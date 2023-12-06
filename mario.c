#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;

    do
    {
        n = get_int("Pyramid Size: ");
    }
    while (n < 1 || n > 8);

    for (int i = 0; i < n; i++)
    {
        // Print the spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Print the hashes
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }

    return 0;
}