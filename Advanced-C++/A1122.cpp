#include <cstdio>

using namespace std;

const int maxn = 210;

int G[maxn][maxn] = {0};

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);

    int v1, v2;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int n1;
        scanf("%d", &n1);

        int *cycle_array = new int[n1+1];
        for(int j = 0; j < n1; j++) {
            scanf("%d", &cycle_array[j]);
        }

        if(n1 != n+1 || cycle_array[0] != cycle_array[n1-1]) {
            printf("NO\n");
            continue;
        }
        
        bool flag = true;
        int vis[maxn] = {0};

        // 一个图中有一个包含所有节点的循环
        // 环的个数应该是图的顶点个数+1，环首位数相同，每个顶点访问次数应该是 2，顶点编号范围在 [1,n]
        for(int j = 1; j < n1; ++j) {
            v1 = cycle_array[j-1];
            v2 = cycle_array[j];
            if(vis[v1] > 2 || vis[v2] > 2 || v1 > n || v2 > n || G[v1][v2] != 1) {
                flag = false;
                break;
            }
            vis[v1]++;
            vis[v2]++;
        }
        printf("%s\n", flag == true ? "YES" : "NO");
    }

    return 0;
}