#include <stdio.h>
#include <stdlib.h>

void sot (int *dis_p, int *loc_p, int length)
{
    int temp;
    for (int i = 0;i <= length; i++)
    {
        for (int j = 0;j < length - 1; j++)
        {
            if (*dis_p > *(dis_p + 1))
            {
               temp = *dis_p;
               *dis_p = *(dis_p + 1);
               *(dis_p + 1) = temp;

               temp = *loc_p;
               *loc_p = *(loc_p + 1);
               *(loc_p + 1) = temp;
            }
            dis_p++;
            loc_p++;
        }
        dis_p += 8 - length;
        loc_p += 8 - length;
        printf("\n");
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
    int dis_sum = {0};
    int length = 4;
    int location[8][8] = { {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8},
                           {1,2,3,4,5,6,7,8}};


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


    sot(dis[0],location[0],length);

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            printf("%d ",dis[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    return 0;
}
