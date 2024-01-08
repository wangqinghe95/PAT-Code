#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 110;
int n;

struct Node
{
    int data;
    int lChild, rChild;
}node[maxn];

int in[maxn] = {0};

void inOrder(int index)
{
    if(-1 == index) {
        return;
    }

    inOrder(node[index].lChild);
    static int number = 0;
    node[index].data = in[number++];
    inOrder(node[index].rChild);
}

void BFS(int index)
{
    int cnt = 0;
    queue<int> q;
    q.push(index);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        printf("%d%c", node[now].data, cnt < n-1 ? ' ' : '\n');
        cnt++;
        if(node[now].lChild != -1) {
            q.push(node[now].lChild);
        }

        if(node[now].rChild != -1) {
            q.push(node[now].rChild);
        }
    }
    
}

int main()
{

    scanf("%d", &n);

    int lchild, rchild;
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &lchild, &rchild);
        node[i].lChild = lchild;
        node[i].rChild = rchild;
    }

    for(int i = 0; i < n; ++i) {
        scanf("%d",&in[i]);
    }

    sort(in, in+n);

    inOrder(0);
    BFS(0);

    return 0;
}