#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("Whats your name? ");

// the i= means not equal

    int n = strlen(name);
    printf("%i\n", n);
}

// so int n = 0 is where you start counting
//  if it is not equal to \0  it'll repeat