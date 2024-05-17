#include <cstdio>
#include <map>
using namespace std;

namespace Solution_1
{

const int maxn = 10010;

struct Node
{
    int data;
    Node* left, *right;
    Node(int key) : data(key), left(nullptr), right(nullptr){}
};

int preOrder[maxn] = {0};
int inOrder[maxn] = {0};

// bool mp[maxn] = {0};
map<int, bool> mp;
int v1, v2;


Node* createTree(int preL, int preR, int inL, int inR)
{
    if(preL > preR) {
        return nullptr;
    }

    Node* root = new Node(preOrder[preL]);
    int k = inL;
    for(; k <= inR; ++k) {
        if(inOrder[k] == preOrder[preL]) break;
    }

    int numleft = k - inL;
    root->left = createTree(preL+1, preL+numleft, inL, k-1);
    root->right = createTree(preL+numleft+1, preR, k+1, inR);

    return root;
}

Node* DFS(Node* root)
{
    if(root == nullptr || root->data == v2 || root->data == v1) {
        return root;
    }

    Node* left = DFS(root->left);
    Node* right = DFS(root->right);

    if(left != nullptr && right != nullptr) return root;
    return left == nullptr ? right : left;
}


void Solution()
{
    int n,m;
    scanf("%d%d", &m, &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &inOrder[i]);
        mp[inOrder[i]] = true;
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &preOrder[i]);
    }

    Node* root = createTree(0, n-1, 0, n-1);

    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &v1, &v2);
        if(mp[v1] == false && mp[v2] == false) {
            printf("ERROR: %d and %d are not found.\n", v1, v2);
        }
        else if(mp[v1] == false || mp[v2] == false){
            printf("ERROR: %d is not found.\n", mp[v1] == false ? v1 : v2);
        }
        else {
            Node* father = DFS(root);
            if(father->data == v1) {
                printf("%d is an ancestor of %d.\n", v1, v2);
            }
            else if (father->data == v2) {
                printf("%d is an ancestor of %d.\n", v2, v1);
            }
            else {
                printf("LCA of %d and %d is %d.\n", v1, v2, father->data);
            }
        }
    }
}

}

int main()
{
    Solution_1::Solution();
    return 0;
}