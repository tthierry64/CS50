#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++) // the image is made pixel by pixel like a 2D array. So We move, pixel by pixel
        //from the width and weight and we compare de triple caractéristic of each pixel and the color black : 0/0/0
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtBlue == 0 && image[i][j].rgbtGreen == 0 && image[i][j].rgbtRed == 0)
            {
                image[i][j].rgbtBlue = 120;
                image[i][j].rgbtGreen = 56;
                image[i][j].rgbtRed = 87;
            }
        }
    }

}
