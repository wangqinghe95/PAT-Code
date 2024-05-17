/**
 * 不能跑通，NA，Not a TS cycle
 * 能跑通，首尾一致， 所有的点都访问到了 ，size==n+1 ， 是一个 TS simple cycle
 * 能跑通，首尾一致，  所有的点都访问到了，是一个 TS cycle
 * 能跑通，首位一致， 即没有访问到所有的点，Not a TS cycle
 * 能跑通，首尾不一致，  但是所有的点都访问到了， Not a TS cycle
*/
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 210;
const int INF = 1000000000;

int G[maxn][maxn] = {0};

namespace version_1
{
/**
 * -1: 表示路不通
 * 1： 表示路通
 * 2：表示路通，且首位一致
*/
int judgePath(vector<int>& path, int& distance)
{
    // 判断是否联通
    int pre_city_index = path[0];
    for(int i = 1; i < path.size(); ++i) {
        int current_index = path[i];
        if(G[pre_city_index][current_index] != INF) {
            distance += G[pre_city_index][current_index];
        }
        else {
            return -1;
        }
        pre_city_index = current_index;
    }

    // 判断是否首位一致
    if(path[path.size()-1] == path[0]) {
        return 2;
    }
    else {
        return 1;
    }

    // 判断所有的点是否已经被访问到

}

/**
 * -1: 表示有点未访问
 * 1: 表示所有点都访问到了
*/
int judgeAllCityVisited(vector<int>& hash, int &n)
{
    for(int i = 1; i <= n; ++i) {
        if(hash[i] == 0) {
            return -1;
        }
    }
    
    return 1;
}

void Solution_1()
{
   int n, m;
    scanf("%d%d", &n, &m);

    fill(G[0], G[0]+maxn*maxn,INF);

    int c1, c2, dis;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d%d", &c1, &c2, &dis);
        G[c1][c2] = G[c2][c1] = dis;        
    }

    int k;
    int min_cycle_index = -1;
    int min_cycle_distance = INF;
    scanf("%d", &k);
    for(int i = 1; i <= k; ++i) {
        int n_size;
        scanf("%d", &n_size);
        vector<int> path(n_size);
        vector<int> hash(n_size+1,0);
        for(int j = 0; j < n_size; ++j) {
            scanf("%d", &path[j]);
            hash[path[j]]++;
        }

        int distance = 0;

        int res1 = judgePath(path, distance);
        int res2 = judgeAllCityVisited(hash, n);
        if(res1 == -1) {
            printf("Path %d: NA (Not a TS cycle)\n", i);
        }
        else if(res1 == 1){
            if(res2 == 1) {
                printf("Path %d: %d (Not a TS cycle)\n", i, distance);
            }
        }
        else {
            if(res2 == 1) {
                if(path.size() == n+1) {
                    printf("Path %d: %d (TS simple cycle)\n", i, distance);
                }
                else {
                    printf("Path %d: %d (TS cycle)\n", i, distance);
                }
                if(min_cycle_distance > distance) {
                    min_cycle_index = i;
                    min_cycle_distance = distance;
                }
            }
            else {
                printf("Path %d: %d (Not a TS cycle)\n", i, distance);
            }
        }
    }

    printf("Shortest Dist(%d) = %d\n", min_cycle_index, min_cycle_distance);    
}
}

int main()
{
    version_1::Solution_1();
    return 0;
}