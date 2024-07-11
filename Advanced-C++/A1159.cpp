/**
 * 
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

namespace Solution_1
{


const int maxn = 35;
int g_in_arr[maxn];
int g_post_arr[maxn];
bool g_b_full_tree = true;
int n;

struct Node
{
    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    int depth = 0;
    int left_child_val = 0;
    int right_child_val = 0;
    int parent_val = 0;
    Node(const int v) : val(v) {}
};

Node* g_node_arr[maxn] = {0};

Node* createTree(int inL, int inR, int postL, int postR)
{
    if(inL > inR) return nullptr;

    Node* now = new Node(g_post_arr[postR]);

    int k;
    for(k = 0; k <= inR; k++) {
        if(g_in_arr[k] == g_post_arr[postR]) break;
    } 

    int num_left = k-inL;

    /*
    post    16 7 11 32 28 2 23 8 15
    in      16 23 7 32 11 2 28 15 8
    k = 7 inL = 0   num_left = 7
            (0,6, 0,6)  (8,8,7,7)
    k = 1 inL = 0 num_left = 1
            (0, 0, 0, 0)    (2, 6, 1, 5)
     */
    now->left = createTree(inL, k-1, postL, postL+num_left-1);
    now->right = createTree(k+1, inR, postL+num_left, postR-1);
    return now;
}

void DFS(Node* root, int depth)
{
    if(root == nullptr) return;

    root->depth = depth;
    if(root->left != nullptr) {
        root->left->parent_val = root->val;
        root->left_child_val = root->left->val;
        if(root->right == nullptr) g_b_full_tree = false;
    }

    if(root->right != nullptr) {
        root->right->parent_val = root->val;
        root->right_child_val = root->right->val;
        if(root->left == nullptr) g_b_full_tree = false;
    }

    DFS(root->left, depth+1);
    DFS(root->right,depth+1);

    static int index = 0;
    g_node_arr[index++] = root;
}

int getQuestionType(const string& str_quiry, int& number1, int& number2)
{
    stringstream ss(str_quiry);
    string word;

    int type = 0;
    while (ss >> word)
    {
        if(word[0] >= '0' && word[0] <= '9') {
            if (number1 == 0) number1 = stoi(word);
            else number2 = stoi(word);
        }
        else if(type == 0) {
            if(word == "root") {
                type = 1;
            }
            else if(word == "siblings") {
                type = 2;
            }
            else if(word == "parent") {
                type = 3;
            }
            else if(word == "left") {
                type = 4;
            }
            else if(word == "right") {
                type = 5;
            }
            else if(word == "level") {
                type = 6;
            }
            else if(word == "full") {
                type = 7;
            }
        }
    }

    return type;
    
}

bool isSiblings(int number1, int number2)
{
    for(int i = 0; i < n; ++i) {
        if(g_node_arr[i]->left_child_val == number1
            && g_node_arr[i]->right_child_val == number2)
            return true;
        if(g_node_arr[i]->right_child_val == number1
            && g_node_arr[i]->left_child_val == number2)
            return true;
    }
    return false;
}

bool isSameLevel(int number1, int number2)
{
    int depth_1 = 0;
    int depth_2 = 0;
    for(int i = 0; i < n; ++i) {
        if(g_node_arr[i]->val == number1) depth_1 = g_node_arr[i]->depth;
        if(g_node_arr[i]->val == number2) depth_2 = g_node_arr[i]->depth;
    }
    return depth_1 == depth_2 ;
}

bool isParent(int number1, int number2)
{
    for(int i = 0; i < n; ++i) {
        if(g_node_arr[i]->val == number1) {
            if(g_node_arr[i]->left_child_val == number2 
                || g_node_arr[i]->right_child_val == number2)
                return true;
        }
    }

    return false;
}

bool isLeftChild(int number1, int number2)
{
    for(int i = 0; i < n; ++i) {
        if(g_node_arr[i]->val == number2 && g_node_arr[i]->left_child_val == number1)
            return true;
    }
    return false;
}

