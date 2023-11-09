//https://www.cnblogs.com/wanghao-boke/p/11915329.html
#include<cstdio>
const int maxn = 60;

int main()
{
    int age[maxn] = {0};
    int n;
    scanf("%d",&n);
    
    int nAge;
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&nAge);
        if (nAge >= 0 && nAge <= 50)
        {
            age[nAge]++;
        }
    }
    
    for (int i = 0; i <= 50; i++)
    {
        if (age[i] != 0)
        {
            printf("%d:%d\n", i, age[i]);
        }
    }
    return 0;
}
