#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //prompts the user for a number and accept numbers only between 1 and 8 only
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);

    //drawing algorithm
    for (int i = 0; i < height; i++)
    {
        //This for loop will draw the first pyramid
        for (int j = 0; j < height; j++)
        {
            if (i + j < height - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  ");

        //This for loop will draw the other pyramid
        for (int k = -1; k < i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}
