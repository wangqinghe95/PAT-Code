#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 30;
struct Node
{
    int data;
    int height;
    Node* lchild;
    Node* rchild;
}*root;

void insert(Node* &root, int x);
Node *newNode(int x);
void updateHeight(Node* &root);
int getHeight(Node *root);
int getBalanceFactor(Node *root);
void R(Node* &root);
void L(Node* &root);

int main()
{
    int n;
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        insert(root, x);
    }

    printf("%d", root->data);
    return 0;
}

void insert(Node* &root, int x)
{
    if (root == NULL)
    {
        root = newNode(x);
        return;
    }

    if (root->data > x)
    {
        insert(root->lchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == 2)
        {
            if (getBalanceFactor(root->lchild) == 1)
            {
                R(root);
            }
            else if(getBalanceFactor(root->lchild) == -1)
            {
                L(root->lchild);
                R(root);
            }            
        }
    }
    else
    {
        insert(root->rchild, x);
        updateHeight(root);
        if (getBalanceFactor(root) == -2)
        {
            if (getBalanceFactor(root->rchild) == -1)
            {
                L(root);
            }
            else if (getBalanceFactor(root->rchild) == 1)
            {
                R(root->rchild);
                L(root);
            }
        }
    }    
}

Node *newNode(int x)
{
    Node *root = new Node;
    root->data = x;
    root->height = 1;
    root->lchild = root->rchild = NULL;
    return root;
}

void updateHeight(Node* &root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

int getHeight(Node *root)
{
    if (root != NULL)
    {
        return root->height;
    }
    else
    {
        return 0;
    }   
}

int getBalanceFactor(Node *root)
{
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void R(Node* &root)
{
    Node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void L(Node* &root)
{
    Node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;   
}