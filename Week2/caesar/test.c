//https://cs50.harvard.edu/x/2023/psets/2/caesar/

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string text);
char rotator(char p, int k,);


int main(int argc, string argv[])
{
  int k, length;
  if (argc != 2 || !only_digits(argv[1]))
    {
      printf("Usage: ./caesar key\n");
      return 1;
    }
    k = atoi(argv[1]);
    plaintext = get_string("plaintext:  ");
    length = strlen(plaintext)
    char ciphertext [leng];

    if (argc != 2 || !only_digits(argv[1]))
    {
      printf("Usage: ./caesar key\n");
    }
    else
    {
      printf("ciphertext: zdazda\n");
    }
 }

bool only_digits (string text)
{
  for (int i = 0; i < strlen(text); i++)
  {
    if (isdigit(text[i]))
    {
      return true;
    }
  }
     return false;
}