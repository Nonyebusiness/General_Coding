#include <cs50.h>
#include <stdio.h>

int get_startsize(void);
int get_endsize(int start);

int main(void)
{

    int n, o, years = 0;

    n = get_startsize();
    o = get_endsize(n);


    while (n < o)
    {
        n += (n / 3) - (n / 4);
        years++;
    }

    printf("Years: %i\n", years);

}

int get_startsize(void)
{
    int a;
    do
    {
        a = get_long("Start size: ");
    }
    while (a < 8);
    return a;
}

int get_endsize(int start)
{
    int b;
    do
    {
        b = get_int("End size: ");
    }
    while (b < start);
    return b;
}