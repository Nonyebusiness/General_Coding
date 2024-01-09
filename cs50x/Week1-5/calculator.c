#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");


    double z = (double) x + (double) y;
    printf("%f\n", z);

}
 
int get_size(void)
{
    int n;
    do
    {
        n=get_int("size: ");
    }
    while (n < 1);
    return n;
}