#ifndef __SHOUTEST_ROUTE_H__
#define __SHOUTEST_ROUTE_H__

#include <stdlib.h>

//int solution[8][8];
//返回结构体
struct find_route
{
    int *p; //solution数组的地址
    int min_sum; //最优解路径长度
    int turn; //最优解顺序
};

struct find_route f_r;

void sot (int *dis_p, int *loc_p, int length); //排序

struct  find_route *best_ans(int *loc_p, int *ans_p, int length); //最优路径寻找


#endif // __SHOUTEST_ROUTE_H__
