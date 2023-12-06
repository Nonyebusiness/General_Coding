// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
}
avg_temp;

avg_temp temps[NUM_CITIES];

void swap(int *a, int *b);

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}


void swap(int *a, int *b)
{

 //the * star represents address
    int temporary = *a; //temporary equals the address of a
    *b = *a; //address of b equals the address of a
    temporary = *b; //temporary equals address of A which makes the address of B become the address of A

}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)   
{
    // Add your code here
    for (int i = 0; i < NUM_CITIES; i++) //this loop runs the algorithm as many times as there are cities
    {
        for (int j = 0; j < NUM_CITIES - i; j++) //this code repeats the sorting algorithm and is repeated as many times as there are cities minus i which is how many cities have been looked at already so it doesnt recompare unnessacily
        {
            if (temps[j].temp > temps[j+1].temp) //this decides if temp being looked at is greater than the temp above it
            {
                swap(&temps[j].temp, &temps[j+1].temp); //this valled the swap function to swap the temps, the ampersand converts the temps to addresses so the swap function can deal with it since it uses pointers
            }
        }
    }
}

