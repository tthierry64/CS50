#include <cs50.h>
#include <stdio.h>
//https://cs50.harvard.edu/x/2023/labs/1/

// Say we have a population of n llamas. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.
//For example, if we were to start with n = 1200 llamas, then in the first year, 1200 / 3 = 400 new llamas would be born and
//1200 / 4 = 300 llamas would pass away. At the end of that year, we would have 1200 + 400 - 300 = 1300 llamas.
//To try another example, if we were to start with n = 1000 llamas, at the end of the year, we would have 1000 / 3 = 333.33 new llamas.
//We can’t have a decimal portion of a llama, though, so we’ll truncate the decimal to get 333 new llamas born. 1000 / 4 = 250 llamas will pass away,
//so we’ll end up with a total of 1000 + 333 - 250 = 1083 llamas at the end of the year.

//$ ./population
//Start size: -5
//Start size: 3
//Start size: 9
//End size: 5
//End size: 18
//Years: 8

int main(void)
{
    // TODO: Prompt for start size

    // TODO: Prompt for end size

    // TODO: Calculate number of years until we reach threshold

    // TODO: Print number of years
}

















#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);

    // TODO: Calculate number of years until we reach threshold
    int years=0;
    while (start < end)
    {
    start = start  + (start / 3) - (start/4);
    years++;
    }
    // TODO: Print number of years

    printf ("Years : %i\n", years);
}



ce que j'ai fait et qui marche : #include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start = 0;
    do
    {
        start = get_int("Start size : ");
    }
    while (start < 9);

    // TODO: Prompt for end size
    int end = 0;
    do
    {
    end = get_int("End size :");
    }
    while (start > end);

    // TODO: Calculate number of years until we reach threshold
    int years=0;
    int n = start;
    {
        while (n < end)
        {
         n *= 1 + 1/3 - 1/4;
        }
    }
        years++;
    // TODO: Print number of years

    printf ("Years : %i\n", years);

