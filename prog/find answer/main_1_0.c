/******************************************
* 找到92种解中0最多的解
* 去掉0最多的解中的相同元素
* 在所有符合条件的解中找到最优解
* ZZY  UPDATE  20180412
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "shoutest_route.h"//计算最短路径头文件

extern int solution[8][8]; //最优解方案

int main()
{
    /***********************variables definition************************/
    int loc[8] = {0}; //pieces location
    int ans[92][8] = {   //All answers
               { 1 ,   5 ,   8 ,   6 ,   3 ,   7 ,   2 ,   4},
               { 1 ,   6 ,   8 ,   3 ,   7 ,   4 ,   2 ,   5},
               { 1 ,   7 ,   4 ,   6 ,   8 ,   2 ,   5 ,   3},
               { 1 ,   7 ,   5 ,   8 ,   2 ,   4 ,   6 ,   3},
               { 2 ,   4 ,   6 ,   8 ,   3 ,   1 ,   7 ,   5},
               { 2 ,   5 ,   7 ,   1 ,   3 ,   8 ,   6 ,   4},
               { 2 ,   5 ,   7 ,   4 ,   1 ,   8 ,   6 ,   3},
               { 2 ,   6 ,   1 ,   7 ,   4 ,   8 ,   3 ,   5},
               { 2 ,   6 ,   8 ,   3 ,   1 ,   4 ,   7 ,   5},
               { 2 ,   7 ,   3 ,   6 ,   8 ,   5 ,   1 ,   4},
               { 2 ,   7 ,   5 ,   8 ,   1 ,   4 ,   6 ,   3},
               { 2 ,   8 ,   6 ,   1 ,   3 ,   5 ,   7 ,   4},
               { 3 ,   1 ,   7 ,   5 ,   8 ,   2 ,   4 ,   6},
               { 3 ,   5 ,   2 ,   8 ,   1 ,   7 ,   4 ,   6},
               { 3 ,   5 ,   2 ,   8 ,   6 ,   4 ,   7 ,   1},
               { 3 ,   5 ,   7 ,   1 ,   4 ,   2 ,   8 ,   6},
               { 3 ,   5 ,   8 ,   4 ,   1 ,   7 ,   2 ,   6},
               { 3 ,   6 ,   2 ,   5 ,   8 ,   1 ,   7 ,   4},
               { 3 ,   6 ,   2 ,   7 ,   1 ,   4 ,   8 ,   5},
               { 3 ,   6 ,   2 ,   7 ,   5 ,   1 ,   8 ,   4},
               { 3 ,   6 ,   4 ,   1 ,   8 ,   5 ,   7 ,   2},
               { 3 ,   6 ,   4 ,   2 ,   8 ,   5 ,   7 ,   1},
               { 3 ,   6 ,   8 ,   1 ,   4 ,   7 ,   5 ,   2},
               { 3 ,   6 ,   8 ,   1 ,   5 ,   7 ,   2 ,   4},
               { 3 ,   6 ,   8 ,   2 ,   4 ,   1 ,   7 ,   5},
               { 3 ,   7 ,   2 ,   8 ,   5 ,   1 ,   4 ,   6},
               { 3 ,   7 ,   2 ,   8 ,   6 ,   4 ,   1 ,   5},
               { 3 ,   8 ,   4 ,   7 ,   1 ,   6 ,   2 ,   5},
               { 4 ,   1 ,   5 ,   8 ,   2 ,   7 ,   3 ,   6},
               { 4 ,   1 ,   5 ,   8 ,   6 ,   3 ,   7 ,   2},
               { 4 ,   2 ,   5 ,   8 ,   6 ,   1 ,   3 ,   7},
               { 4 ,   2 ,   7 ,   3 ,   6 ,   8 ,   1 ,   5},
               { 4 ,   2 ,   7 ,   3 ,   6 ,   8 ,   5 ,   1},
               { 4 ,   2 ,   7 ,   5 ,   1 ,   8 ,   6 ,   3},
               { 4 ,   2 ,   8 ,   5 ,   7 ,   1 ,   3 ,   6},
               { 4 ,   2 ,   8 ,   6 ,   1 ,   3 ,   5 ,   7},
               { 4 ,   6 ,   1 ,   5 ,   2 ,   8 ,   3 ,   7},
               { 4 ,   6 ,   8 ,   2 ,   7 ,   1 ,   3 ,   5},
               { 4 ,   6 ,   8 ,   3 ,   1 ,   7 ,   5 ,   2},
               { 4 ,   7 ,   1 ,   8 ,   5 ,   2 ,   6 ,   3},
               { 4 ,   7 ,   3 ,   8 ,   2 ,   5 ,   1 ,   6},
               { 4 ,   7 ,   5 ,   2 ,   6 ,   1 ,   3 ,   8},
               { 4 ,   7 ,   5 ,   3 ,   1 ,   6 ,   8 ,   2},
               { 4 ,   8 ,   1 ,   3 ,   6 ,   2 ,   7 ,   5},
               { 4 ,   8 ,   1 ,   5 ,   7 ,   2 ,   6 ,   3},
               { 4 ,   8 ,   5 ,   3 ,   1 ,   7 ,   2 ,   6},
               { 5 ,   1 ,   4 ,   6 ,   8 ,   2 ,   7 ,   3},
               { 5 ,   1 ,   8 ,   4 ,   2 ,   7 ,   3 ,   6},
               { 5 ,   1 ,   8 ,   6 ,   3 ,   7 ,   2 ,   4},
               { 5 ,   2 ,   4 ,   6 ,   8 ,   3 ,   1 ,   7},
               { 5 ,   2 ,   4 ,   7 ,   3 ,   8 ,   6 ,   1},
               { 5 ,   2 ,   6 ,   1 ,   7 ,   4 ,   8 ,   3},
               { 5 ,   2 ,   8 ,   1 ,   4 ,   7 ,   3 ,   6},
               { 5 ,   3 ,   1 ,   6 ,   8 ,   2 ,   4 ,   7},
               { 5 ,   3 ,   1 ,   7 ,   2 ,   8 ,   6 ,   4},
               { 5 ,   3 ,   8 ,   4 ,   7 ,   1 ,   6 ,   2},
               { 5 ,   7 ,   1 ,   3 ,   8 ,   6 ,   4 ,   2},
               { 5 ,   7 ,   1 ,   4 ,   2 ,   8 ,   6 ,   3},
               { 5 ,   7 ,   2 ,   4 ,   8 ,   1 ,   3 ,   6},
               { 5 ,   7 ,   2 ,   6 ,   3 ,   1 ,   4 ,   8},
               { 5 ,   7 ,   2 ,   6 ,   3 ,   1 ,   8 ,   4},
               { 5 ,   7 ,   4 ,   1 ,   3 ,   8 ,   6 ,   2},
               { 5 ,   8 ,   4 ,   1 ,   3 ,   6 ,   2 ,   7},
               { 5 ,   8 ,   4 ,   1 ,   7 ,   2 ,   6 ,   3},
               { 6 ,   1 ,   5 ,   2 ,   8 ,   3 ,   7 ,   4},
               { 6 ,   2 ,   7 ,   1 ,   3 ,   5 ,   8 ,   4},
               { 6 ,   2 ,   7 ,   1 ,   4 ,   8 ,   5 ,   3},
               { 6 ,   3 ,   1 ,   7 ,   5 ,   8 ,   2 ,   4},
               { 6 ,   3 ,   1 ,   8 ,   4 ,   2 ,   7 ,   5},
               { 6 ,   3 ,   1 ,   8 ,   5 ,   2 ,   4 ,   7},
               { 6 ,   3 ,   5 ,   7 ,   1 ,   4 ,   2 ,   8},
               { 6 ,   3 ,   5 ,   8 ,   1 ,   4 ,   2 ,   7},
               { 6 ,   3 ,   7 ,   2 ,   4 ,   8 ,   1 ,   5},
               { 6 ,   3 ,   7 ,   2 ,   8 ,   5 ,   1 ,   4},
               { 6 ,   3 ,   7 ,   4 ,   1 ,   8 ,   2 ,   5},
               { 6 ,   4 ,   1 ,   5 ,   8 ,   2 ,   7 ,   3},
               { 6 ,   4 ,   2 ,   8 ,   5 ,   7 ,   1 ,   3},
               { 6 ,   4 ,   7 ,   1 ,   3 ,   5 ,   2 ,   8},
               { 6 ,   4 ,   7 ,   1 ,   8 ,   2 ,   5 ,   3},
               { 6 ,   8 ,   2 ,   4 ,   1 ,   7 ,   5 ,   3},
               { 7 ,   1 ,   3 ,   8 ,   6 ,   4 ,   2 ,   5},
               { 7 ,   2 ,   4 ,   1 ,   8 ,   5 ,   3 ,   6},
               { 7 ,   2 ,   6 ,   3 ,   1 ,   4 ,   8 ,   5},
               { 7 ,   3 ,   1 ,   6 ,   8 ,   5 ,   2 ,   4},
               { 7 ,   3 ,   8 ,   2 ,   5 ,   1 ,   6 ,   4},
               { 7 ,   4 ,   2 ,   5 ,   8 ,   1 ,   3 ,   6},
               { 7 ,   4 ,   2 ,   8 ,   6 ,   1 ,   3 ,   5},
               { 7 ,   5 ,   3 ,   1 ,   6 ,   8 ,   2 ,   4},
               { 8 ,   2 ,   4 ,   1 ,   7 ,   5 ,   3 ,   6},
               { 8 ,   2 ,   5 ,   3 ,   1 ,   7 ,   4 ,   6},
               { 8 ,   3 ,   1 ,   6 ,   2 ,   5 ,   7 ,   4},
               { 8 ,   4 ,   1 ,   3 ,   6 ,   2 ,   7 ,   5}
               };

    /**********随机生成棋子位置************/
    int *loc_p; //随机棋子位置数组指针
    int *loc_q; //棋子排序时用到的随机棋子位置数组指针
    int *ans_p; //解数组的指针

    int temp_sort = 0; //排序临时变量

    /**********match zeros*****************/
    int k; //0的个数临时变量

    int count_zeros [92][16] = {0}; //所有方案0的个数数组
    int *count_zeros_p; //所有方案0的个数数组的指针

    int loc_changed[20][8] = {0}; //需要移动的棋子的位置数组
    int ans_changed[20][8] = {0}; //棋子移动的目标位置数组
    int optimal_solution_count = 0; //可行解计数

    int max_zeros = 0; //0最多的个数
    int min_s = 64; //总移动距离的最小值
    int solution_num = 0; //最有方案序号
    int f_r_t = 0; //struct shoutest——route 返回指针临时变量
    struct  find_route *best_ans_loc; //struct shoutest——route 返回指针
    struct find_route *f_r_p; ////struct shoutest——route 返回指针

    /******************per edition*************************/
     //random location
    srand((unsigned)time(0)); //随机种子

    printf("random location is \n");
    // create random location
    loc_p = loc;
    for (; loc_p <= &loc[7]; loc_p++)
    {
        *loc_p = rand()%63+1; //在1-64中随机生成8个数
        printf("%d ",*loc_p); //打印
        // test whether repeated
        for (loc_q = loc; loc_q < loc_p; loc_q++) //查重
        {
            if (*loc_p == *loc_q) //repeated
            {
                // print random location//找到重复 退格
                if (*loc_p > 9)
                    printf("\b\b\b");
                else
                    printf("\b\b");

                loc_p--;
                break;
            }
        }
    }
    printf("\n");

     //sort
    printf("\nlocation sorted\n");//排序

    for ( loc_p = loc; loc_p <= &loc[7]; loc_p ++ ) //i=0:7
    {
        for ( loc_q = loc_p+1; loc_q <= &loc[7];loc_q++ ) //j=i+1:7
        {
            if ( *loc_q < *loc_p )
            {
                temp_sort = *loc_q;
                *loc_q = *loc_p;
                *loc_p = temp_sort;
            }
        }
        printf("%d ",*loc_p);
    }


    ///print all answers
    printf("\nAll answers are\n");

     //change the form of ans[][]
    for ( int i = 0; i <92; i++ )
    {
        for ( int j = 0; j < 8; j++)
        {
            *(*(ans+i)+j) += j * 8;
           // printf("%d ",*(*(ans+i)+j) );
        }
        //printf("\n");
    }
