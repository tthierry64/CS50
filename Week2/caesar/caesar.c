//https://cs50.harvard.edu/x/2023/psets/2/caesar/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

string get_plaintext(void);
bool only_digits(string text);
char rotator(int k, char pi);


int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1])) // to check the argument and argv. Attention to the [!] because isdigit return false if the char is digit
    {
        printf("Usage: ./caesar key\n");
        return 1;  // do not forget return true or the program canot stop in case of handles lack of argv[1]
    }

    string plaintext = get_string("plaintext:  ");

    string ciphertext = plaintext;
    int k = atoi(argv[1]);

    for (int i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = rotator(k, ciphertext[i]);
    }
    printf("ciphertext: %s\n", ciphertext);

}

//FONCTIONS----------------------------------------------------------------------
char rotator(int k, char pi)
{
    char ci;
    if (isupper(pi) && isalpha(pi))
    {
        ci = ((pi - 65) + k) % 26 + 65;
    }
    else if (islower(pi) && isalpha(pi))
    {
        ci = ((pi - 97) + k) % 26 + 97;
    }
    else
    {
        ci = pi;
    }
    return ci;
}
//----------
bool only_digits(string text)
{
    for (int i = 0; i < strlen(text); i++)
    {
        if (!isdigit(text[i]))  // careful isdigit return false if the char is digit
        {
            return false;
        }
    }
    return true;
}
