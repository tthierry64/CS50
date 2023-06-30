//https://cs50.harvard.edu/x/2023/psets/2/substitution/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string get_plaintext(void);
bool only_26alpha(string text);
string substitution(string key, string text);


int main(int argc, string argv[])


{
    string key = get_string("key:  ");
    string text = get_string("plaintext:  ");


    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        char numtext = text[i];
        if (islower(numtext) && isalpha(numtext))
        {
            printf("%c", tolower(key[numtext - 97]));
        }
        else if (isupper(numtext) && isalpha(numtext))
        {
            printf("%c", (key[numtext - 65]));
        }
        else
        {
            printf("%c", numtext);
        }
    }
    printf("\n");
}