///****************************match zeros****************************************/
    //count zeros
    for (int i = 0; i < 92; i++)//92种解遍历
    {
        k=0;
        count_zeros_p = count_zeros[i];
        for (int j=0; j < 8;j++)//行遍历
        {
            for (;k <8;)
            {
                if (loc[j] == ans[i][k]) //匹配到0
                {
                    count_zeros[i][0] +=1;
                    *++count_zeros_p = j;
                    *++count_zeros_p = k;
                    k++;//匹配下一个位置
                    break;
                }
                else//比配不相等
                {
                    if (loc[j] < ans[i][k])
                        break;
                    else k++;
                }
            }
        }
       // printf("%d ",count_zeros[i][0]);//打印当前0的个数

        if (max_zeros < count_zeros[i][0]) //寻找0最多的个数
            max_zeros = count_zeros[i][0];
    }
    printf("\n max_zeros = %d \n",max_zeros);
    /******optimal solution round one************/
    printf("\nzeros matched\n");

    loc_p = loc_changed[0]; //loc_changed中保存去掉相同位置的棋子位置
    ans_p = ans_changed[0]; //loc_changed中保存去掉相同位置的目标位置
    for (int i = 0; i<92; i++)
    {
        if ( count_zeros[i][0] == max_zeros ) //找到合理解
        {
            optimal_solution_count++; //合理解个数+1
//            optimal_solution[optimal_solution_count-1] = i;
            printf("%d ",i+1); //打印当前合理解
            printf("\nmatched loc is\n");
            for (int j = 0;j<8; j++)
                printf("%d   %d\n",loc[j],ans[i][j]);//打印匹配结果

            for (int j = 0;j< 2*count_zeros[i][0];j++)
            {
                printf("%d ",count_zeros[i][j+1]); //打印匹配位置
            }
            printf("\n");

            count_zeros_p = count_zeros[i];//去掉0
            count_zeros_p += 1;  //count_zeros_p指向count_zeros[1]
            for (int j = 0; j < 8; j++)
            {
                if (j == *count_zeros_p)
                    count_zeros_p += 2;
                else
                {
                    *loc_p = loc[j]; //loc_changed 去掉loc中的0
                    loc_p++;
                }
            }
            loc_p += max_zeros ;//loc_p指向loc_changed的下一行

            count_zeros_p = count_zeros[i];
            count_zeros_p += 2;  //count_zeros_p指向count_zeros[2]
            for (int j = 0; j < 8; j++) //去掉合理解中的0
            {
                if (j == *count_zeros_p)
                    count_zeros_p += 2;
                else
                {
                    *ans_p = ans[i][j]; //ans_changed
                    ans_p++;
                }
            }
            ans_p += max_zeros ;//ans_p指向ans_changed的下一行
        }
    }

    printf("\noptimal_solution_count = %d \n",optimal_solution_count);//打印最优解的总数

