#include <cs50.h>
#include <stdio.h>

bool prime(int number);

int main(void)
{
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}d

bool prime(int number)
{
    // TODO
    int j;
    for (j = 2; j <= number - 1; j++)
    {
        if (number % j == 0)
        {
            return false;
        }
    }
    return number;
}