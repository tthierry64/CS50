//https://cs50.harvard.edu/x/2023/psets/1/credit/

#include <cs50.h>
#include <stdio.h>

long get_cardnum(void);
long length_card (long cardnum);

int main(void)
{
    //Define the card number we want to analyse
    long cardnum = get_cardnum();
    printf("the num is : %li\n", cardnum);
    long lengthcard = length_card (cardnum);
    printf("the length is : %li\n", lengthcard);




}
//----------
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
//----------
long length_card (long cardnum)
{
    long length_card = 0;
    while (cardnum > 0)
    {
        cardnum /= 10;
        length_card++;
    }
    return length_card;
}

