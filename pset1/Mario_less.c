#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int Height;

    //prompts the user for the Height and check wether it's between 1 & 8 or not
    do
    {
        Height = get_int("Height: ");
    }
    while (Height < 1 || Height > 8);

    //drawing algorithm
    for (int i = 0; i < Height; i++)
    {
        for (int j = 0; j < Height; j++)
        {
            //for every line draw a space if j and i is less than the total height - 1 otherwise draw #
            if (j + i < Height - 1)
            {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}
