// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>

int max(int array[], int n); //is a function that will take a array and a int

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int largest = 0; //this is a interger called largest set to 0

    for (int i = 0; i < n; i++) //this loop repeats for as many values there are
    {
        if (array[i] > largest) //this check the array numbered with the loop number is bigger than the largest number
        {
           largest = array[i]; //if it is then the largest number is set to that number
        }
    }

    return largest;
}
