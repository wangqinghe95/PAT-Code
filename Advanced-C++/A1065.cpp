/*
主要是需要考虑到两个long long相加是否会越界的问题
*/
#include<cstdio>

int main()
{
    long long a, b, c;
    long long res;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        res = a + b;
        bool flag;
        if (a > 0 && b >0 && res < 0)
        {
            flag = true;
        }
        else if(a < 0 && b < 0 && res >= 0)
        {
           flag = false;
        }
        else if (res > c)
        {
            flag = true;
        }
        else
        {
            flag = false;
        }  
        
        if (flag)
        {
            printf("Case #%d: true",i);
        }
        else
        {
            printf("Case #%d: false", i);
        }
        printf("\n");
    }
    return 0;
}