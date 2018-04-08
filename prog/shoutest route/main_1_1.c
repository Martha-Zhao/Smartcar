/****************************************************
* shoutest route
* 指定当前棋子位置数组 loc
* 指定当前0最多的某一种解 ans
* ZZY---20180408
***************************************************/

#include <stdio.h>
#include <stdlib.h>

void sot ( int (*dis)[4], int (*loc)[4], int lenth)
{
    int temp = 0;
    for (int k = 0;k < 4; k++)
    {
        for ( int i = 0; i < lenth - 1; i++)
        {
            for ( int j = i + 1; j < lenth; j++)
            {
                if ( dis[k][i] > dis[k][j] )
                {
                    temp = dis[k][i];
                    dis[k][i] = dis[k][j];
                    dis[k][j] = temp;

                    temp = loc[k][i];
                    loc[k][i] = loc[k][j];
                    loc[k][j] = temp;
                }
            }

        }
    }
}


int main()
{
    int loc[4] = {9,19,20,54};//pieces location
    int ans[4] = {13,35,47,50}; // one of solutions
    int p[4]={0},q[4]={0},r[4]={0},s[4]={0}; //p--pieces row  q---pieces column r---ans row s---ans column
    int dis[4][4] = {0}; // distance mat
    int location[4][4] = {{1,2,3,4},{1,2,3,4},{1,2,3,4},{1,2,3,4}}; //sorted location
    int dis_sum[4] = {0}; //certain answer sum

    int occupied[4]; //occupied mat


    //change the form of ans and loc
    printf ("change form results\n");

    for (int i = 0; i < (sizeof(loc)/sizeof(int)); i++)
    {
        if (loc[i] % 8 == 0)
        {
            p[i] = loc[i] / 8;
            q[i] = 8;
        }
        else
        {
            p[i] = loc[i] / 8 + 1;
            q[i] = loc[i] % 8;
        }
        printf ("%d  %d---%d   ",loc[i],p[i],q[i]);

        if (ans[i] % 8 == 0)
        {
            r[i] = ans[i] /  8;
            s[i] = 8;
        }
        else
        {
            r[i] = ans[i] / 8 + 1;
            s[i] = ans[i] % 8;
        }
        printf("%d   %d---%d\n",ans[i],r[i],s[i]);
    }

    // 求各点之间距离
    for ( int i = 0; i< 4; i++ )
    {
        for ( int j = 0; j < 4; j++)
        {
            dis[i][j] = abs( p[i] - r[j] ) + abs( q[i] - s[j] );
            printf("%d  ",dis[i][j]);
        }
        printf("\n");
    }

    //路径按照大小排序
    sot(dis, location, 4);

    //输出排序完成的数组以及序号位置
    for ( int k = 0; k < 4; k++)
    {
        for ( int i = 0 ;i < 4; i++)
        {
            printf("%d---",dis[k][i]);
            printf("%d\n",location[k][i]);
        }
        printf("\n\n");
    }

    //找到最优解
    int flag = 0;
//    for (int i = 0; i < 4; i++) //优先解遍历
//    {
//        dis_sum[i] = dis[i][0];
//        occupied[0] = location[i][0];
        int k = 0;
        int z = 0;
        int a = 0;
        flag = 2;
        for ( int j = 0; j < 4; j++ )
        {
            for ( a = 0; (flag == 1)||( flag == 2 ); a++)
            {
                for ( z = 0; z < k; z++)
                {
                    if ( location[j][a] == occupied[z] )
                    {
                        flag = 1;
                        break;
                    }
                    flag = 0;
                }
                if ( a == 4 )
                {
                    break;
                }
            }

            if ( flag == 2)
            {
               dis_sum[0] += dis[j][0];
               occupied[j] = location[j][0];
               k++;
            }
            else if ( flag == 0 )
            {
               dis_sum[0] += dis[j][a-1];
               occupied[j] = location[j][a-1];
               k++;
               flag = 1;
            }
            else
                break;
        }
     printf("sum of number %d is %d \n",0,dis_sum[0]);
//    }

    return 0;
}
