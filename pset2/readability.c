#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

float get_grade(int letters, int words, int sentences);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    //this will check whether it is smaller than grade 1
    if ((int)round(get_grade(count_letters(text), count_words(text), count_sentences(text))) < 1)
    {
        printf("Before Grade 1");
    }
    //this will check whether it's bigger than grade 16
    else if ((int)round(get_grade(count_letters(text), count_words(text), count_sentences(text))) > 16)
    {
        printf("Grade 16+");
    }
    //this will print the final result if it's between 1 and 16
    else
    {
        printf("Grade %i", (int)round(get_grade(count_letters(text), count_words(text), count_sentences(text))));
    }

    printf("\n");
}

//This function will calculate the grade using the formula
float get_grade(int letters, int words, int sentences)
{
    float avgl, avgs;
    avgl = letters / (float)words * 100;
    avgs = sentences / (float)words * 100;
    return 0.0588 * avgl - 0.296 * avgs - 15.8;
}

//This function is for counting the letters of the text
int count_letters(string text)
{
    int letters = 0;

    //This will check for every char to see whether it's an alpha or not and then count alpha letters
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    return letters;
}

//This function will count words of the text
int count_words(string text)
{
    int words = 0;

    //This will check for every char to see whether it's a spacebar to count it as a word
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    //the added 1 is for the last word of the sentence
    return words + 1;
}

//This function will count the number of senteces in the text
int count_sentences(string text)
{
    int sentences = 0;

    //This will check for every char to see whether it's an end of a sentence or not to count it
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}
