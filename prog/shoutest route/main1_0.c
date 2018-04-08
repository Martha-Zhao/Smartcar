#include <stdio.h>
#include <stdlib.h>

int main()
{
    int loc [5] = {2,4,5,41,53};//除掉0的棋子位置数组
    int ans [5] = {20,31,33,46,61};//除掉0的期望位置数组
    int p = 0,q = 0,r = 0,s = 0;

    for (int i = 0;i < 5;i++)
    {
        //格式转换
        q = loc[i] % 8;
        if (q == 0)
            p = loc[i] / 8;
        else p = loc[i] / 8 + 1 ;

        s = ans[i] % 8;
        if (s == 0)
            r = ans[i] / 8;
        else r = ans[i] / 8 + 1 ;

        //匹配


    }
    return 0;
}
