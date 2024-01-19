#include <iostream>

using namespace std;

int main()
{
    int n;
    long long sum = 0;
    double tmp;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i)
    {
        scanf("%lf", &tmp);
        sum += (long long)(tmp*1000) * i * (n-i+1);
    }

    printf("%.1f", (double)sum/1000);

    return 0;
}