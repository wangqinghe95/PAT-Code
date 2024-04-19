/**
 * 在一个无向图中，clique 被定义为是顶点集合的子集，该集合是中所有顶点都互相连接
 * max clique 是一个顶点集合，该集合中所有顶点都互相连接且定点数最大
*/
#include <cstdio>

const int maxn = 220;
int G[maxn][maxn] = {0};

/**
 * -1: Not a Clique
 * -2: Not Maximal
 * 0: Yes
*/
int judgeVertices(const int* arr, const int size)
{
    for(int i = 0; i < size; ++i) {
        for(int j = i+1; j < size; ++j) {
            if(G[arr[i]][arr[j]] != 1) return -1;
        }
    }

    for(int i = 0; i < maxn; ++i) {
        bool bNotMaximal = true;
        for(int j = 0; j < size; ++j) {
            if(G[arr[j]][i] != 1) {
                bNotMaximal = false;
                break;
            }
        }
        if(bNotMaximal == true) {
            return -2;
        }
    }

    return 0;
}

int main()
{
    int Nv, Ne;
    scanf("%d%d",&Nv, &Ne);

    int v1, v2;
    for(int i = 0; i < Ne; ++i) {
        scanf("%d%d",&v1, &v2);
        G[v1][v2] = G[v2][v1] = 1;
    }

    int m,k;
    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        scanf("%d", &k);
        int arr_query[maxn] = {0};
        for(int j = 0; j < k; ++j) {
            scanf("%d", &arr_query[j]);
        }
        if(judgeVertices(arr_query, k) == 0) {
            printf("Yes\n");
        }
        else if(judgeVertices(arr_query, k) == -1) {
            printf("Not a Clique\n");
        }
        else if (judgeVertices(arr_query, k) == -2) {
            printf("Not Maximal\n");
        }
        else {
            
        }
    }

    return 0;
}

