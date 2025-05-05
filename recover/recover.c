#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Define the size of a memory block
#define BLOCK_SIZE 512

// Define a new data type BYTE
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Allocate 512 bytes of memory for storage
    BYTE *storage = malloc(BLOCK_SIZE * sizeof(BYTE));

    // Check if memory allocation failed
    if (storage == NULL)
    {
        return 1;
    }

    // Initialize variables
    int increment = 0;
    FILE *card = NULL;
    FILE *new_img = NULL;

    // Allocate memory for filename
    char *filename = malloc(sizeof(char) * 10);

    // Check if memory allocation for filename failed
    if (filename == NULL)
    {
        return 1;
    }

    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        puts("Correct usage: ./recover your_file_name.extension");
        return 1;
    }

    // Open the memory card file
    card = fopen(argv[1], "r");

    // Check if the file opened correctly
    if (card == NULL)
    {
        puts("Could not open file.\n");
        return 1;
    }

    // Read the file in 512-byte blocks until EOF
    while (fread(storage, sizeof(BYTE), BLOCK_SIZE, card) == 512)
    {
        // Check if the block contains the start of a JPEG
        if (storage[0] == 0xff && storage[1] == 0xd8 && storage[2] == 0xff && (storage[3] & 0xf0) == 0xe0)
        {
            // If it's the first JPEG found
            if (increment == 0)
            {
                // Create a new file and write the block to it
                sprintf(filename, "%03i.jpg", increment);
                new_img = fopen(filename, "w");
                fwrite(storage, sizeof(BYTE), BLOCK_SIZE, new_img);
                increment++;
            }
            else
            {
                // Close the previous file, create a new file, and write the block to it
                fclose(new_img);
                sprintf(filename, "%03i.jpg", increment);
                new_img = fopen(filename, "w");
                fwrite(storage, BLOCK_SIZE, 1, new_img);
                increment++;
            }
        }
        else
        {
            // If a JPEG has already been found, continue writing the current block
            if (increment > 0)
            {
                fwrite(storage, sizeof(BYTE), BLOCK_SIZE, new_img);
            }
        }
    }

    // Free allocated memory and close files
    free(storage);
    free(filename);
    fclose(card);
    fclose(new_img);

    return 0;
}
