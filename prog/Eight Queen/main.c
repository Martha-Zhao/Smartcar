#include <stdio.h>
#include <stdlib.h>


static int gEightQueen[8] = {0};
static int gcount = 0;
static int total [92][8] = {0};

void print()
{
    int outer;
    int inner;

    //int con = 0;

    for (outer = 0; outer < 8;outer++)
    {
//        for (inner = 0; inner <gEightQueen[outer] ; inner++ )
//            printf("* ");
//
//        printf ("# ");
//
//        for (inner = gEightQueen[outer]+1; inner < 8; inner++)
//            printf ("* ");
//
//        printf("    %d \n" , gEightQueen[outer]);

        total[gcount-1][outer] = gEightQueen[outer];
    }

   // printf("-------------------------------------\n\n");




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
    int a = 0;
    int b = 1;
    int c = 2;
    int i,j;

    c = a + b;
    a = c + b;
    b = a + c;
    eight_queen(0);
    printf("total = %d \n",gcount);

    for (i = 0; i < 92; i++)
    {
        printf("Number%d   ",i+1);
        for (j = 0; j < 8; j++)
        {
            printf("%d ",total[i][j]+1);
        }
        printf("\n\n");
    }
    return 1;
}
