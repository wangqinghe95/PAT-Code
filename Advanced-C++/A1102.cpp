#include <cstdio>
#include <queue>

using std::queue;
// using namespace std;

const int maxn = 15;
int visited[maxn] = {false};

struct Node
{
    int left;
    int right;
}node[maxn];

int n;

int getChild(char c) 
{
    if(c >= '0' && c <='9') {
        visited[c-'0'] = true;
        return c-'0';
    }
    else {
        return -1;
    }
}

void postTraverse(int root)
{
    if(-1 == root) {
        return;
    }

    postTraverse(node[root].left);
    postTraverse(node[root].right);

    if(node[root].left == -1 && node[root].right == -1) {
        return;
    }

    int tmp = node[root].left;
    node[root].left = node[root].right;
    node[root].right = tmp;
}

void BFS(int root)
{
    queue<int> q;
    q.push(root);

    int count = 0;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        count++;
        printf("%d%c", now, count < n ? ' ' : '\n');
        if(node[now].left != -1) {
            q.push(node[now].left);
        }
        if(node[now].right != -1) {
            q.push(node[now].right);
        }
    }
}

void inOrder(int index)
{
    if(index == -1) {
        return;
    }

    inOrder(node[index].left);

    static int count = 0;
    count++;
    printf("%d%c", index, count < n ? ' ' : '\n');

    inOrder(node[index].right);
}

int main()
{

    scanf("%d%*c", &n);

    for(int i = 0; i < n; ++i) {
        char l,r;
        scanf("%c %c%*c", &l, &r);
        node[i].left = getChild(l);
        node[i].right = getChild(r);
    }

    int root = -1;
    for(int i = 0; i < n; ++i) {
        if(visited[i] == false) {
            root = i;
            break;
        }
    }

    postTraverse(root);

    BFS(root);
    inOrder(root);

    return 0;
}