bool isRightChild(int number1, int number2)
{
    for(int i = 0; i < n; ++i) {
        if(g_node_arr[i]->val == number2 && g_node_arr[i]->right_child_val == number1)
            return true;
    }
    return false;
}

int Solution()
{
    cin >> n;

    for(int i = 0; i < n; ++i) {
        scanf("%d", &g_post_arr[i]);
    }

    for(int i = 0; i < n; ++i) {
        scanf("%d", &g_in_arr[i]);
    }

    Node* root = nullptr;
    root = createTree(0, n-1, 0, n-1);

    DFS(root, 1);

    int m;
    scanf("%d%*c", &m);
    for(int i = 0; i < m; ++i) {
        string str_quiry;
        getline(cin, str_quiry);

        int num1 = 0, num2 = 0;
        int question_type = getQuestionType(str_quiry, num1, num2);
        switch (question_type)
        {
        case 1:
            printf("%s\n", g_post_arr[n-1] == num1 ? "Yes" : "No");
            break;
        case 2:
            printf("%s\n", isSiblings(num1, num2) ? "Yes" : "No");
            break;
        case 3:
            printf("%s\n", isParent(num1, num2) ? "Yes" : "No");
            break;
        case 4:
            printf("%s\n", isLeftChild(num1, num2) ? "Yes" : "No");
            break;
        case 5:
            printf("%s\n", isRightChild(num1, num2) ? "Yes" : "No");
            break;
        case 6:
            printf("%s\n", isSameLevel(num1, num2) ? "Yes" : "No");
            break;
        case 7:
            printf("%s\n", g_b_full_tree ? "Yes" : "No");
            break;
        default:
            break;
        }
    }

    return 0;
}

}

namespace Solution_2
{
/**
 * 二叉树结构
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

const int maxn = 35;

int postorder[maxn] = {0};
int inorder[maxn] = {0};
bool isFullTree = true;

struct Node
{
    int val;
    int parent_val, left_child_val, right_child_val;
    int level = -1;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int v) : val(v), left(nullptr), right(nullptr), parent_val(-1),left_child_val(-1),right_child_val(-1)  {}
};

Node* tree[maxn];

Node* createBinaryTree(int inL, int inR, int postL, int postR)
{
    if(inL > inR) return nullptr;
    Node* now = new Node(postorder[postR]);

    int k = inL;
    for(; k <= inR; ++k) {
        if(inorder[k] == postorder[postR]) {
            break;
        }
    }

    int numberLeft = k-inL;
    now->left = createBinaryTree(inL, k-1, postL, postL+numberLeft-1);
    now->right = createBinaryTree(k+1, inR, postL+numberLeft, postR-1);

    return now;
}

int getQuestionData(const string& str, int& number1, int& number2)
{
    stringstream ss(str);
    string word;
    int type = 0;
    while (ss >> word)
    {
        if(word[0] >= '0' && word[0] <= '9') {
            if (number1 == 0) number1 = stoi(word);
            else number2 = stoi(word);
        }
        else if(type == 0) {
            if(word == "root") {
                type = 1;
            }
            else if(word == "siblings") {
                type = 2;
            }
            else if(word == "parent") {
                type = 3;
            }
            else if(word == "left") {
                type = 4;
            }
            else if(word == "right") {
                type = 5;
            }
            else if(word == "level") {
                type = 6;
            }
            else if(word == "full") {
                type = 7;
            }
        }
    }

    return type;
}

bool isSiblings(int n, int num1, int num2) 
{
    for(int i = 0; i < n; ++i) {
        if(tree[i]->left_child_val == num1 && tree[i]->right_child_val == num2) {
            return true;
        }
        if(tree[i]->left_child_val == num2 && tree[i]->right_child_val == num1) {
            return true;
        }
    }
    return false;
/*
    if(root == nullptr) return false;
    if(root->left == nullptr || root->right == nullptr) return false;

    if(root->left->val == num1 && root->right->val == num2) {
        return true;
    }
    if(root->left->val == num2 && root->right->val == num1) {
        return true;
    }

    return isSiblings(root->left, num1, num2) ||  isSiblings(root->left, num1, num2);
*/
}

