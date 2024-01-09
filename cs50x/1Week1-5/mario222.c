#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // this code continously asks user for a number greater than 1
    int n;
    do
    {
        n= get_int("Size: ");
    }
    while (n < 1);


    // this code generates a square adding n rows that are n wide
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("#");
        }
        printf("\n");
    }

}