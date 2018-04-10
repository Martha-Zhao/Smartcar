#include <stdio.h>
#include <stdlib.h>
//void sot (int *p, int length,int width)
//{
//    //int *p = loc;
//    for (int i = 0;i < width; i++)
//    {
//        for (int j = 0;j < length; j++)
//        {
//            printf("p[%d][%d] = %d  ",i,j,*p);
//            p++;
//        }
//        printf("\n");
//    }
//
//
//    for (int i = 0; i < length; i++,p++)
//    {
//        if (*p % 2 == 0)
//            *p = 0;
//    }
//}


int main()
{
    /***********************参数定义********************************/
    int loc[4] = {9,19,20,54};
    int ans[4] = {13,35,47,50};
    int p[8] = {0},q[8] = {0},r[8] = {0}, s[8] = {0};
    int *loc_p = loc;
    int *ans_p = ans;
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
    //sot(loc,8,2);
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



    loc_p = loc;
    ans_p = ans;
    for (int i = 0; i < length; i++)
    {
        ans_p = ans;
        for (int j = 0; j < length; j++)
        {
           dis[i][j] = abs(*loc_p - *ans_p);
           ans_p++;
           printf("%d ",dis[i][j]);
        }
        loc_p++;
        printf("\n");
    }
    printf("\n");
    return 0;
}
