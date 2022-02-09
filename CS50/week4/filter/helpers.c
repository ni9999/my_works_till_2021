#include "helpers.h"
#include <math.h>
#include <stdio.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            BYTE sum=(image[i][j].rgbtRed+image[i][j].rgbtGreen+image[i][j].rgbtBlue)/3;
            image[i][j].rgbtRed=image[i][j].rgbtGreen=image[i][j].rgbtBlue=sum;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
     for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int Red = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int Green =round( .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int Blue= round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if(Red>255)
                image[i][j].rgbtRed=255;
            else image[i][j].rgbtRed=Red;
            if(Green>255)
                 image[i][j].rgbtGreen=255;
            else  image[i][j].rgbtGreen=Green;
            if(Blue>255)
                image[i][j].rgbtBlue=255;
            else image[i][j].rgbtBlue=Blue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width/2;j++)
        {
            int k=width-1-j;
            BYTE tmp;
            tmp=image[i][k].rgbtRed;
            image[i][k].rgbtRed=image[i][j].rgbtRed;
            image[i][j].rgbtRed=tmp;

            tmp=image[i][k].rgbtGreen;
            image[i][k].rgbtGreen=image[i][j].rgbtGreen;
            image[i][j].rgbtGreen=tmp;

            tmp=image[i][k].rgbtBlue;
            image[i][k].rgbtBlue=image[i][j].rgbtBlue;
            image[i][j].rgbtBlue=tmp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE imagecp[height][width];
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            imagecp[i][j]=image[i][j];
        }
    }

    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            int k,l,box=0;
			BYTE sumR=0,sumG=0,sumB=0;
			for ( k = -1; k < 2; k++)
			{
				for ( l = -1; l < 2; l++)
				{
					if (i+k>-1  &&  j+l>-1  &&  i+k<height  &&  j+l<width)
					{
						sumR=sumR+imagecp[i+k][j+l].rgbtRed;
						sumG=sumG+imagecp[i+k][j+l].rgbtGreen;
						sumB=sumB+imagecp[i+k][j+l].rgbtBlue;
						box++;
					}

				}
			}
			image[i][j].rgbtRed=round(sumR/box);
			image[i][j].rgbtGreen=round(sumG/box);
			image[i][j].rgbtBlue=round(sumB/box);
        }
    }
    return;
}
