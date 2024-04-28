#include <cstdio>
#include <vector>
const int maxn = 10010;

using namespace std;

// int G[maxn][maxn] = {0};
// int inDegree[maxn] = {0};


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);

    vector<int> inDegree(n+1);
    vector<vector<int>> G(n+1);

    int v1, v2;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1].push_back(v2);
        inDegree[v2]++;
    }

    int k;
    scanf("%d", &k);
    vector<int> results;
    for(int i = 0; i < k; ++i) {
        bool flag = true;
        vector<int> tempDegree = inDegree;
        
        for(int j = 0; j < n; ++j) {
            scanf("%d", &v1);
            if(flag == false) continue;
            if(tempDegree[v1] != 0) {
                flag = false;
                continue;
            }
            for(int u = 0; u < G[v1].size(); ++u) {
                int v = G[v1][u];
                tempDegree[v]--;
            }
        }
        if(flag == false) results.push_back(i);
    }

    for(int i = 0; i < results.size(); ++i) {
        printf("%d%c", results[i], i != results.size() - 1 ? ' ' : '\n');
    }

    return 0;
}