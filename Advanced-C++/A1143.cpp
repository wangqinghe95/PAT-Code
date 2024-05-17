#include <cstdio>
#include <map>
using namespace std;

/**
 * 提交结果，三个正确，三个运行超时
 * 思路没问题
 * A1151 通过
 * 三个超时仅仅是因为给的时间是 200ms，要求使用 BST 特性
*/
namespace Solution_1
{

const int maxn = 10010;

struct Node
{
    int data;
    Node* left, *right;
    Node(int key) : data(key), left(nullptr), right(nullptr){}
};


// bool mp[maxn] = {0};
map<int, bool> mp;
int v1, v2;


void createTree(Node* &root, int v)
{
    if(root == nullptr) {
        root = new Node(v);
        return;
    }

    if(v >= root->data) {
        createTree(root->right, v);
    }
    else {
        createTree(root->left, v);
    }
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
    int v;
    Node* root = nullptr;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        createTree(root, v);
        mp[v] = 1;
    }


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

/**
 * 指明了 BST 的最低公共祖先，说明需要用到 BST 的特性
 * 有负数，不能使用数组来做 hashtable
*/
namespace Solution_2
{

const int maxn = 10100;

// bool isExist[maxn] = {0};
map<int, bool> isExist;
int g_tree_nodes[maxn] = {0};

void Solution()
{
    int n,m;
    scanf("%d%d", &m, &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &g_tree_nodes[i]);
        isExist[g_tree_nodes[i]] = true;
    }

    int u,v;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &u,&v);
        if(isExist[v] == false && isExist[u] == false) {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if(isExist[v] == false || isExist[u] == false) {
            printf("ERROR: %d is not found.\n", isExist[u] == false ? u : v);
        }
        else {
            int a;
            for(int j = 0; j < n; ++j) {
                a = g_tree_nodes[j];
                if((a >= u && a <= v) || (a >= v && a <= u)) {
                    break;
                }
            }
            if(a == u || a == v) {
                printf("%d is an ancestor of %d.\n", a, a == u ? v : u);
            }
            else {
                printf("LCA of %d and %d is %d.\n", u, v, a);
            }
        }
    }
}
}

int main()
{

    Solution_1::Solution();
    // Solution_2::Solution();
    return 0;
}