#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            float red = pixel.rgbtRed;
            float green =  pixel.rgbtGreen;
            float blue = pixel.rgbtBlue;

            float grey = (red + green + blue) / 3;

            int roundgrey = round(grey);

            pixel.rgbtRed = roundgrey;
            pixel.rgbtGreen = roundgrey;
            pixel.rgbtBlue = roundgrey;

            image[i][j] = pixel;
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
            RGBTRIPLE pixel = image[i][j];
            float originalRed = pixel.rgbtRed;
            float originalGreen = pixel.rgbtGreen;
            float originalBlue = pixel.rgbtBlue;

            // Calculate sepia colors
            int sepiaRed = round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen = round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue = round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);


            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            pixel.rgbtRed = (uint8_t)sepiaRed;
            pixel.rgbtGreen = (uint8_t)sepiaGreen;
            pixel.rgbtBlue = (uint8_t)sepiaBlue;

            image[i][j] = pixel;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width/2 ; j++)
        {


            int b = width - j -1;

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][b];
            image[i][b] = temp;
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE blurred[height][width];

    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            int loops = 0;

            for (int ai = -1; ai <= 1; ai++)
            {
                for (int aj = -1; aj <= 1; aj++)
                {
                    if (i + ai >= 0 && i + ai < height && j + aj >= 0 && j + aj < width)
                    {
                        sumRed += image[i + ai][j + aj].rgbtRed;
                        sumGreen += image[i + ai][j + aj].rgbtGreen;
                        sumBlue += image[i + ai][j + aj].rgbtBlue;
                        loops++;
                    }
                }
            }

            int avgRed = round((float)sumRed / loops);
            int avgGreen = round((float)sumGreen / loops);
            int avgBlue = round((float)sumBlue / loops);

            blurred[i][j].rgbtRed = avgRed;
            blurred[i][j].rgbtGreen = avgGreen;
            blurred[i][j].rgbtBlue = avgBlue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = blurred[i][j];
        }
    }
}