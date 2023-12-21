/**
 * Solution 1
 * BFS 层次遍历树，然后遍历的时候将树的层次记录
 * 然后再重新访问树结构数组，记录每层树的个数
 * 同时找出一层树个数的层数
*/

/**
 * Solution 2
 * 
 * BFS 层次遍历
 * 但是在层次遍历的同时就统计每层的树节点的个数
 * 并且计算出最大树节点的个数的层数
 * 
*/

/**
 *  Solution 3
 *  DFS 实现层次遍历
 * 
 *  https://www.cnblogs.com/wanghao-boke/p/9293680.html
*/

# if 1
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



#else
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 110;
int generation[maxn] = {0};

struct Node
{
    vector<int> childs;
}tree[maxn];

int max_generation = 0;
int max_index_generation = 0;

void BFS(int s)
{
    queue<int> que;
    que.push(s);

    int last = s;
    int tail = -1;
    int level = 1;
    int count = 0;

    while (!que.empty())
    {
        int top = que.front();
        que.pop();
        count++;

        if(tree[top].childs.size() != 0) {
            for(int i = 0; i < tree[top].childs.size(); ++i) {
                int child_idx = tree[top].childs[i];
                que.push(child_idx);

                tail = child_idx;
            }
        }

        if(top == last) {
            last = tail;
            if(count > max_generation) {
                max_generation = count;
                max_index_generation = level;
            }
            level++;
            count = 0;
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

    printf("%d %d\n", max_generation, max_index_generation);
    return 0;
}
#endif