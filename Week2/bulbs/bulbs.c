//https://cs50.harvard.edu/x/2023/psets/2/bulbs/
// Autre méthode : https://www.youtube.com/watch?v=28Gf6PZTmYM&list=PLo_wesNOyQTMl3zIvoIVANOqGNL4B2Sg-

// Pour rentrer directement dans le Byte d'un caractère

// unsigned char byte = message[i]   //unsigned char is a character datatype where the variable consumes all the 8 bits of the memory and there is no sign bit
//capable de représenter au moins les nombres [0 ; 255]. et
//signed char :  capable de représenter au moins les nombres [−127 ; +127]
//https://www.geeksforgeeks.org/unsigned-char-in-c-with-examples/


//https://emmanuel-delahaye.developpez.com/tutoriels/c/operateurs-bit-bit-c/
//I-F. SHR (Décalage à droite)
////L'opérateur binaire SHR a pour opérande de gauche la valeur initiale et pour opérande de droite le nombre de bits à décaler à droite. Les bits de poids faibles sont perdus et les bits de poids forts entrés (à gauche) sont à 0. Ce n'est pas une rotation.
//L'opérateur C est >>. Il agit sur chaque bit de la valeur :

//unsigned a = 0xF0F0;
//unsigned b = 2;
//unsigned c = a >> b; /* c == 0011 1100 0011 1100 soit 0x3C3C */

//I-G. SHL (Décalage à gauche)
//L'opérateur binaire SHL a pour opérande de gauche la valeur initiale et pour opérande de droite le nombre de bits à décaler à gauche. Les bits de poids forts sont perdus et les bits de poids faibles entrés (à droite) sont à 0. Ce n'est pas une rotation.
//L'opérateur C est <<. Il agit sur chaque bit de la valeur :

//unsigned a = 0xF0F0;
//unsigned b = 2;
//unsigned c = a << b; /* c == 1100 0011 1100 0000 soit 0xC3C0 */



// for (j = BITS_IN-BYTE -1; j >= 0; j++)    // 1er bit est à 8-1=7eme place et le dernier à la 0eme place
// int bit = (byte >> j) & 1;
// print_bulb(bit);

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    string message = get_string("Message: ");
    int bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8;
    for (int i = 0; i < strlen(message); i++)
    {
        char car = message[i]; // consider one character of the message from left to right
        int numcar = car; // consider the integer coresponding to the character from ascii
        for (int j = 0; j < BITS_IN_BYTE ; j++) //go throw th byte (composing of 8 bits) of the integer.
            //Doing the division by 2 and saving the rest. For each 8 bits
            //the switch is used to store de valeu of the 8 digits in differents variables
        {
            switch (j)
            {
                case 0 :
                    bit1 = numcar % 2;
                    break;

                case 1 :
                    bit2 = numcar % 2;
                    break;

                case 2 :
                    bit3 = numcar % 2;
                    break;

                case 3 :
                    bit4 = numcar % 2;
                    break;

                case 4 :
                    bit5 = numcar % 2;
                    break;

                case 5 :
                    bit6 = numcar % 2;
                    break;

                case 6 :
                    bit7 = numcar % 2;
                    break;

                case 7 :
                    bit8 = numcar % 2;
                    break;
            }
            numcar /= 2; //passing to the next bit, dividing the previous one by 2
        }
        // Print bits/bulbs in the right order
        print_bulb(bit8);
        print_bulb(bit7);
        print_bulb(bit6);
        print_bulb(bit5);
        print_bulb(bit4);
        print_bulb(bit3);
        print_bulb(bit2);
        print_bulb(bit1);
        printf("\n");
    }
}

// FONCTIONS --------------------------------------

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
