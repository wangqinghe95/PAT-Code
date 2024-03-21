/**
 * 何时输入 ()
 * 根节点无需，叶节点无需
 * 非根节点，非叶节点都需要打印左右括号，即深度大于 1，且有孩子的节点
*/

#include <cstdio>

const int maxn = 25;

struct Node
{
    char data[15];
    int left, right;
}node[maxn];

bool isNotRoot[maxn] = {0};

void InOrder(int root, int depth)
{
    if(root == -1){
        return;
    }

    if(node[root].left == -1 && node[root].right == -1) {
        printf("%s", node[root].data);
    }
    else {
        if(depth > 1) {
            printf("(");
        }

        InOrder(node[root].left, depth+1);
        printf("%s", node[root].data);
        InOrder(node[root].right, depth+1);

        if(depth > 1) {
            printf(")");
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 1; i <= n; ++i) {
        getchar();
        scanf("%s %d %d", node[i].data, &node[i].left, &node[i].right);
        isNotRoot[node[i].left] = 1;
        isNotRoot[node[i].right] = 1;
    }

    int index_root = -1;
    for(int i = 1; i <= n; ++i) {
        if(isNotRoot[i] == 0) {
            index_root = i;
            break;
        }
    }

    InOrder(index_root, 1);
    
    return 0;
}
