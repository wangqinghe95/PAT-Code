#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

int arr[maxn] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr+1, arr+n+1, cmp);

    int E = 1;
    while (E <= n && arr[E] > E)
    {
        E++;
    }

    printf("%d", E-1);
    return 0;    
}