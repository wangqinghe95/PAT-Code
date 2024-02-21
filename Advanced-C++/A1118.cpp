#include <cstdio>

const int maxn = 10010;

int g_trees[maxn] = {0};
int g_birds[maxn] = {0};
int father[maxn] = {0};     // Union set

void init(int n);
int findFather(int x);
void Union(int a, int b);

int main()
{
    int n;
    scanf("%d", &n);

    init(n);

    int k;
    int x1, x;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &k);
        scanf("%d", &x1);
        g_birds[x1] = 1;

        for(int j = 0; j < k-1; j++) {
            scanf("%d", &x);
            g_birds[x] = 1;
            Union(x1, x);
        }
    }

    int num_trees = 0;
    int num_birds = 0;
    for(int i = 0; i < maxn; ++i) {
        if(g_birds[i] == 1) {
            int fa = findFather(i);
            g_trees[fa]++;
            num_birds++;
        }
    }

    for(int i = 0; i < maxn; ++i) {
        if(g_trees[i] != 0) {
            num_trees++;
        }
    }

    printf("%d %d\n", num_trees, num_birds);
    
    int quiry = 0;
    scanf("%d", &quiry);
    int b1, b2;
    for(int i = 0; i < quiry; ++i) {
        scanf("%d %d", &b1, &b2);
        if(findFather(b1) != findFather(b2)) {
            printf("No\n");
        }
        else {
            printf("Yes\n");
        }
    }

    return 0;
}

void init(int n)
{
    for(int i = 0; i <= maxn; ++i) {
        father[i] = i;
    }
}

int findFather(int x)
{
    int f = x;
    while (f != father[f])
    {
        f = father[f];
    }

    while (x != father[x])
    {
        int z = x;
        x = father[x];
        father[z] = f;
    }
    
    return f;
}

void Union(int a, int b)
{
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa != fb) {
        father[fa] = fb;
    }
}