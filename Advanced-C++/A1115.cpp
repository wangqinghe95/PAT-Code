#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int maxn = 1010;

struct Node
{
    int x;
    Node* left = nullptr;
    Node* right = nullptr;
};

void insert(Node* &node, int v)
{
    if(node == nullptr) {
        node = new Node;
        node->x = v;
        return ;
    }
    if(node->x >= v) {
        insert(node->left, v);
    }
    else {
        insert(node->right, v);
    }
}

namespace Solution_BFS
{

    vector<int> layer_cnt;

    void BFS(Node* root)
    {
        queue<Node*> q;
        q.push(root);

        Node* last_node = root;
        Node* cur_node = root;
        int node_cnt = 0;

        while (!q.empty())
        {
            Node* now = q.front();
            node_cnt++;
            q.pop();
            if(now->left != nullptr) {
                q.push(now->left);
                cur_node = now->left;
            }
            if(now->right != nullptr) {
                q.push(now->right);
                cur_node = now->right;
            }

            if(now == last_node) {
                layer_cnt.push_back(node_cnt);
                node_cnt = 0;
                last_node = cur_node;
            }
        }
        
    }
    void Solution(Node* root)
    {

        BFS(root);

        int n2 = layer_cnt[layer_cnt.size()-2];
        int n1 = layer_cnt[layer_cnt.size()-1];
        printf("%d + %d = %d\n", n1, n2, n1+n2);
    }
}

namespace Solution_DFS
{
    int num_level[maxn] = {0};
    int max_level = -1;
    void DFS(Node* node, int level)
    {
        if(node == nullptr) {
            return;
        }
        num_level[level]++;
        if(level > max_level){
            max_level = level;
        }

        DFS(node->left, level+1);
        DFS(node->right, level+1);
    }
    void Solution(Node* root)
    {
        DFS(root,1);
        printf("%d + %d = %d\n", num_level[max_level], num_level[max_level-1], num_level[max_level] + num_level[max_level-1]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Node* root = nullptr;
    int v;
    for(int i = 0; i < n; ++i){
        scanf("%d",&v);
        insert(root,v);
    }

    // Solution_BFS::Solution(root);
    Solution_DFS::Solution(root);

    return 0;
}