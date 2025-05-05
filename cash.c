#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int cents;

    // Prompt the user for a positive integer (change owed)
    do
    {
        cents = get_int("Change owed: ");
    } while (cents < 0);

    // Initialize the coin counter
    int coins = 0;

    // Calculate the minimum number of coins
    coins += cents / 25;  // Quarters (25 cents)
    cents %= 25;

    coins += cents / 10;  // Dimes (10 cents)
    cents %= 10;

    coins += cents / 5;   // Nickels (5 cents)
    cents %= 5;

    coins += cents;       // Pennies (1 cent)

    // Output the total number of coins
    printf("%d\n", coins);

    return 0;
}
