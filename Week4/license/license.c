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

    // open the file for reading
    FILE *infile = fopen(argv[1], "r");

    // creating an index variable to access particular plates of array
    int idx = 0;

    while (fread(buffer, sizeof(char), 7, infile) == 7)
    {
        // Replace '\n' with '\0'
        buffer[6] = '\0';

        // Save plate number in array
        //We need to "malloc" because initially, plates is made by "char" = 1 byte. Now we need 7 bytes. We need to change his size
        plates[idx] = malloc(7 * sizeof(char));
        // Now we can use the copy function
        strcpy(plates[idx], buffer);
        idx++;
    }
    for (int i = 0; i < 8; i++)
    {
        printf("%s\n", plates[i]);
    }
    for (int i = 0; i < 8; i++)
    {
        free(plates[i]);
    }
    fclose(infile);
}