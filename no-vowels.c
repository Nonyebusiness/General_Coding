// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(int argc, string argv[])
{
        if (argc < 2) //this is for if the user didnt type anything after the command
    {
        printf("Usage: ./no-vowels [input_string]\n");
        return 1;
    }

    string input = argv[1];  //this sets input to the letters typed in the commandline

    int length = strlen(input); //this finds the length of how long the sentnece is

    for (int i = 0; i < length; i++) //this is a loop that stops once the loop has looped as many times as the entire sentence length
    {
        if (input[i] == 'a') //this looks at the current letter based on how many times the code has looped for exmaple if we're on loop 4 it will look at the 4th letter
        {
            input[i] = '6'; //this sets the letter to the desired letter
        }
        else if(input[i] == 'e')
        {
            input[i] = '3';
        }
        else if(input[i] == 'i')
        {
            input[i] = '1';
        }
        else if (input[i] == 'o')
        {
            input[i] = '0';
        }
        else
        {
            continue; //if the letterisnt a vowel the loop starts again which should be a different letter
        }
    }

    printf("%s\n", input);
}
