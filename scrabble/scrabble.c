#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h> // these are the libraries

int compute_score(string word);  // putting this here so the main can be on top and will function well although compute is initialized later

int main(void)
{
    // asking for players to enter their words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Calculating the scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // finding the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(string word)
{
    // Points array
    int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;

    // the score for each letter in the word will be counted here
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Convert the letter to uppercase
        char letter = toupper(word[i]);

        // checking if the character is a letter
        if (isalpha(letter))
        {
            // Subtract 'A' to get the index
            score += points[letter - 'A'];
        }
    }

    return score;
}
