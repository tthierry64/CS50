// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string replace(string letters);
int main(int argc, string argv[])

{

        printf("%c\n", ("argv"[1]));
}

//FONCTIONS----------------------------------------------------------------------------------------
string replace(string letters)
{
    for (int i = 0; i < strlen(letters); i++)
    {
        if (tolower(letters[i]) == 'a')
        {
            letters[i] = '6';
        }
        else if (tolower(letters[i]) == 'e')
        {
            letters[i] = '3';
        }
        else if (tolower(letters[i]) == 'i')
        {
            letters[i] = '1';
        }
        else if (tolower(letters[i]) == 'o')
        {
            letters[i] = '0';
        }
    }
    return letters;
}