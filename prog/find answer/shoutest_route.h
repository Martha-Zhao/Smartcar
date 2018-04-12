#ifndef __SHOUTEST_ROUTE_H__
#define __SHOUTEST_ROUTE_H__

#include <stdlib.h>

//int solution[8][8];

struct find_route
{
    int *p;
    int min_sum;
    int turn;
};

struct find_route f_r;

void sot (int *dis_p, int *loc_p, int length);

struct  find_route *best_ans(int *loc_p, int *ans_p, int length);


#endif // __SHOUTEST_ROUTE_H__
