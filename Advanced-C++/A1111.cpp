#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 510;
const int INF = 1000000000;

int n,m;
int st, ed;
int g_cost_length[maxn][maxn];
int g_cost_time[maxn][maxn];

int d[maxn];
int t[maxn];
bool vis[maxn] = {false};

int n_min_time_cost =  INF;
int n_min_length_cost = INF;

vector<int> pre_length[maxn], pre_time[maxn];

vector<int> path_dis, path_time ,temp;

void Dijkstra_Dis(int s);
void DFS_Dis(int v);
void Dijkstra_Time(int s);
void DFS_Time(int v);

int main()
{
    fill(g_cost_length[0], g_cost_length[0]+maxn*maxn, INF);
    fill(g_cost_time[0], g_cost_time[0]+maxn*maxn, INF);

    scanf("%d%d",&n, &m);
    int v1, v2;
    int n_one_way;
    for(int i = 0 ; i < m; ++i) {
        scanf("%d %d", &v1, &v2);
        scanf("%d %d %d", &n_one_way, &g_cost_length[v1][v2], &g_cost_time[v1][v2]);
        if(0 == n_one_way) {
            g_cost_length[v2][v1] = g_cost_length[v1][v2];
            g_cost_time[v2][v1] = g_cost_time[v1][v2];
        }
    }

    scanf("%d%d",&st, &ed);

    Dijkstra_Dis(st);
    DFS_Dis(ed);

    temp.clear();

    Dijkstra_Time(st);
    DFS_Time(ed);

    if(path_dis == path_time) {
        printf("Distance = %d; Time = %d: ", d[ed], t[ed]);
        for(int i = path_dis.size()-1; i >= 0; --i){
            printf("%d", path_dis[i]);
            if( i > 0) {
                printf(" -> ");
            }
        }
        printf("\n");        
    }
    else {
        printf("Distance = %d: ", d[ed]);
        for(int i = path_dis.size()-1; i >= 0; --i){
            printf("%d", path_dis[i]);
            if( i > 0) {
                printf(" -> ");
            }
        }
        printf("\n");
        printf("Time = %d: ", t[ed]);
        for(int i = path_time.size()-1; i >= 0; --i){
            printf("%d", path_time[i]);
            if( i > 0) {
                printf(" -> ");
            }
        }
        printf("\n");
    }

    return 0;

}

void Dijkstra_Dis(int s)
{
    fill(d,d+maxn, INF);
    memset(vis, 0, sizeof(vis));

    d[s] = 0;
    for(int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && d[j] < min) {
                u = j;
                min = d[j];
            }
        }

        if(-1 == u) return;
        vis[u] = true;

        for(int v = 0; v < n; v++) {
            if(vis[v] == false && g_cost_length[u][v] != INF) {
                if(d[v] > d[u] + g_cost_length[u][v]) {
                    d[v] = d[u] + g_cost_length[u][v];
                    pre_length[v].clear();
                    pre_length[v].push_back(u);
                }
                else if(d[v] == d[u] + g_cost_length[u][v]) {
                    pre_length[v].push_back(u);
                }
            }
        }
    }
}

void DFS_Dis(int v)
{
    if(v == st) {
        temp.push_back(v);
        int n_tmp_time_cost = 0;
        for(int i = temp.size() - 1; i > 0; --i) {
            int id = temp[i];
            int id_next = temp[i-1];
            n_tmp_time_cost += g_cost_time[id][id_next];
        }

        if(n_min_time_cost > n_tmp_time_cost) {
            n_min_time_cost = n_tmp_time_cost;
            path_dis = temp;
        }
        temp.pop_back();
        return;
    }

    temp.push_back(v);
    for(int i = 0; i < pre_length[v].size(); ++i) {
        DFS_Dis(pre_length[v][i]);
    }

    temp.pop_back();
}

void Dijkstra_Time(int s)
{
    fill(t,t+maxn, INF);
    memset(vis, 0, sizeof(vis));

    t[s] = 0;
    for(int i = 0; i < n; ++i) {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++) {
            if(vis[j] == false && t[j] < min) {
                u = j;
                min = d[j];
            }
        }

        if(-1 == u) return;
        vis[u] = true;

        for(int v = 0; v < n; v++) {
            if(vis[v] == false && g_cost_time[u][v] != INF) {
                if(t[v] > t[u] + g_cost_time[u][v]) {
                    t[v] = t[u] + g_cost_time[u][v];
                    pre_time[v].clear();
                    pre_time[v].push_back(u);
                }
                else if(t[v] == t[u] + g_cost_time[u][v]) {
                    pre_time[v].push_back(u);
                }
            }
        }
    }    
}
void DFS_Time(int v)
{
    if(v == st) {
        temp.push_back(v);
        if(path_time.size() == 0 || temp.size() < path_time.size()){
            path_time = temp;
        }
        temp.pop_back();
        return;
    }

    temp.push_back(v);
    for(int i = 0; i < pre_time[v].size(); ++i) {
        DFS_Time(pre_time[v][i]);
    }

    temp.pop_back();
}