#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check if the user provided exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Validate that the command-line argument is a non-negative integer
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert the command-line argument to an integer (the key)
    int key = atoi(argv[1]);

    // Prompt the user for the plaintext
    string plaintext = get_string("plaintext:  ");

    // Encrypt the plaintext
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        // Check if the character is an uppercase letter
        if (isupper(c))
        {
            printf("%c", 'A' + (c - 'A' + key) % 26);
        }
        // Check if the character is a lowercase letter
        else if (islower(c))
        {
            printf("%c", 'a' + (c - 'a' + key) % 26);
        }
        // If it's not a letter, print it unchanged
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    // Exit the program successfully
    return 0;
}
