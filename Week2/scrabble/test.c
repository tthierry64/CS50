#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
//              a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q,  r, s, t, u, v, w, x, y, z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");

    // Score both words
    int score1 = compute_score(word1);

    // TODO: Print the winner
    printf ("%i \n", score1);
}

int compute_score(string word)

{

    // TODO: Compute and return score for string

    int score = 0;
   for (int i = 0, len = strlen(word); i < len ; i++)
{
    if (isupper(word[i]))
    {
        score = POINTS[word[i] - 65];
    }
    else if (islower(word[i]))
        {
        score = POINTS[word[i] - 97];
        }
    }
return score;
}