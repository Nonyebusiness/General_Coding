#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    //this is how many weeks the user does
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    //this loop repeats until i is greater then weeks and gets how many hours the user does
    //the number of week is how many times i has looped so the beginning is 0 since i starts at 0
    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    //this gets a or t to decide what calculation to do
    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');
//this prints the output
    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{

    //this sets calc hours to 0 so we can freely add values to it
    float calc_hours = 0;


    //this calcualtion is for if the user pressed T
    if ( output == 'T')
    {

        // this loop repeats until we've lopped the number of weeks
        for (int i = 0; i < weeks; i++)
        {
         calc_hours += hours[i]; //this adds the hours based on what week and loop we're on so if we're on loop 3 it adds how many hours was put in week 3
        }

    return calc_hours; //here we give the calcvalue over to the printf

    }
    else if( output == 'A') //this is the calcualtions for if th euser pressed A
    {
        for (int i = 0; i < weeks; i++) //same thing as the other loop
        {
         calc_hours += hours[i]; // same as the other addition one
        }
        calc_hours /= weeks; //this time we divide the calc hours by how many weeks there are to find th eaverage

        return calc_hours; //gives the calcualtions to print
    }
    else //this a backup incase something goes wrong
    {
        return 1;
    }
}