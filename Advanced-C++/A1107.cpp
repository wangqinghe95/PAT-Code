#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1010;

int father[maxn];
int hobby[maxn] = {0};
int root[maxn] = {0};

bool cmp(int a, int b)
{
    return a > b;
}

void init(int n)
{
    for(int i = 1; i <= n; ++i) {
        father[i] = i;
    }
}

int findFather(int x)
{
    int a = x;
    while (a != father[a])
    {
        a = father[a];
    }

    int f = x;
    while (f != father[f])
    {
        int z = f;
        f = father[f];
        father[f] = a;
    }
    
    return a;
}

void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb) {
        father[fa] = fb;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    init(n);

    for(int i = 1; i <= n; ++i) {
        int k, h;
        scanf("%d:", &k);
        for(int j = 0; j < k; ++j) {
            scanf("%d", &h);

            if(hobby[h] == 0) {
                hobby[h] = i;
            }

            Union(i, findFather(hobby[h]));
        }
    }

    for(int i = 1; i <= n; ++i) {
        root[findFather(i)]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        if(root[i] != 0) {
            ans++;
        }
    }

    printf("%d\n", ans);
    sort(root+1, root+n+1, cmp);
    for(int i = 1; i <= ans; ++i) {
        printf("%d%c", root[i], i < ans ? ' ' : '\n');
    }

    return 0;
}