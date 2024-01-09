#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");


    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input);  //get the length

    if (length == 0)  //the base case
    {
        return 0;
    }

    int digit = input[0] - '0'; 
    if (digit < 0 || digit > 9)
    {
        return -1; // Return -1 to indicate invalid input
    }

    return digit * pow(10, length - 1) + convert(input + 1);

}
