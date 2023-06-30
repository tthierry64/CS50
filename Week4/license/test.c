#include <stdio.h>

int main(void)
{
    int a = 12;
    int *p;
    char *q = "abcde";


    p = &a;

    printf("a = %i\n", a);
    printf("p = %p\n", p);
    printf("q = %p\n", q);
    printf("valeur pointée par q = %c\n", *q);
    printf("valeur pointée par q = %s\n", q);

    q = "nouvelle valeur de chaîne";
    printf("valeur pointée par q = %c\n", *q);
    printf("valeur pointée par q = %s\n", q);

}

