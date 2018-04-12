#include <stdio.h>
#include <stdlib.h>
#include "shoutest_route.h"
//dis数组排序 距离数组排序
void sot (int *dis_p, int *loc_p, int length)
{
    int temp;
    int *p;
    int *q;
    for (int k = 0; k < length; k++) //第k行
    {
        for (int i = 0; i < length - 1; i++) //排序
        {
            p = dis_p + 1;
            q = loc_p + 1;
            for (int j = i + 1; j < length; j++)
            {
                if (*dis_p > *p) //交换dis顺序
                {
                   temp = *dis_p;
                   *dis_p = *p;
                   *p = temp;

                   temp = *loc_p; //交换loc顺序
                   *loc_p = *q;
                   *q = temp;
                }
                p++;
                q++;
            }
            dis_p ++;
            loc_p ++;
        }
        dis_p += 8 - length + 1; //下一行
        loc_p += 8 - length + 1; //下一行
    }

}


struct  find_route * best_ans(int *loc_p, int *ans_p, int length) //最优路径求解
{
    /***********************参数定义********************************/
//    int loc[4] = {9,19,20,54};
//    int ans[4] = {13,35,47,50};
//    int *loc_p = loc;
//    int *ans_p = ans;
    int p[8] = {0},q[8] = {0},r[8] = {0}, s[8] = {0}; //改变形式 loc->p行 q列  ans->r行s列
    int *p_p,*p_q,*p_r,*p_s; //行列指针
    int dis[8][8] = {0}; //loc ans 距离一一对应构成的二维数组
    int dis_sum[8] = {0};  //某一种情况求和
    int *dis_p; //dis数组指针
    //int length = 4;
    //构造位置数组
    int location[8][8] = { {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8}};

    int occupied[8] = {0}; //已经被占用的位置数组


    int cun = 0; //已经移动棋子个数
    int flag = 2;  //是否被占用标志位
    int k = 0;
    int solution[8][8] = {0}; //最终解方案
    int *solu_p;//solution数组指针
    int temp_solution = 0; //临时变量
    int min_sum = 64; //距离最小值
    /***********************预处理********************************/

//    loc_p = loc;
//    ans_p = ans;

    printf("change form of loc and ans\n"); //改变形式 64-->行列
    for (int i = 0; i < length; i++,loc_p++,ans_p++)
    {
        if (*loc_p % 8 == 0)
        {
            p[i] = *loc_p / 8;
            q[i] = 8;
        }
        else
        {
            p[i] = (*loc_p / 8) + 1;
            q[i] = *loc_p % 8;
        }

        if (*ans_p % 8 == 0)
        {
            r[i] = *ans_p / 8;
            s[i] = 8;
        }
        else
        {
            r[i] = (*ans_p / 8) + 1;
            s[i] = *ans_p % 8;
        }
        printf("%d  %d---%d  %d---%d  %d\n",*loc_p,p[i],q[i],r[i],s[i],*ans_p);
    }


    /***********************求和--排序********************************/
    p_p = p;//指针初始化位置
    p_q = q;
    p_r = r;
    p_s = s;
    for (int i = 0; i < length; i++)//求loc与ans两两之间的距离
    {
        p_r = r;
        p_s = s;
        for (int j = 0; j < length; j++)
        {
           dis[i][j] = abs(*p_p - *p_r) + abs(*p_q-*p_s);
           p_r++;
           p_s++;
           printf("%d ",dis[i][j]);
        }
        p_p++;
        p_q++;
        printf("\n");
    }
    printf("\n");

    //排序
    sot(dis[0],location[0],length); //按距离排序并保留原始位置
    //输出sot结果
    printf("dis ans location is\n");
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d---%d\n",dis[i][j],location[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    /***********************寻路********************************/
    for (int i = 0; i < length; i++) //合理解遍历
    {
        for (int j = 1; j < length; j++)//第j个棋子优先考虑
            occupied[j] = 0;
        dis_sum[i] = dis[i][0]; //dis_sum初始化
        occupied[0] = location[i][0];//第j个棋子所在位置被占用
        cun = 1;//一个棋子排序完成，计数加一
        solution[i][0] = location[i][0]; //将当前棋子的位置保存在solution[i][0]
        for (int j = 0; j < length; j++)//遍历剩下的棋子
        {
           if (j == i)
                j++;
//           else
//           {
               for (k = 0; (flag == 1)||( flag == 2 ); k++)
               {
                   for (int z = 0; z < cun; z++) //判断当前位置是否被占用
                   {
                       if (location[j][k] == occupied[z])//如果被占用找一下个位置
                       {
                           flag = 1;
                           break;
                       }
                       flag = 0;
                   }
                   if ( k == length)
                       break;

               }
               if (flag == 0) //如果不被占用，当前棋子加入可行解
               {
                  dis_sum[i] += dis[j][k - 1]; //距离更新
                  occupied[cun] = location[j][k-1]; //被占位置更新
                  solution[i][cun] = location[j][k-1]; //保存棋子位置
                  cun++; //已放置棋子个数+1
                  flag = 1;//更新标志位
               }
//           }
        }
        printf("sum[%d] = %d\n",i,dis_sum[i]); //输出当前解的距离总数
    }

    for (int i = 0;i < length; i++) //找到最短距离
    {
        if (min_sum > dis_sum[i])
            min_sum = dis_sum[i];
    }
    printf("min_sum = %d\n",min_sum); //输出最短距离

    int i = 0;
    dis_p = dis_sum; //dis_p指针指向距离数组
    while (*dis_p > min_sum) //dis_p指向距离最短的数组
    {
        dis_p++;
        i++;
    }

    solu_p = solution[i]; //solu_p指向距离最短的方案
    temp_solution = *solu_p; //临时变量
    for (int j = 0; j < i; j++)//棋子位置回到正常情况
    {
        *solu_p = *(solu_p + 1);
        solu_p ++;
    }
    *solu_p = temp_solution;

    printf("number %d is min_sum = %d\n",i,*dis_p); //输出最短距离
    for (int j = 0; j < length; j++)//输出最优方案
    {
        printf("%d ",solution[i][j]);
    }
    printf("\n");

    f_r.min_sum = min_sum; //确定最优方案的结构体
    f_r.p = solution[i];
    f_r.turn = i;
    //f_r = {solution[i],min_sum,i};

    return &f_r; //返回结构体地址
}
