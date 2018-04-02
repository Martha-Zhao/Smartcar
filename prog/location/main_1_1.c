/*************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    //variables definition
    int loc[8] = {0}; //pieces location
    int temp_sort = 0; //排序临时变量
    int k = 0; //match zeros 临时变量
    int temp_count = 0;

    int optimal_solution_count = 0;//最优方案个数
    int optimal_solution[92] = {0};//最优方案序号

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
    int count_zeros[92][16] = {0};  //0的个数

    /******************per edition*************************/
    // random location
    srand((unsigned)time(0)); //随机种子

    printf("random location is \n");
    // create random location
    for (int i = 0; i<8;i++)
    {
        loc[i] = rand()%63+1;
        // test whether repeated
        for (int t = 0;t<i;t++)
        {
            if (loc[i] == loc[t]) //repeated
            {
                i =i-1;
                break;
            }
        }
    }
    // print random location
    for ( int i = 0 ; i<8; i++)
       printf("%d ", loc[i]);

    // sort
    printf("\nlocation sorted\n");
    for (int i = 0; i<8; i++)
    {
        for (int j=i+1;j<8;j++)
        {
            if (loc[j] < loc[i])
            {
                temp_sort = loc[j];
                loc[j] = loc[i];
                loc[i] = temp_sort;
            }
        }
        printf("%d ",loc[i]);
    }


    //print all answers
    printf("\nAll answers are\n");

    // change the form of ans[][]
    for (int i = 0; i < 92 ;i++)
    {
        for (int j = 0; j<8; j++)
        {
            ans[i][j] = j * 8 + ans[i][j];
            //printf("%d  ",ans[i][j]);
        }
        //printf("\n");

    }

/******************match zeros*************************/
    //count zeros
    int max_zeros = 0;
    printf("\ncount_zeros is\n");
    for (int i = 0; i < 92; i++)//92种解遍历
    {
        k=0;
        for (int j=0; j < 8;j++)//行遍历
        {
            temp_count = 0;
            for (;k <8;)
            {
                if (loc[j] == ans[i][k]) //匹配到0
                {
                    count_zeros[i][0]++;//0计数++
                    temp_count = count_zeros[i][0];
                    count_zeros[i][2*temp_count-1] = j;
                    count_zeros[i][2*temp_count] = k;
//                    count_zeros[i][&(count_zeros[i][0])] = j;
//                    count_zeros[i][&(count_zeros[i][0])+1] = k;
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
    for (int i = 0; i<92; i++)
    {
        if (count_zeros[i][0] == max_zeros )
        {
            optimal_solution_count++;
            optimal_solution[optimal_solution_count-1] = i;
            printf("%d ",i+1);
            printf("\nmatched loc is\n");
            for (int j = 0;j<8; j++)
            {
                printf("%d   %d\n",loc[j],ans[i][j]);//打印匹配结果
            }

            for (int j = 0;j< 2*count_zeros[i][0];j++)
            {
                printf("%d ",count_zeros[i][j+1]); //打印匹配位置
            }
            printf("\n\n\n");

        }
    }
    printf("\n optimal_solution_count = %d \n",optimal_solution_count);//打印最优解的总数






    return 0;
}
