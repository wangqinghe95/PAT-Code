#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 110;
int generation[maxn] = {0};

struct Node
{
    int level;
    vector<int> childs;
}tree[maxn];


void BFS(int s)
{
    queue<int> que;
    que.push(s);
    tree[s].level = 1;

    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        if(tree[top].childs.size() != 0) {
            for(int i = 0; i < tree[top].childs.size(); ++i) {
                int child_idx = tree[top].childs[i];
                tree[child_idx].level = tree[top].level + 1;
                que.push(child_idx);
            }
        }
    }
    
}

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < m; ++i) {
        int num = 0;
        int idx = 0;
        scanf("%d%d",&idx,&num);
        for(int j = 0; j < num; ++j) {
            int child_idx;
            scanf("%d",&child_idx);
            tree[idx].childs.push_back(child_idx);
        }
    }

    BFS(1);

    int generation_maxn = 0;
    int max_index = -1;
    for(int i = 1; i <= n; ++i) {
        generation[tree[i].level]++;
        if(generation_maxn < generation[tree[i].level]) {
            generation_maxn = generation[tree[i].level];
            max_index = tree[i].level;
        }
    }

    printf("%d %d\n", generation_maxn, max_index);
    return 0;
}