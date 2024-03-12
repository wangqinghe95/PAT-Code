#include <cstdio>

const int maxn = 550;

int G[maxn][maxn] = {0};
int V[maxn] = {0};
bool vis[maxn] = {0};
int cnt = 0;
int n,m;

void DFS(int v) {
    vis[v] = 1;
    cnt++;
    for(int i = 1; i <= n; ++i) {
        if(!vis[i] && G[v][i] == 1) {
            DFS(i);
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);

    int v1, v2;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
        V[v1]++;
        V[v2]++;
    }

    int num_odd = 0;
    for(int i = 1; i <= n; ++i) {
        printf("%d%c", V[i], i!=n?' ' : '\n');

        if(V[i] % 2 != 0) {
            num_odd++;
        }
    }

    DFS(1);

    if(cnt != n) {
        printf("Non-Eulerian\n");
        return 0;
    }

    if(num_odd == 0) {
        printf("Eulerian\n");
    }
    else if(num_odd == 2) {
        printf("Semi-Eulerian\n");
    }
    else {
        printf("Non-Eulerian\n");
    }

    return 0;
}