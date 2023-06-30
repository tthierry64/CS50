#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float B = image[i][j].rgbtBlue;
            float G = image[i][j].rgbtGreen;
            float R = image[i][j].rgbtRed;
            int moy =  round((B + G  + R) / 3); // the function round goes with float numbers
            image[i][j].rgbtBlue = moy;
            image[i][j].rgbtGreen = moy;
            image[i][j].rgbtRed = moy;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //we create a copy of originals pixels to work with
            float originalRed = image[i][j].rgbtRed;
            float originalGreen = image[i][j].rgbtGreen;
            float originalBlue = image[i][j].rgbtBlue;

            // the function round goes with float numbers
            int sepiaRed = round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen = round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue = round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[i][j].rgbtRed = sepiaRed;
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            image[i][j].rgbtGreen = sepiaGreen;
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            // We make a symetry with the central axe
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //we initiate all the new variables
    RGBTRIPLE temp[height][width];
    float totalRed = 0;
    float totalGreen = 0;
    float totalBlue = 0;
    int counter = 0;
    float blurRed = 0;
    float blurGreen = 0;
    float blurBlue = 0;

    // we create a copy of the image in order to not erase the previous valor of the pixel conciderated
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    // we considere one pixel and calculate the average of pixels around
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            totalRed = 0;
            totalGreen = 0;
            totalBlue = 0;
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        totalRed += temp[x][y].rgbtRed;
                        totalGreen += temp[x][y].rgbtGreen;
                        totalBlue += temp[x][y].rgbtBlue;
                        counter++; // to get the division
                    }
                }
            }
            //finally we can copy the new valors of RGB in the origianl pixels
            blurRed = round(totalRed / counter);
            blurGreen = round(totalGreen / counter);
            blurBlue = round(totalBlue / counter);
            image[i][j].rgbtRed = blurRed;
            image[i][j].rgbtGreen = blurGreen;
            image[i][j].rgbtBlue = blurBlue;
        }
    }
    return;
}
