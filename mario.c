#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    // Prompt user for a height between 1 and 8
    do
    {
        height = get_int("Height: ");
    } while (height < 1 || height > 8);

    // Loop to print each row of the pyramid
    for (int i = 0; i < height; i++)
    {
        // Print leading spaces
        for (int j = height - i - 1; j > 0; j--)
        {
            printf(" ");
        }

        // Print left pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Print gap between pyramids
        printf("  ");

        // Print right pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        // Move to the next line after each row
        printf("\n");
    }

}
