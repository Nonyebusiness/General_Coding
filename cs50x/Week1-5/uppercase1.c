#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string s = get_string("Before: ");
    printf("After: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
            printf("%c", toupper(s[i]));
    }
    printf("\n");

    // the && means and

    // so in this code s of the letters becomes what you type in the before string,
    // then after is printed without moving to a new spot
    // then the for loop starts from i, and finds n which equals the previous string; if i is less than n; then you actiave the print whwich  convert the letter to capital

}