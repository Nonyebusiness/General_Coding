#include <cs50.h>
#include <stdio.h>

int main(void)
{
    float a, b, c, d;

    a = get_float("Bill before tax and tip: ");

    b = get_float("Sale Tax Percent: ");

    c = get_float("Tip Percent: ");

    d = (a + ((a/100) * b) + ((a/100) * c))/2;

    printf("You will owe $%.2f each!\n", d);
}