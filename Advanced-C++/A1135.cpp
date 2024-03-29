/**
 * 红黑树的 5 个特性
 * 1. 每个节点不是红就是黑
 * 2. 根节点是黑的
 * 3. 每个叶节点是黑的
 * 4. 如果一个节点是红的，那么它的孩子是黑的
 * 5. 对于每个节点，所有从当前节点到叶节点的路径中包含相同个数的给黑色节点。
 * 
*/

/**
 * Solution:
 *  红黑树是一个二叉搜索树
 *  判断一个节点起到已该节点为跟的所有叶节点的路径中黑色节点个数相等
 *  红黑树中父子两个节点不能都是红色
*/

#include <cstdio>

const int maxn = 40;

struct RedBlackTree
{
    int type;
    int data;
    RedBlackTree* left, *right;
    RedBlackTree(int v) : data(v), left(nullptr), right(nullptr){}
};

int getAbsolute(int v)
{
    return v > 0 ? v : -v;
}

void createRedBlackTree(RedBlackTree* &root, int v)
{
    if(root == nullptr) {
        root = new RedBlackTree(v);
        return;
    }
    
    if(getAbsolute(v) > getAbsolute(root->data)) {
        createRedBlackTree(root->right, v);
    }
    else if(getAbsolute(v) < getAbsolute(root->data)){
        createRedBlackTree(root->left, v);
    }
}

int judgeBlockNodeTree(RedBlackTree* root, int parent_data)
{
    if(root == nullptr) {
        return 0;
    }

    if(root->data < 0 && parent_data < 0) {
        return -1;
    }

    int number_left_black_node = judgeBlockNodeTree(root->left, root->data);
    int number_right_black_node = judgeBlockNodeTree(root->right, root->data);

    if(number_right_black_node == -1 || number_right_black_node == -1) {
        return -1;
    }

    if( number_left_black_node != number_right_black_node) {
        return -1;
    }

    return root->data > 0 ? 1 + number_left_black_node : number_left_black_node;
}

bool isRedBalckTree(RedBlackTree* root)
{
    if(root->data < 0) {
        return false;
    }

    int number_left_black_node = judgeBlockNodeTree(root->left, root->data);
    int number_right_black_node = judgeBlockNodeTree(root->right, root->data);

    if(number_left_black_node == -1 || number_right_black_node == -1) {
        return false;
    }

    if( number_left_black_node != number_right_black_node) {
        return false;
    }

    return true;
}

int main()
{
    int k, n;
    scanf("%d", &k);

    for(int i = 0; i < k; ++i) {
        RedBlackTree* root = nullptr;

        scanf("%d", &n);
        int v;
        for(int j = 0; j < n; ++j) {
            scanf("%d", &v);
            createRedBlackTree(root, v);
        }

        if(isRedBalckTree(root)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}

/**
1
9
11 -2 1 -7 5 -4 8 14 -15
*/