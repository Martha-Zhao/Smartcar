#include <stdio.h>
#include <stdlib.h>


static int gEightQueen[8] = {0};
static int gcount = 0;

void print()
{
    int outer;
    int inner;

    for (outer = 0; outer < 8;outer++)
    {
        for (inner = 0; inner <gEightQueen[outer] ; inner++ )
            printf("* ");

        printf ("# ");

        for (inner = gEightQueen[outer]+1; inner < 8; inner++)
            printf ("* ");

        printf("    %d \n" , gEightQueen[outer]);
    }

    printf("-------------------------------------\n");




}

int check (int loop ,int value)
{
    int index;
    int data;

    for (index = 0; index < loop ; index++)
    {
        data = gEightQueen[index];

        if ( (index == loop) || (data == value) )
            return 0;

        if ( ( (index + data) == (loop + value) ) ||( (index - data) == (loop - value) ) )
            return 0;
    }

    return 1;
}


void eight_queen (int index)
{
    int loop;

    for (loop = 0; loop < 8; loop++)
    {
        if  (check (index,loop) )
        {
            gEightQueen[index] = loop;

            if (index == 7)
            {
                gcount++, print();
                gEightQueen[index] = 0;
                return ;
            }

            eight_queen(index + 1);
            gEightQueen[index] = 0;
        }
    }
}



int main(int argc, char* argv[])
{
    eight_queen(0);
    printf("total = %d \n",gcount);
    return 1;
}
