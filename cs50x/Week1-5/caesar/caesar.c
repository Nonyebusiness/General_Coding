#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool only_digits(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, string argv[])
{
    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    string word = get_string("Plaintext: ");

    for (int i = 0, n = strlen(word); i < n; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                word[i] = ((word[i] - 'A' + key) % 26) + 'A';
            }
            else if (islower(word[i]))
            {
                word[i] = ((word[i] - 'a' + key) % 26) + 'a';
            }
        }
    }

    printf("Ciphertext: %s\n", word);
}
