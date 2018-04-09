/******************************************
* 找到92种解中0最多的解
* 去掉0最多的解中的相同元素
* 打印最终结果
* ZZY  UPDATE  20180408
*******************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    int *loc_p;
    int *loc_q;
    int *ans_p;

    int temp_sort = 0;

    /**********match zeros*****************/
    int k;

    int count_zeros [92][16] = {0};
    int *count_zeros_p;

    int loc_changed[][8] = {0};
    int ans_changed[][8] = {0};
    int optimal_solution_count = 0;

    int max_zeros = 0;

    /******************per edition*************************/
     //random location
    srand((unsigned)time(0)); //随机种子

    printf("random location is \n");
    // create random location
    loc_p = loc;
    for (; loc_p <= &loc[7]; loc_p++)
    {
        *loc_p = rand()%63+1;
        printf("%d ",*loc_p);
        // test whether repeated
        for (loc_q = loc; loc_q < loc_p; loc_q++)
        {
            if (*loc_p == *loc_q) //repeated
            {
                // print random location
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
    printf("\nlocation sorted\n");

    for ( loc_p = loc; loc_p <= &loc[7]; loc_p ++ )
    {
        for ( loc_q = loc_p+1; loc_q <= &loc[7];loc_q++ )
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
        printf("%d ",count_zeros[i][0]);//打印当前0的个数

        if (max_zeros < count_zeros[i][0]) //寻找0最多的个数
            max_zeros = count_zeros[i][0];
    }
    printf("\n max_zeros = %d \n",max_zeros);
    /******optimal solution round one************/
    printf("\nzeros matched\n");

    loc_p = loc_changed[0];
    ans_p = ans_changed[0];
    for (int i = 0; i<92; i++)
    {
        if ( count_zeros[i][0] == max_zeros )
        {
            optimal_solution_count++;
//            optimal_solution[optimal_solution_count-1] = i;
            printf("%d ",i+1);
            printf("\nmatched loc is\n");
            for (int j = 0;j<8; j++)
                printf("%d   %d\n",loc[j],ans[i][j]);//打印匹配结果

            for (int j = 0;j< 2*count_zeros[i][0];j++)
            {
                printf("%d ",count_zeros[i][j+1]); //打印匹配位置
            }
            printf("\n");

            count_zeros_p = count_zeros[i];
            count_zeros_p += 1;  //count_zeros_p指向count_zeros[1]
            for (int j = 0; j < 8; j++)
            {
                if (j == *count_zeros_p)
                    count_zeros_p += 2;
                else
                {
                    *loc_p = loc[j]; //loc_changed
                    loc_p++;
                }
            }
            loc_p += max_zeros ;

            count_zeros_p = count_zeros[i];
            count_zeros_p += 2;  //count_zeros_p指向count_zeros[2]
            for (int j = 0; j < 8; j++)
            {
                if (j == *count_zeros_p)
                    count_zeros_p += 2;
                else
                {
                    *ans_p = ans[i][j]; //ans_changed
                    ans_p++;
                }
            }
            ans_p += max_zeros ;
        }
    }

    printf("\noptimal_solution_count = %d \n",optimal_solution_count);//打印最优解的总数

    loc_p = loc_changed[0];
    ans_p = ans_changed[0];

    for ( int i = 0; i < optimal_solution_count; i++, loc_p += max_zeros, ans_p += max_zeros)
    {
        printf("solution %d is :\n",i+1);
        for ( int j = 0; j < (8 - max_zeros); j++,loc_p++,ans_p++)
        {
            printf("%d  %d\n",*loc_p, *ans_p);
        }
        printf("\n\n");
    }

    return 0;
}
