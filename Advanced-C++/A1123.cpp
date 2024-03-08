#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 25;

struct Node
{
    int data;
    int height;
    Node* left;
    Node* right;
    Node(int v) : data(v), height(1), left(nullptr), right(nullptr){}
};

int n;

void insert(Node* &root, int v);
int getBalanceFactor(Node* root);
int getHeight(Node* root);
void updateHeight(Node* root);
void R(Node* &root);
void L(Node* &root);

void level(Node* root);
void preOrder(Node* root, int indenx);
int max_index = -1;

int main()
{
    scanf("%d", &n);

    int v;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        insert(root, v);;
    }

    level(root);
    preOrder(root, 1);
    if(max_index == n){
        // printf("%d ", max_index);
        printf("YES\n");
    }
    else {
        // printf("%d ", max_index);

        printf("NO\n");
    }

    return 0;
}

void insert(Node* &root, int v)
{
    if(root == nullptr) {
        root = new Node(v);
        return;
    }

    if(root->data > v) {
        insert(root->left, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2) {
            if(getBalanceFactor(root->left) == 1) {
                R(root);
            }
            else if(getBalanceFactor(root->left) == -1) {
                L(root->left);
                R(root);
            }
        }
    }
    else if (root->data < v) {
        insert(root->right, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if(getBalanceFactor(root->right) == -1) {
                L(root);
            }
            else if(getBalanceFactor(root->right) == 1) {
                R(root->right);
                L(root);
            }
        }
    }

}

void updateHeight(Node* root)
{
    int left_height = getHeight(root->left);
    int right_height = getHeight(root->right);

    root->height = left_height > right_height ? left_height + 1 : right_height + 1;
}

int getBalanceFactor(Node* root)
{
    return getHeight(root->left) - getHeight(root->right);
}

int getHeight(Node* root)
{
    if(root == nullptr) {
        return 0;
    }

    return root->height;
}

void R(Node* &root)
{
    Node* tmp = root->left;
    root->left = tmp->right;
    tmp->right = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;

}
void L(Node* &root)
{
    Node* tmp = root->right;
    root->right = tmp->left;
    tmp->left = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void level(Node* root)
{
    queue<Node*> q;
    q.push(root);

    int print_num = 0;
    while (!q.empty())
    {
        Node* now = q.front();
        q.pop();
        printf("%d%c", now->data, ++print_num < n ? ' ' : '\n');

        if(now->left != nullptr) {
            q.push(now->left);
        }
        if(now->right != nullptr) {
            q.push(now->right);
        }
    }
}

void preOrder(Node* root, int index)
{
    if(root == nullptr) {
        return ;
    }

    if(max_index < index) {
        max_index = index;
    }

    preOrder(root->left, index*2);
    preOrder(root->right, index*2+1);
}
