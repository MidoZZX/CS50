#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //This will check whether the user has typed a key or not and return 1 if he/she didn't
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }
    //if the user typed in a valid key then this code will execute
    else
    {
        //This will check for any letters in the key and print usage information
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("Usage: %s key\n", argv[0]);
                return 1;
            }
        }

        //the atoi function is for changing the key from string to int
        int key = atoi(argv[1]);

        printf("%i\n", key);

        string plaintext = get_string("plaintext: ");

        printf("ciphertext: ");

        for (int i = 0; i < strlen(plaintext); i++)
        {
            //this will print anything that is not an alpha
            if (isalpha(plaintext[i]) == false)
            {
                printf("%c", plaintext[i]);
            }
            else
            {
                int ascii = plaintext[i];
                int shifted = ascii + key;

                if (ascii > 64 && ascii < 91)
                {
                    //this will do the math for the lowercase letters
                    if (shifted > 90)
                    {
                        printf("%c", (shifted - 64) % 26 + 64);
                    }
                    else
                    {
                        printf("%c", shifted);
                    }
                }
                else
                {
                    //this will check for capital letters and do the math
                    if (shifted > 122)
                    {
                        printf("%c", (shifted - 97) % 26 + 97);
                    }
                    else
                    {
                        printf("%c", shifted);
                    }
                }
            }
        }

        printf("\n");
    }
}
