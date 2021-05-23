#include<cstdio>
#include<set>
using namespace std;
const int maxn = 55;
set<int> s[maxn];

void compare(int u, int v);

int main()
{
    int n;
    int m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &m);
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &x);
            s[i].insert(x);
        }
    }

    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int u,v;
        scanf("%d%d", &u, &v);
        compare(u,v);
    }
    return 0;
}

void compare(int u, int v)
{
    int totalNum = s[u].size();
    int sameNum = 0;
    for (set<int>::iterator it = s[v].begin(); it != s[v].end(); it++)
    {
        if (s[u].find(*it) != s[u].end())
        {
            sameNum++;
        }
        else
        {
            totalNum++;
        }
    }

    printf("%.1f%%\n", sameNum * 100.0 / totalNum);
}