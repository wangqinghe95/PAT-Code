#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10;

int dp[maxn] = {0};
int w[maxn] = {0};
bool flag[maxn] = {0};
bool choice[maxn][10] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }

    sort(w+1, w+n+1, cmp);
    for (int i = 1; i <= n; i++)
    {
        for (int v = m; v >= w[i]; v--)
        {
            if(dp[v] <= dp[v - w[i]] + w[i])
            {
                dp[v] = dp[v - w[i]] + w[i];
                choice[i][v] = 1;
            }            
        }
    }

    if (dp[m] != m)
    {
        printf("No Solution\n");
    }
    else
    {
        int k = n;
        int num = 0;
        int v = m;
        while(k >= 0)
        {
            if (choice[k][v] == 1)
            {
                flag[k] = 1;
                num++;
                v -= w[k];
            }
            k--;
        }

        for (int i = n; i >= 1; i--)
        {
            if (flag[i] == 1)
            {
                printf("%d", w[i]);
                num--;
                if (num > 0)
                {
                    printf(" ");
                }
            }
        }
    }
    
    return 0;
}