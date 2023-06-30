#include <stdio.h>
#include <cs50.h>
int main()
{
  char ch;

  printf("Enter the character to get the ASCII value: ");
  scanf("%c", &ch);

  int ascii = ch;
  printf("ASCII value of %c = %d\n", ch, ascii);
  return 0;
}