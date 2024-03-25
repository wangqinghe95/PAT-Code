#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

const int maxn = 10000;

int G[maxn][maxn] = {0};
vector<int> g_vec_lines[maxn];

bool vis[maxn] = {false};
vector<int> path, temp_path;

int g_path_transfer_times;

int st, ed;

int calculateTransferTimes(const vector<int>& vec)
{
    int transfer_times = 0;
    int pre_line = -1;
    for(int i = 1; i < vec.size(); ++i) {
        if(G[vec[i]][vec[i-1]] != pre_line) {
            transfer_times++;
            pre_line = G[vec[i]][vec[i-1]];
        }
    }

    return transfer_times;
}

void DFS(int v)
{
    if(v == ed) {
        if(path.size() == 0) {
            path = temp_path;
            g_path_transfer_times = calculateTransferTimes(temp_path);
            return;
        }

        if( temp_path.size() <= path.size()) {
            int tmp_transfer_times = calculateTransferTimes(temp_path);

            if(temp_path.size() < path.size()) {
                path = temp_path;
                g_path_transfer_times = tmp_transfer_times;
            }
            else if(temp_path.size() == path.size() && tmp_transfer_times < g_path_transfer_times) {
                path = temp_path;
                g_path_transfer_times = tmp_transfer_times;                    
            }
        }
        return;
    }

    for(int i = 0 ; i < g_vec_lines[v].size(); ++i) {
        int cur_v = g_vec_lines[v][i];
        if(false == vis[cur_v]) {
            temp_path.push_back(cur_v);
            vis[cur_v] = true;
            DFS(cur_v);

            temp_path.pop_back();
            vis[cur_v] = false;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int m, pre, v;
    for(int i = 1; i <= n; ++i) {
        scanf("%d%d", &m, &pre);
        for(int j = 1; j < m; ++j) {
            scanf("%d", &v);
            G[pre][v] = G[v][pre] = i;
            g_vec_lines[pre].push_back(v);
            g_vec_lines[v].push_back(pre);

            pre = v;
        }
    }

    int k;
    scanf("%d", &k);

    for(int i = 0; i < k; ++i) {
        scanf("%d%d", &st, &ed );

        memset(vis, 0, sizeof(vis));
        path.clear();
        temp_path.clear();

        temp_path.push_back(st);
        vis[st] = 1;
        DFS(st);

        printf("%d\n", path.size() - 1);

        int pre_line = -1;
        int pre_transfet_stops = st;

        for(int j = 1; j < path.size(); ++j) {
            int cur_line = G[path[j]][path[j-1]];
            if(cur_line != pre_line) {
                if(pre_line != -1) {
                    printf("Take Line#%d from %04d to %04d.\n", pre_line, pre_transfet_stops, path[j-1]);
                }
                pre_line = cur_line;
                pre_transfet_stops = path[j-1];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n", pre_line, pre_transfet_stops, ed);
    }
    return 0;
}