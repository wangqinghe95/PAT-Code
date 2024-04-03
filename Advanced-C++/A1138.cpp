#include <cstdio>

const int maxn = 50010;

int pre[maxn] = {0};
int in[maxn] = {0};
int post[maxn] = {0};

struct Node
{
    int data;
    Node* lchild;
    Node* rchild;
    Node(int v) : data(v), lchild(nullptr), rchild(nullptr) {}
};

Node* createBinaryTree(int preL, int preR, int inL, int inR)
{
    if(preL > preR) {
        return nullptr;
    }

    Node* root = new Node(pre[preL]);

    int k = inL;
    for(; k <= inR; ++k) {
        if(in[k] == pre[preL]) break;
    }

    int number_left = k - inL;
    root->lchild = createBinaryTree(preL+1, preL+number_left, inL, k);  // k 已经默认包含了去掉根节点了，因为从 0 开始的
    root->rchild = createBinaryTree(preL+number_left+1, preR, k+1, inR);

    return root;
}

void postOrder(Node* root)
{
    if(root == nullptr) return;

    static int index = 0;
    postOrder(root->lchild);
    postOrder(root->rchild);
    post[index++] = root->data;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }

    for(int i = 0; i < n; ++i) {
        scanf("%d", &in[i]);
    }

    Node* root = createBinaryTree(0, n-1, 0, n-1);
    postOrder(root);
    printf("%d\n", post[0]);
    return 0;
}