/**
 * index = 3 : child is left or right
 * index = 1 : child is left
 * index = 2 : child is right
*/
bool isParent(int n, int parent, int child, int index)
{
    for(int i = 0; i < n; ++i) {
        if(tree[i]->val == parent) {
            if(tree[i]->left_child_val == child && ((index & 1) == 1)) {
                return true;
            }
            if(tree[i]->right_child_val == child && ((index & 2) == 2)){
                return true;
            }
            return false;
        }
    }
    return false;    
}

bool isParent(const Node* root, int num1, int num2)
{
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr) return false;
    if(root->left != nullptr) {
        if(root->val == num1 && root->left->val == num2) return true;
    }
    if(root->right != nullptr) {
        if(root->val == num1 && root->right->val == num2) return true;
    }
    return isParent(root->left, num1, num2) || isParent(root->right, num1, num2);
}

bool isSameLevel(int n, int num1, int num2)
{
# if 0
    int depth_1 = 0;
    int depth_2 = 0;
    for(int i = 0; i < n; ++i) {
        if(tree[i]->val == num1) depth_1 = tree[i]->level;
        if(tree[i]->val == num2) depth_2 = tree[i]->level;
    }
    return depth_1 == depth_2 ;
# else
    int level1 = -1;
    int level2 = -1;
    for(int i = 0; i < n; ++i) {
        if(level1 != -1 && level2 != -1) break;
        if(tree[i]->val == num1) {
            level1 = tree[i]->level;
        }
        if(tree[i]->val == num2) {
            level2 = tree[i]->level;
        }
    }
    // if(level1 == -1 || level2 == -1) return false;
    // if(level1 != level2) return false;
    // return true;
    return level1 == level2;
#endif 
}

void preTranser(Node* root, int level)
{
    if(root == nullptr) return;
    root->level = level;
    if(root->left != nullptr){
        root->left_child_val = root->left->val;
        root->left->parent_val = root->val;
    }
    if(root->right != nullptr){
        root->right_child_val = root->right->val;
        root->right->parent_val = root->val;
    }

    if(isFullTree == true && ((root->left != nullptr && root->right == nullptr) || (root->left == nullptr && root->right != nullptr) )) {
        isFullTree = false;
    }

    static int index = 0;
    preTranser(root->left, level+1);
    preTranser(root->right, level+1);
    tree[index++] = root;
}

int Solution()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &postorder[i]);
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &inorder[i]);
    }

    Node* root = createBinaryTree(0, n-1, 0, n-1);
    preTranser(root, 0);

    int m;
    scanf("%d%*c", &m);
    while (m--)
    {
        string question;
        getline(cin, question);

        int number1 = 0, number2 = 0;
        int type = getQuestionData(question, number1, number2);
        // printf("\ntype = %d, number1 = %d number2 = %d\n", type, number1, number2);
        switch (type)
        {
        case 1:
        {    
            printf("%s\n", postorder[n-1] == number1 ? "Yes" : "No");
            break;
        }
        case 2:
        {
            printf("%s\n", isSiblings(n, number1, number2) ? "Yes" : "No");
            break;
        }
        case 3:
        {
            printf("%s\n", isParent(n, number1, number2, 3) ? "Yes" : "No");
            break;
        }
        case 4:
        {
            printf("%s\n", isParent(n, number2, number1, 1) ? "Yes" : "No");
            break;
        }
        case 5:
        {
            printf("%s\n", isParent(n, number2, number1, 2) ? "Yes" : "No");
            break;
        }
        case 6:
        {
            printf("%s\n", isSameLevel(n, number2, number1) ? "Yes" : "No");
            break;
        }
        case 7:
        {
            printf("%s\n", isFullTree ? "Yes" : "No");
        }
        
        default:
            break;
        }
    }

    return 0;
}

/*
9
16 7 11 32 28 2 23 8 15
16 23 7 32 11 2 28 15 8
1
It is a full tree
*/
}

int main()
{
    Solution_2::Solution();
    return 0;
}
