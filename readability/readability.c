#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    int letters = 0;
    int words = 0;
    int fullsentences = 0;

    string sentence = get_string("Text: ");

    for (int i = 0; sentence[i] != 0; i++)
    {
        if (isalpha(sentence[i]))
        {
            letters++;
        }
    }

    for (int j = 0; sentence[j] != 0; j++)
    {
        if (sentence[j] == ' ')
        {
            words++;
        }
    }

    for (int k = 0; sentence[k] != 0; k++)
    {
        if (sentence[k] == '!' || sentence[k] == '?' || sentence[k] == '.')
        {
            fullsentences++;
        }
    }

    words++;

    float L = (letters / (float) words) * 100;

    float S = (fullsentences / (float) words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);


    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}