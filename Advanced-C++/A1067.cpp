#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100100;

int main()
{
    int n;
    int x;
    int arr[maxn] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        arr[x] = i;
    }

    int now = 0;
    int cnt = 0;
    while(1)
    {
        while (arr[0] != 0)
        {
            swap(arr[0], arr[arr[0]]);
            cnt++;
        }

        while (now < n && arr[now] == now)
        {
            now++;
        }

        if (now == n)
        {
            break;
        }
        
        swap(arr[now], arr[0]);
        cnt++;
    }

    printf("%d", cnt);
    return 0;
}