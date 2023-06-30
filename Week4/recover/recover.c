#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
#define block_size 512

int main(int argc, char *argv[])
{
    BYTE buffer[block_size];
    int counter = 0;
    char *jpeg_name = malloc(8 * sizeof(char));// 8 chars to name a jpeg file : "xxx.jpeg\0" with nul char
    FILE *jpeg_file = NULL;

    //condition of command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //Open memory card
    FILE *read_f = fopen(argv[1], "r");
    //Check if the destination used to read the doc is valid
    if (read_f == NULL)
    {
        printf("impossible to open the file, adress probably null");
    }
    //In the new "buffer" file : "read_f" read each block of 512 bytes and check if there 4 first bytes are tipical to JPEGs firts ones.
    //To that we create a new file "buffer" to analyze each bytes of "read_f".
    //// If it is so, we will copy the blocks in an other new file that we need to create and open first named : "file_name". Each block will be temporally
    //// stored in "buffer" the witten in a new file with an incremented name with the fonction : "sprintf" that we define first
    while (fread(buffer, sizeof(char), block_size, read_f))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (jpeg_file != NULL)
            {
                fclose(jpeg_file);  // we needeed to declare a FILE jpeg_file above the code on line 13, thus it is "active" for all the code
                //but for now we need it to be closed no matter what is its value or adress. and we cannot write on the NULL
            }
            sprintf(jpeg_name, "%03i.jpg", counter);
            jpeg_file = fopen(jpeg_name, "w");
            counter++;
        }
        //Check if the destination used to read the new file is valid
        if (jpeg_file != NULL)
        {
            fwrite(buffer, sizeof(char), block_size, jpeg_file);
        }
    }
    fclose(read_f);
    fclose(jpeg_file);
    free(jpeg_name);

}