#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your first name? ");
    printf("hello, %s\n", name);
}