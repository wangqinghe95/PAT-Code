#include <cstdio>

const int maxn = 35;

struct  Node
{
    int data;
    Node* left, *right;
    Node(int v) : data(v), left(nullptr), right(nullptr){};
};

int n;
bool bUnique = true;
int pre[maxn] = {0};
int post[maxn] = {0};

Node* buildTree(int preL, int preR, int postL, int postR)
{
    if(preL > preR) {
        return nullptr;
    }

    Node* root = new Node(pre[preL]);

    int k;
    int num_left = 0;
    for(k = postL; k < postR; ++k) {
        num_left++;
        if(post[k] == pre[preL+1]) {
            break;
        }
    }

    if(postR-1 == k) {  //
        bUnique = false;
    }

    root->left = buildTree(preL+1, preL+num_left, postL, k);
    root->right = buildTree(preL+num_left+1, preR, k+1, postR-1);

    return root;
}

void inOrder(Node* root)
{
    if(root == nullptr) {
        return;
    }

    inOrder(root->left);
    static int cnt = 0;
    cnt++;
    printf("%d%c", root->data, cnt < n ? ' ' : '\n');
    inOrder(root->right);
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &post[i]);
    }

    Node* root = buildTree(0,n-1,0,n-1);
    printf(bUnique ? "Yes\n" : "No\n");

    inOrder(root);

    return 0;
}