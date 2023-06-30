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
    if (argc != 2) //chek if only one more argument  is used
    {
        printf("Usage: ./substitution key\n");
        return 1;  // do not forget return true or the program canot stop in case of handles lack of argv[1]
    }
    if (!only_26alpha(argv[1]))
    {
        printf("Key must contain 26 unique alphabetical characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext:  ");
    substitution(argv[1], plaintext);
}

//----------
bool only_26alpha(string text)
{
    if (strlen(text) != 26)  // to prompt only 26 characters
    {
        return false;
    }
    for (int i = 0; i < strlen(text); i++)// to prompt only alphabet characters
    {
        if (!isalpha(text[i]))  // careful isalpha return false if the char is alphabetical so [!]
        {
            return false;
        }
        for (int j = i + 1; j < strlen(text); j++) // check the unicity : fixing the charactere i and compare it to the j others.
            if (toupper(text[i]) == toupper(text[j]))
            {
                return false;
            }
    }
    return true;

}
//----------
string substitution(string key, string text)
{
    for (int i = 0; i < strlen(key); i++)
    {
        if (islower(key[i]))
        {
            key[i] = toupper(key[i]);
        }
    }
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
    return 0;
}