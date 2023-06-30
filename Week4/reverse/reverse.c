#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"




//EXERCICE CORRIGE NON SOUMIS CAR TROP COMPLQUE
//
//
//
//
//
//
//
//
//
//
//
//

WAVHEADER temp_header;

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("impossible to open the file, adress probably null");
        return 1;
    }

    // Read header
    // TODO #3
    // we need to create a new file based on the WAVEHEADER structure wichi will be a copy of the original file.
    //Thus, we can analyze it and it will be easier to get into the file format.

    //we need to check only the header part. So this new file will only contains the copy of the header of the original file.
    fread(&temp_header, sizeof(WAVHEADER) , 1, input_file);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(temp_header) == 0)
    {
        printf("The aufio file is not a WAV file\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL)
    {
        printf("impossible to open the output file, adress probably null");
        return 1;
    }

  // Write header to file
  // TODO #6
    fwrite(&temp_header, sizeof(WAVHEADER), 1, output_file);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(temp_header);

    // Write reversed audio to file
    // TODO #8
    if(fseek(input_file, block_size, SEEK_END))
    {
        return 1;
    }
    BYTE buffer[block_size];
    while((ftell(input_file) - block_size) > sizeof(temp_header))
    {
        if(fseek(input_file, -2 * block_size, SEEK_CUR)) //minus 2 because we check backward
        {
            return 1;
        }

        fread(buffer, block_size, 1, input_file);
        fwrite(buffer, block_size, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    //We want to check the presence of the WAVE word attesting the wav format of the file.
    //Comparing string does not work. So we need to compare char by char the 4 first char of header.format
   if(temp_header.format[0] == 'W' && temp_header.format[1] == 'A' && temp_header.format[2] == 'V' && temp_header.format[3] == 'E')
   {
    return 1;
   }
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int size = temp_header.numChannels * temp_header.bitsPerSample / 8; // Divided per 8 to get bytes and not bits
    return size;
}