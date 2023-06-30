//https://cs50.harvard.edu/x/2023/psets/1/credit/

#include <cs50.h>
#include <stdio.h>

long get_cardnum(void);
long length_card(long cardnum);

int main(void)
{
    //Define the card number we want to analyse
    long cardnum = get_cardnum();
//    printf("the num is : %li\n", cardnum);

    //Make the sum of even digits (x2) et odd digits (starting from the end)

    long digit = 1;  // the analized digit = cardnum %10 : it is a tracker
    long sum_odd = 0;
    long sum_even = 0;
    long restdigit = cardnum;
    while (restdigit > 0)
    {
        if (digit % 2 == 0) // check if the digit is even
        {
            if ((restdigit % 10) > 4) // to analyse digit that contains 2  digits (ie (>9 like 10 or 11...)when multiplited by 2
            {
                sum_even += ((2 * (restdigit % 10)) / 10 + (2 * (restdigit % 10)) % 10);    //if the digit is even and double
            }
            else
            {
                sum_even += (restdigit % 10) * 2;    //if the digit is even non double
            }
        }
        else // or
        {
            sum_odd += restdigit % 10;     //if the digit is odd
        }
        restdigit = restdigit / 10;
        digit++;
    }

// Make the total sum
    long total;
    total = sum_odd + sum_even;

//    printf ("odd : %li \n", sum_odd);
//    printf ("even : %li \n", sum_even);
//   printf ("total is : %li \n", total);


// Guess the brand
    long lengthcard = length_card(cardnum);
//    printf("the length is : %li\n", lengthcard);
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }

    else if (lengthcard == 15 && (cardnum / 10000000000000 == 34 || cardnum / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if ((lengthcard == 13 || lengthcard == 16)  && (cardnum / 1000000000000 == 4 || cardnum / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else if ((lengthcard == 16)  && (cardnum / 100000000000000 >= 51 && cardnum / 100000000000000 <= 55))
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
// FONCTIONS -----------------------------------------------------------------------------------------------------------------------------------------------------------------

//---------- Prompt the card number
long get_cardnum(void)
{
    long cardnum;
    do
    {
        cardnum = get_long("Number: ");
    }
    while (cardnum < 0);
    return cardnum;
}
//---------- Get the length of the card
long length_card(long cardnum)
{
    long lengthcard = 0;
    while (cardnum > 0)
    {
        cardnum /= 10;
        lengthcard++;
    }
    return lengthcard;
}

