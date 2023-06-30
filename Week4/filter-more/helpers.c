#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // the function round goes with float numbers
            float B = image[i][j].rgbtBlue;
            float G = image[i][j].rgbtGreen;
            float R = image[i][j].rgbtRed;
            int moy =  round((B + G  + R) / 3);
            image[i][j].rgbtBlue = moy;
            image[i][j].rgbtGreen = moy;
            image[i][j].rgbtRed = moy;
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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // we create a copy of the image in order to not erase the previous valor of the pixel conciderated
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }
    //creation of the two kernels matrix
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //Selection of one pixel i,j and multiply the pixels directly around by Gx and Gy
    // the folowing float are the result of the multiplication of matrix for each channel : Red, Green and Blue
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0;
            int GxGreen = 0;
            int GxBlue = 0;
            int GyRed = 0;
            int GyGreen = 0;
            int GyBlue = 0;
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    //definition of the pixels ain edges in function of x and y
                    if ((i - 1 + x) >= 0 && (i - 1 + x) < height && (j - 1 + y) >= 0 && (j - 1 + y) < width)
                    {
                        //definition of the pixels around in function of x and y
                        int a = image[i - 1 + x][j - 1 + y].rgbtRed;
                        int b = image[i - 1 + x][j - 1 + y].rgbtGreen;
                        int c = image[i - 1 + x][j - 1 + y].rgbtBlue;

                        //calculation of total Gx and Gy of eah channel
                        GxRed = GxRed + a * Gx[x][y];
                        GxGreen = GxGreen + b * Gx[x][y];
                        GxBlue = GxBlue + c * Gx[x][y];

                        GyRed = GyRed + a * Gy[x][y];
                        GyGreen = GyGreen + b * Gy[x][y];
                        GyBlue = GyBlue + c * Gy[x][y];
                    }
                }
                //Calculate square roof Gx^² and square roof Gy^² for each channel and verifying that it does not overwrite 255
                int TotRed = round(sqrt((GxRed * GxRed)  + (GyRed * GyRed)));
                if (TotRed > 255)
                {
                    TotRed = 255;
                }
                int TotGreen = round(sqrt((GxGreen * GxGreen)  + (GyGreen * GyGreen)));
                if (TotGreen > 255)
                {
                    TotGreen = 255;
                }
                int TotBlue = round(sqrt((GxBlue * GxBlue)  + (GyBlue * GyBlue)));
                if (TotBlue > 255)
                {
                    TotBlue = 255;
                }
                temp[i][j].rgbtRed = TotRed;
                temp[i][j].rgbtGreen = TotGreen;
                temp[i][j].rgbtBlue = TotBlue;
            }
        }
    }

    // Create the new image copying temp pixels in image pixels in a new loop in order to not influence the previous lines

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }
    return;
}
