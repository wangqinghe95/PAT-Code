#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;

struct Moon
{
    double store;
    double total;
    double price;
}moon[maxn];

bool cmp(Moon a, Moon b);

int main()
{
    int n;
    double D;
    scanf("%d%lf", &n, &D);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &moon[i].store);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &moon[i].total);
        moon[i].price = moon[i].total / moon[i].store;
    }

    sort(moon, moon+n, cmp);
    
    double tempD = D;
    double profit = 0;
    
    for (int i = 0; i < n; i++)
    {
        if (moon[i].store <= tempD)
        {
            profit += moon[i].total;
            tempD -= moon[i].store;
        }
        else
        {
            profit += tempD * moon[i].price;
            break;
        }
    }

    printf("%.2f", profit);

    return 0;
}

bool cmp(Moon a, Moon b)
{
    return a.price > b.price;
}