#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./read infile\n");
        return 1;
    }

    // Create buffer to read into
    char buffer[7];

    // Create array to store plate numbers
    char *plates[8];
    for (int i = 0; i < 8; i++) // you reserve for each i array memory with size of 7 bytes (each word plate is 6 digits + /0 = 7 digits)
    {
        plates[i] = malloc(7);
    }

    FILE *infile = fopen(argv[1], "r");

    int idx = 0;

    while (fread(buffer, 1, 7, infile) == 7) //  the fread function always gives some output. In this case it is sizeof(7).
    //Therefore, it will run until it reaches the end of the arrays from the txt file and gives a different numeric value and stops.
    {
        buffer[6] = '\0'; // each word from the buffer will be 6 characters long and must end with '\0' [ '0' is the seventh character in the string]
        for(int i = 0; i < 6; i++) //this loop will copy the characters from the buffer one by one into plates array
        {
            plates[idx][i] = buffer[i]; //buffer [i] //we need to copy each letter in turn for a given plate number
        }
        //insted of loop above You can use just - > strcpy(plates[idx], buffer);
        idx++; //  we need to increment indx by one to start overwriting the next array number from the buffer.
    }

    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);

    }
    fclose(infile);
}
