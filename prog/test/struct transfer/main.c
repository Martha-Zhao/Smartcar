#include <stdio.h>
#include <stdlib.h>

#include "aaa.h"


int main()
{
    struct student *a;
    int loc = 0;
    a = fun();
    loc = *((a->p)+1);
    printf("a-min_sum = %d\n",a->min_sum);
    printf("a-dis[0][0] = %d\n",loc);


    return 0;
}
