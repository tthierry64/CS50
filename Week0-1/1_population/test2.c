#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int n;
    do
    {
        n = get_int ("Start: ");
    }
    while (n < 9);

    int m;
    do
    {
        m = get_int("End :");
    }
    while (m < n);

    int y = 0;
    while (n < m)
  { n = n + n / 3 - n / 4;
    y++;
  }
        {
            printf ("Years : %i\n", y);
        }
}