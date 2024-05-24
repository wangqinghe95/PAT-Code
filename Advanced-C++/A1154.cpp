/**
 * 因为颜色的范围是 int 范围内的一个非负整数
 * 所以需要使用 set 类型来统计颜色的种类个数
 * 
 * 不能直接用 vector<vector>> G(N,vector<int>(M)) 这种方式初始化，因为会导致内存超限
 * 
*/

#include <cstdio>
#include <vector>
#include <set>
using namespace std;

namespace Solution_1
{

int N,M;

bool check(vector<vector<int>> &G, vector<int> & color)
{
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < G[i].size(); ++j) {
            int next_node = G[i][j];
            if(color[i] == color[next_node]) {
                return false;
            }
        }
    }

    return true;
}

void Solution()
{
    scanf("%d%d", &N, &M);

    vector<vector<int>> G(N);

    int v1,v2;
    for(int i = 0; i < M; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i) {
        vector<int> check_color(N);

        set<int> hashTable;
        for(int j = 0; j < N; ++j){
            scanf("%d",&check_color[j]);
            hashTable.insert(check_color[j]);
        }

        if(check(G,check_color) == false) {
            printf("No\n");
        }
        else {
            printf("%d-coloring\n", (int)hashTable.size());
        }
    }

}

}

namespace Solution_2
{
const int maxn = 100010;
const int INF = 1000000000;

vector<int> G[maxn];

bool checkColor(vector<int> &checked_color, int v)
{
    for(int i = 0; i < G[v].size(); ++i) {
        int next_node = G[v][i];
        if(checked_color[next_node] == checked_color[v]) {
            return false;
        }
    }
    return true;
}

void solution()
{
    int N, M;
    scanf("%d%d", &N, &M);

    int v1, v2;
    for(int i = 0; i < M; ++i) {
        scanf("%d%d", &v1, &v2);
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    int K;
    scanf("%d", &K);
    for(int i = 0; i < K; ++i) {
        vector<int> checked_color(maxn);    // 不能使用 N 作为容量大小，否则第一个点不过
        set<int> hash_color;
        for(int j = 0; j < N; ++j) {
            scanf("%d", &checked_color[j]);
            hash_color.insert(checked_color[j]);
        }

        int cnt = 0;
        bool flag = true;
        for(int j = 0; j < N; ++j) {
            if(checkColor(checked_color, j) == false) {
                flag = false;
                break;
            } 
        }

        if(flag == false) {
            printf("No\n");
            continue;
        }

        printf("%d-coloring\n", (int)hash_color.size());
    }
}

}

int main()
{
    Solution_1::Solution();
    // Solution_2::solution();
    return 0;
}