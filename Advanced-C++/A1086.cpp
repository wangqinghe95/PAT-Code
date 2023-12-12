/**
 * 用 stack 的进出栈模拟树的中序遍历，暗含了前序和中序的遍历
 * 即能使用树的中序和先序遍历确定唯一的一棵树
*/

#include <iostream>
#include <cstring>
#include <stack>

using std::stack;

const int MAXN = 35;
int pre[MAXN];
int in[MAXN];
int n;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* createTree(int preL, int preR, int inL, int inR)
{
    if(preL > preR) return NULL;

    Node* root = new Node;
    root->data = pre[preL];

    int k;
    for(k = inL; k <= inR; k++) {
        if(in[k] == pre[preL]){
            break;
        }
    }

    int numLeft = k - inL;
    root->left = createTree(preL+1, preL+numLeft, inL, k-1);
    root->right = createTree(preL+numLeft+1, preR, k+1, inR);
    return root;
}

void postTraversal(Node* root)
{
    if(root == NULL){
        return;
    }

    postTraversal(root->left);
    postTraversal(root->right);
    printf("%d",root->data);
    static int num = 0;
    num++;
    if(num < n) {
        printf(" ");
    }
}

int main()
{
    scanf("%d\n",&n);

    stack<int> st;
    int preIndex = 0, inIndex = 0;
    int x;
    for(int i = 0; i < n*2; ++i) {
        char str[10] = {0};
        scanf("%s",str);
        if(strcmp(str,"Push") == 0) {
            scanf("%d", &x);
            st.push(x);
            pre[preIndex++] = x;
        }
        else if(strcmp(str, "Pop") == 0) {
            in[inIndex++] = st.top();
            st.pop();
        }
        else {

        }
    }

    Node* root = createTree(0, n-1, 0, n-1);
    postTraversal(root);

    return 0;
}