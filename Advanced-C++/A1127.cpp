#include <cstdio>
#include <vector>

using std::vector;

const int maxn = 40;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};


int g_arr_inorder[maxn] = {0};
int g_arr_postorder[maxn] = {0};

int n;

Node* buildBinaryTree(int inL, int inR, int postL, int postR)
{
    if(inL > inR) {
        return nullptr;
    }

    Node* root = new Node(g_arr_postorder[postR]);
    int k = inL;
    for(; k <= inR; ++k) {
        if(g_arr_inorder[k] == g_arr_postorder[postR]) {
            break;
        }
    }

    int num_left = k - inL;
    root->left = buildBinaryTree(inL, k-1, postL, postL+num_left-1);
    root->right = buildBinaryTree(k+1, inR, postL+num_left, postR-1);

    return root;
}

vector<int> g_arr_level_data[maxn];
int max_level = -1;
void DFS(Node* root, int depth)
{
    if(root == nullptr){
        return;
    }

    g_arr_level_data[depth].push_back(root->data);
    if(depth > max_level){
        max_level = depth;
    }
    DFS(root->left, depth+1);
    DFS(root->right, depth+1);
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &g_arr_inorder[i]);
    }

    for(int i = 0; i < n; ++i) {
        scanf("%d", &g_arr_postorder[i]);
    }

    Node* root = buildBinaryTree(0, n-1, 0, n-1);

    DFS(root,1);
    printf("%d", g_arr_level_data[1][0]);
    for(int i = 2; i <= max_level; ++i) {
        if(i % 2 == 0) {
            for(int j = 0; j < g_arr_level_data[i].size(); ++j){
                printf(" %d", g_arr_level_data[i][j]);
            }
        }
        else {
            for(int j = g_arr_level_data[i].size() - 1; j >= 0; j--){
                printf(" %d", g_arr_level_data[i][j]);
            }
        }
    }

    printf("\n");
    return 0;
}
