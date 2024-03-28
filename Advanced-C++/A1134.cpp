#include <cstdio>
#include <vector>
using namespace std;

const int maxn = 100010;

vector<int> g_vec_vertices[maxn];


int main()
{
    int n,m;
    scanf("%d%d", &n, &m);

    int v1,v2;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        g_vec_vertices[v1].push_back(i);
        g_vec_vertices[v2].push_back(i);
    }

    int k;
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        int nv;
        scanf("%d", &nv);

        bool isVisited[maxn] = {0};

        for(int j = 0; j < nv; ++j) {
            scanf("%d", &v1);
            for(auto x : g_vec_vertices[v1]) {
                if(isVisited[x] == false) {
                    isVisited[x] = true;
                }
            }
        }

        bool  b_all_edges_visited = true;
        for(int j = 0; j < m; ++j) {
            if(isVisited[j] == false) {
                b_all_edges_visited = false;
                break;
            }
        }
        printf("%s\n", b_all_edges_visited == false ? "No" : "Yes");
    }

    return 0;
}