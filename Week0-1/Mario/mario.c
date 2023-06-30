//https://cs50.harvard.edu/x/2023/psets/1/mario/more/
#include <cs50.h>
#include <stdio.h>


int get_height(void);
void print_space(int height);
void print_block(int height);

int main(void)

{
    int height = get_height();
    for (int line = 1; line <= height; line++)
    {
        print_space(height - line);
        print_block(line);
        printf("  ");
        print_block(line);
        printf("\n");
    }

}

//----------
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (1 > height || height > 8);
    return height;
}
//----------
void print_space(int height)
{
       for(int num_space = 0; num_space < height; num_space++)
     {
        printf(" ");
     }
}
//----------
void print_block(int height)
{
      for(int num_block = 0; num_block < height; num_block++)
    {
        printf("#");
    }
}