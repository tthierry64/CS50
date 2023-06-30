#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{

// prompt the text from the user

    string text = get_string("Text: ");

    int total_letters = count_letters(text);
    int total_words = count_words(text);
    int total_sentences = count_sentences(text);


    double L = total_letters / (float)total_words * 100;
    double S = total_sentences / (float)total_words * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}

// Functions---------------------

// Calculate de number of letters in the text knowing a string is an array
int count_letters(string text)
{
    int total_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]) != 0)
        {
            total_letters ++;
        }
    }
    // printf("%i letters\n", total_letters);
    return total_letters;
}

// Calculate de number of words in the text ie: count the number of space +1
int count_words(string text)
{
    int total_words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            total_words ++;
        }
    }
    // printf("%i words\n", total_words);
    return total_words;
}

// calculate the number of sentences in the text ie: count the number of . ! or ?
int count_sentences(string text)
{
    int total_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            total_sentences ++;
        }
    }
    // printf("%i sentences\n", total_sentences);
    return total_sentences;
}