//https://cs50.harvard.edu/x/2023/psets/1/cash/
#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();


    // Print total number of coins to give the customer
     int quarters = calculate_quarters(cents);
    printf("%i\n", quarters);
}
//----------
int get_cents(void)
{
    int cents;
    do
    {
    cents = get_float("Change owed: ")*100.00;
    }
    while(cents < 0);
    return cents;
}
//----------
int calculate_quarters(int cents)
{
    int quarters;
    {
        quarters = cents/25;
    }
    return quarters;
}
//----------
int calculate_dimes(int cents)
{
    // TODO
    return 0;
}
//----------
int calculate_nickels(int cents)
{
    // TODO
    return 0;
}
//----------
int calculate_pennies(int cents)
{
    // TODO
    return 0;
}
