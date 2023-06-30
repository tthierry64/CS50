#include <cs50.h>
#include <stdio.h>

int main (void)

{
    int size;
    do
    {
        size = get_int("size of the array: ");
    }
    while (size < 1);

int array[size];
array[0] = 1;

for (int i = 1; i < size; i++)
{
   array[i] = 2 * array[i - 1];
}
for (int j = 0; j < size; j++)
{printf("%i ", array[j]);
}
}