//https://cs50.harvard.edu/x/2023/problems/2/no-vowels/

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
    if (argc != 2)
    {
        printf("ERROORRRRRRRRR : wrong wommand-line arguments\n");
        return 1; // pour stopper le programme ici si c'est le cas est vrai. Ca évite de faire le lire la suite du programme pour
        //rien
    }
      printf("%s\n", replace(argv[1]));
}

//FONCTIONS----------------------------------------------------------------------------------------
string replace(string letters)
{
   for (int i = 0; i < strlen(letters); i++)
   {
//         On peut sinon créer une variable char c = tolower(letters[i]); et dans le switch on attribue les nouvelles lettres à c
            switch (letters[i])
       {
           case 'a':
           letters[i] = '6' ;
           break;

           case 'e':
           letters[i] = '3' ;
           break;

           case 'i':
           letters[i] = '1' ;
           break;

           case 'o':
           letters[i] = '0' ;
           break;

           default :
           letters[i] = letters[i] ;
           break;
       }


//  string replace(string letters)
//  {
//      for (int i = 0; i < strlen(letters); i++)
//      {
//        if (tolower(letters[i]) == 'a')
//        {
//            letters[i] = '6';
//        }
//        else if (tolower(letters[i]) == 'e')
//        {
//            letters[i] = '3';
//        }
//        else if (tolower(letters[i]) == 'i')
//        {
//            letters[i] = '1';
//        }
//        else if (tolower(letters[i]) == 'o')
//        {
//            letters[i] = '0';
//      }
    }
    return letters;
}