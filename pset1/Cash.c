#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float dollars;
    //gets the amount of dollars we need to change to make our operations
    do
    {
        dollars = get_float("How much change is owed? ");
    }
    while (dollars < 0);
    int cents;
    //changes dollars to cents that we can use in the next steps
    cents = round(dollars * 100);
    printf("cents: %i\n", cents);
    int quarters = 0, dimes = 0, nickels = 0, pennies = 0;
    int coins = 0;
    //below is the logic of counting coins..
    //This is for counting quarters
    if (cents >= 25)
    {
        for (; cents >= 25; cents -= 25)
        {
            coins++;
        }
    }
    //This is for counting dimes
    if (cents >= 10)
    {
        for (; cents >= 10; cents -= 10)
        {
            coins++;
        }
    }
    //This is for counting nickels
    if (cents >= 5)
    {
        for (; cents >= 5; cents -= 5)
        {
            coins++;
        }
    }
    //This is for counting pennies
    if (cents >= 1)
    {
        for (; cents >= 1; cents--)
        {
            coins++;
        }
    }
    printf("coins: %i\n", coins);
}
