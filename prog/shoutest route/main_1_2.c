#include <stdio.h>
#include <stdlib.h>

void sot (int *dis_p, int *loc_p, int length)
{
    int temp;
    int *p;
    int *q;
    for (int k = 0; k < length; k++)
    {
        for (int i = 0; i < length - 1; i++)
        {
            p = dis_p + 1;
            q = loc_p + 1;
            for (int j = i + 1; j < length; j++)
            {
                if (*dis_p > *p)
                {
                   temp = *dis_p;
                   *dis_p = *p;
                   *p = temp;

                   temp = *loc_p;
                   *loc_p = *q;
                   *q = temp;
                }
                p++;
                q++;
            }
            dis_p ++;
            loc_p ++;
        }
        dis_p += 8 - length + 1;
        loc_p += 8 - length + 1;
    }

}


int main()
{
    /***********************参数定义********************************/
    int loc[4] = {9,19,20,54};
    int ans[4] = {13,35,47,50};
    int *loc_p = loc;
    int *ans_p = ans;
    int p[8] = {0},q[8] = {0},r[8] = {0}, s[8] = {0};
    int *p_p,*p_q,*p_r,*p_s;
    int dis[8][8] = {0};
    int dis_sum[8] = {0};
    int *dis_p;
    int length = 4;
    int location[8][8] = { {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8}};

    int occupied[8] = {0};
    /***********************预处理********************************/

    loc_p = loc;
    ans_p = ans;

    printf("change form of loc and ans\n");
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
    p_p = p;
    p_q = q;
    p_r = r;
    p_s = s;
    for (int i = 0; i < length; i++)
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
    sot(dis[0],location[0],length);
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
    int cun = 0;
    int flag = 2;
    int k = 0;
    int min_sum = 64;
    for (int i = 0; i < length; i++) //优先解遍历
    {
        dis_sum[i] = dis[i][0];
        occupied[0] = location[i][0];
        cun = 1;
        for (int j = 0; j < length; j++)
        {
           if (j == i)
                j++;
//           else
//           {
               for (k = 0; (flag == 1)||( flag == 2 ); k++)
               {
                   for (int z = 0; z < cun; z++)
                   {
                       if (location[j][k] == occupied[z])
                       {
                           flag = 1;
                           break;
                       }
                       flag = 0;
                   }
                   if ( k == length)
                    break;
               }
               if (flag == 0)
               {
                  dis_sum[i] += dis[j][k - 1];
                  occupied[j] = location[j][k-1];
                  cun++;
                  flag = 1;
               }
//           }
        }
        printf("sum[%d] = %d\n",i,dis_sum[i]);
    }

    for (int i = 0;i < length; i++)
    {
        if (min_sum > dis_sum[i])
            min_sum = dis_sum[i];
    }
    printf("min_sum = %d\n",min_sum);

    int i = 0;
    dis_p = dis_sum;
    while (*dis_p > min_sum)
    {
        dis_p++;
        i++;
    }
    printf("number %d is min_sum = %d",i,*dis_p);



    return 0;
}