//    loc_p = loc_changed[0];//从第一种解开始求需要走的路径
//    ans_p = ans_changed[0];//对应第一种方案

    for ( int i = 0; i < optimal_solution_count; i++, loc_p += max_zeros, ans_p += max_zeros)//遍历合理解
    {
        printf("solution %d is :\n",i+1); //打印当前合理解的序号

        loc_p = loc_changed[i];//第i种解
        ans_p = ans_changed[i];//第i种方案
        for ( int j = 0; j < (8 - max_zeros); j++,loc_p++,ans_p++) //输出当前方案
        {
            printf("%d  %d\n",*loc_p, *ans_p);
        }
        printf("\n\n");
        loc_p = loc_changed[i];//指针回归loc_changed[i][0]
        ans_p = ans_changed[i];//指针回归ans_changed[i][0]

        f_r_p = best_ans(loc_p, ans_p, (8-max_zeros)); //调用子函数求解第i种方案的最优路径
        f_r_t = *f_r_p->p;//解保存的数组
        printf("solution[%d] = %d\n",i,f_r_t);
        printf("min_sum[%d] = %d\n",i,f_r_p->min_sum);//输出当前方案路径
        printf("turn[%d] is %d\n",i,f_r_p->turn); //执行顺序

        if (f_r_p->min_sum < min_s)//定位指针到best_ans_loc
        {
            min_s = f_r_p->min_sum;
            solution_num = i;
            f_r_t = *f_r_p->p;
            best_ans_loc = f_r_p;
        }
    }

    printf("best solution is %d\n",solution_num); //输出最优解序号
    printf("solution = %d\n",f_r_t); //输出最优解
    printf("min_sum = %d\n",best_ans_loc->min_sum); //输出最优解路径
    printf("turn is %d\n",best_ans_loc->turn); //输出最优解顺序

    return 0;
}
