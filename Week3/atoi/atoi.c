#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO

    int str = strlen (input);
    int integer = 0;
    int buffer = 0;
    //Remember you need a base case when creating a recursive function.
    if (strlen(input) == 1)
    {
        return input[0] - 48;
    }
    //Start by getting the index of the last char in the string (the char before the \0).
    char last_digit = input[str -1];
    //Convert this char into its numeric value. Can you subtract some char to do this?
    int converted_last_digit = last_digit - 48;
    //Remove the last char from the string by moving the null terminator one position to the left.
    input[str -1] = '\0';
    //Return this value plus 10 times the integer value of the new shortened string.
    return converted_last_digit + 10 * convert(input);
}

// -> on ajoute le dernier digit à 10 x les précédents
/*
ex:
32456  = 6 + (5 + (4 + (2 + (3 x10) x10 ) x10 ) x10 )x10   avec 3 = base case

*/