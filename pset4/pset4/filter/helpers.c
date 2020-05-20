#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float gray;

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            // averages the color intensity and then applies the same value to all the colors to get gray
            gray = round((image[j][i].rgbtBlue + image[j][i].rgbtGreen + image[j][i].rgbtRed) / 3.0);

            image[j][i].rgbtBlue = gray;
            image[j][i].rgbtGreen = gray;
            image[j][i].rgbtRed = gray;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
     RGBTRIPLE temp;
     int j;
     int i;

    for (int r = 0; r < height; r++)
    {
        j = width - 1;
        i = 0;
        while (i < j)
        {
            temp.rgbtBlue = image[r][i].rgbtBlue;
            temp.rgbtGreen = image[r][i].rgbtGreen;
            temp.rgbtRed = image[r][i].rgbtRed;
            image[r][i].rgbtBlue = image[r][j].rgbtBlue;
            image[r][i].rgbtGreen = image[r][j].rgbtGreen;
            image[r][i].rgbtRed = image[r][j].rgbtRed;
            image[r][j].rgbtBlue = temp.rgbtBlue;
            image[r][j].rgbtGreen = temp.rgbtGreen;
            image[r][j].rgbtRed = temp.rgbtRed;
            i++;
            j--;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    float nred, ngreen, nblue;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];
    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            temp[r][p] = image[r][p];

        }
    }

    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            if (r == 0 && p == 0) //Caso 1
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r + 1][p + 1].rgbtRed + temp[r + 1][p].rgbtRed) / 4.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r + 1][p + 1].rgbtGreen + temp[r + 1][p].rgbtGreen) / 4.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r + 1][p + 1].rgbtBlue + temp[r + 1][p].rgbtBlue) / 4.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
            else if (r == 0 && p == width - 1) //Caso 2
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p - 1].rgbtRed + temp[r + 1][p - 1].rgbtRed + temp[r + 1][p].rgbtRed) / 4.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r + 1][p - 1].rgbtGreen + temp[r + 1][p].rgbtGreen) / 4.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r + 1][p - 1].rgbtBlue + temp[r + 1][p].rgbtBlue) / 4.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;

            }
            else if (r == height - 1 && p == 0) //Caso 3
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r - 1][p + 1].rgbtRed + temp[r - 1][p].rgbtRed) / 4.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r - 1][p + 1].rgbtGreen + temp[r - 1][p].rgbtGreen) / 4.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r - 1][p + 1].rgbtBlue + temp[r - 1][p].rgbtBlue) / 4.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
            else if (r == height - 1 && p == width - 1) //Caso 4
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p - 1].rgbtRed + temp[r - 1][p - 1].rgbtRed + temp[r - 1][p].rgbtRed) / 4.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r - 1][p - 1].rgbtGreen + temp[r - 1][p].rgbtGreen) / 4.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r - 1][p - 1].rgbtBlue + temp[r - 1][p].rgbtBlue) / 4.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
            else if (r == 0) //Caso 5
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r][p - 1].rgbtRed + temp[r + 1][p].rgbtRed + temp[r + 1][p + 1].rgbtRed + temp[r + 1][p - 1].rgbtRed) / 6.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r + 1][p].rgbtBlue + temp[r + 1][p + 1].rgbtBlue + temp[r + 1][p - 1].rgbtBlue) / 6.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r + 1][p].rgbtGreen + temp[r + 1][p + 1].rgbtGreen + temp[r + 1][p - 1].rgbtGreen) / 6.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;

            }
            else if (r == height - 1) //Caso 6
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r][p - 1].rgbtRed + temp[r - 1][p].rgbtRed + temp[r - 1][p + 1].rgbtRed + temp[r - 1][p - 1].rgbtRed) / 6.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r - 1][p].rgbtBlue + temp[r - 1][p + 1].rgbtBlue + temp[r - 1][p - 1].rgbtBlue) / 6.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r - 1][p].rgbtGreen + temp[r - 1][p + 1].rgbtGreen + temp[r - 1][p - 1].rgbtGreen) / 6.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;

            }
            else if (p == 0) //Caso 7
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r + 1][p].rgbtRed + temp[r - 1][p].rgbtRed + temp[r + 1][p + 1].rgbtRed + temp[r - 1][p + 1].rgbtRed) / 6.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r + 1][p].rgbtBlue + temp[r - 1][p].rgbtBlue + temp[r + 1][p + 1].rgbtBlue + temp[r - 1][p + 1].rgbtBlue) / 6.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r + 1][p].rgbtGreen + temp[r - 1][p].rgbtGreen + temp[r + 1][p + 1].rgbtGreen + temp[r - 1][p + 1].rgbtGreen) / 6.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
            else if (p == width - 1) //Caso 9
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p - 1].rgbtRed + temp[r + 1][p].rgbtRed + temp[r - 1][p].rgbtRed + temp[r + 1][p - 1].rgbtRed + temp[r - 1][p - 1].rgbtRed) / 6.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r + 1][p].rgbtBlue + temp[r - 1][p].rgbtBlue + temp[r + 1][p - 1].rgbtBlue + temp[r - 1][p - 1].rgbtBlue) / 6.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r + 1][p].rgbtGreen + temp[r - 1][p].rgbtGreen + temp[r + 1][p - 1].rgbtGreen + temp[r - 1][p - 1].rgbtGreen) / 6.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
            else
            {
                nred = round((temp[r][p].rgbtRed + temp[r][p + 1].rgbtRed + temp[r][p - 1].rgbtRed + temp[r + 1][p].rgbtRed + temp[r - 1][p].rgbtRed + temp[r + 1][p + 1].rgbtRed + temp[r - 1][p + 1].rgbtRed + temp[r + 1][p - 1].rgbtRed + temp[r - 1][p - 1].rgbtRed) / 9.0);
                nblue = round((temp[r][p].rgbtBlue + temp[r][p + 1].rgbtBlue + temp[r][p - 1].rgbtBlue + temp[r + 1][p].rgbtBlue + temp[r - 1][p].rgbtBlue + temp[r + 1][p + 1].rgbtBlue + temp[r - 1][p + 1].rgbtBlue + temp[r + 1][p - 1].rgbtBlue + temp[r - 1][p - 1].rgbtBlue) / 9.0);
                ngreen = round((temp[r][p].rgbtGreen + temp[r][p + 1].rgbtGreen + temp[r][p - 1].rgbtGreen + temp[r + 1][p].rgbtGreen + temp[r - 1][p].rgbtGreen + temp[r + 1][p + 1].rgbtGreen + temp[r - 1][p + 1].rgbtGreen + temp[r + 1][p - 1].rgbtGreen + temp[r - 1][p - 1].rgbtGreen) / 9.0);
                image[r][p].rgbtRed = nred;
                image[r][p].rgbtBlue = nblue;
                image[r][p].rgbtGreen = ngreen;
            }
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int Gx[3][3] = {{-1,0,1},{- 2,0, 2},{-1,0,1}};
    int Gy[3][3] = {{- 1,- 2,- 1},{0,0, 0},{1,2,1}};
    float rx, gx, bx, ry, gy, by;
    //create a temporary table of colors to not alter the calculations
    RGBTRIPLE temp[height][width];
    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            temp[r][p] = image[r][p];
        }
    }

    for (int r = 0; r < height; r++)
    {
        for (int p = 0; p < width; p++)
        {
            rx = 0;
            ry = 0;
            gx = 0;
            gy = 0;
            bx = 0;
            by = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (r - 1 + i < 0 || r - 1 + i > height - 1 || p - 1 + j < 0 || p - 1 + j > width - 1)
                    {
                        continue;
                    }
                     //Convolucion en x para cada color
                     rx += temp[r - 1 + i][p - 1 + j].rgbtRed*Gx[i][j];
                     gx += temp[r - 1 + i][p - 1 + j].rgbtGreen*Gx[i][j];
                     bx += temp[r - 1 + i][p - 1 + j].rgbtBlue*Gx[i][j];

                     //Convolucion en y para cada color
                     ry += temp[r - 1 + i][p - 1 + j].rgbtRed*Gy[i][j];
                     gy += temp[r - 1 + i][p - 1 + j].rgbtGreen*Gy[i][j];
                     by += temp[r - 1 + i][p - 1 + j].rgbtBlue*Gy[i][j];
                }
            }
            float red = round(sqrt(rx*rx + ry*ry));
            float green = round(sqrt(gx*gx + gy*gy));
            float blue = round(sqrt(bx*bx + by*by));

            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            image[r][p].rgbtRed = red;
            image[r][p].rgbtBlue = blue;
            image[r][p].rgbtGreen = green;
        }
    }
    return;
}
