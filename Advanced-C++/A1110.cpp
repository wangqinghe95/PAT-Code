#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

const int maxn = 25;

struct Node
{
    int left, right;
}node[maxn];

bool isNotRoot[maxn] = {false};

/**
 * 孩子节点的索引有可能是两位数
*/
namespace Solution_BFS_ERROR
{
    int getChildIndex(char c)
    {
        if(c >= '0' && c <= '9') {
            return c-'0';
        }
        else {
            return -1;
        }
    }

    int BFS(int root)
    {
        queue<int> q;
        q.push(root);

        bool flag = false;
        int last_index = root;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            last_index = now;
            if(flag && (node[now].left != -1 || node[now].right != -1) ) {
                return -1;
            }

            if(node[now].left != -1 && node[now].right != -1) {
                q.push(node[now].left);
                q.push(node[now].right);
            }
            else if(node[now].left != -1 && node[now].right == -1){
                q.push(node[now].left);
                flag = true;
            }
            else if(node[now].left == -1 && node[now].right != -1){
                return -1;
            }
            else if(node[now].left == -1 && node[now].right == -1) {
                flag = true;
            }
            else {
                // nothing
            }
        }

        return last_index;    
    }

    void Solution()
    {
        int n;
        scanf("%d%*c", &n);

        int root = -1;
        for(int i = 0; i < n; ++i) {
            char l, r;
            scanf("%c %c%*c", &l, &r);
            node[i].left = getChildIndex(l);
            node[i].right = getChildIndex(r);
            isNotRoot[node[i].left] = true;
            isNotRoot[node[i].right] = true;
        }

        for(int i = 0; i < n; ++i) {
            if(isNotRoot[i] == false) {
                root = i;
                break;
            }
        }

        if(n == 1) {
            printf("YES %d\n", root);
            return;
        }

        int last_index = BFS(root);
        if(last_index == -1) {
            printf("NO %d\n", root);
        }
        else {
            printf("YES %d\n", last_index);
        }
    }
}

/**
 * cin 遇到 空格或者换行符会自动中断
 * cin 适用于输入输出数据量不大的场景，即 maxn 在 100 以内的数据
*/
namespace Solution_BFS_Correct
{
    int getChildIndex(const string& str)
    {
        if(str == "-") {
            return -1;
        }
        else {
            return stoi(str);
        }
    }

    int BFS(int root)
    {
        queue<int> q;
        q.push(root);

        bool flag = false;
        int last_index = root;
        while (!q.empty())
        {
            int now = q.front();
            q.pop();

            last_index = now;
            if(flag && (node[now].left != -1 || node[now].right != -1) ) {
                return -1;
            }

            if(node[now].left != -1 && node[now].right != -1) {
                q.push(node[now].left);
                q.push(node[now].right);
            }
            else if(node[now].left != -1 && node[now].right == -1){
                q.push(node[now].left);
                flag = true;
            }
            else if(node[now].left == -1 && node[now].right != -1){
                return -1;
            }
            else if(node[now].left == -1 && node[now].right == -1) {
                flag = true;
            }
            else {
                // nothing
            }
        }

        return last_index;    
    }

    void Solution()
    {
        int n;
        cin >> n;

        string str_lchild, str_rchild;
        for(int i = 0; i < n; ++i) {
            cin >> str_lchild >> str_rchild;
            node[i].left = getChildIndex(str_lchild);
            node[i].right = getChildIndex(str_rchild);
            isNotRoot[node[i].left] = true;
            isNotRoot[node[i].right] = true;
        }
        
        int root_index = -1;
        for(int i = 0; i < n; ++i) {
            if(isNotRoot[i] == false) {
                root_index = i;
                break;
            }
        }

        int last_index = BFS(root_index);
        if(last_index == -1) {
            printf("NO %d\n", root_index);
        }
        else {
            printf("YES %d\n", last_index);
        }

    }
}

/**
 * 完全二叉树
 * 如果是完全二叉树，那么节点的个数 n 和先序遍历得到的最大 index 应该是相等的
*/
namespace Solution_Preorder
{
    int getChildIndex(const string& str)
    {
        if(str == "-") {
            return -1;
        }
        else {
            return stoi(str);
        }
    }

    int max_index = -1;
    int last_v = -1;
    void preOrder(int v, int index)
    {
        if(-1 == v) {
            return;
        }

        if(index > max_index) {
            max_index = index;
            last_v = v;
        }

        preOrder(node[v].left, index*2);
        preOrder(node[v].right, index*2+1);
    }
    void Solution()
    {
        int n;
        cin >> n;

        string str_lchild, str_rchild;
        for(int i = 0; i < n; ++i) {
            cin >> str_lchild >> str_rchild;
            node[i].left = getChildIndex(str_lchild);
            node[i].right = getChildIndex(str_rchild);
            isNotRoot[node[i].left] = true;
            isNotRoot[node[i].right] = true;
        }
        
        int root_index = -1;
        for(int i = 0; i < n; ++i) {
            if(isNotRoot[i] == false) {
                root_index = i;
                break;
            }
        }

        preOrder(root_index, 1);
        if(max_index != n) {
            printf("NO %d\n", root_index);
        }
        else {
            printf("YES %d\n", last_v);
        }
    }
}

int main()
{

    // Solution_BFS_Correct::Solution();
    Solution_Preorder::Solution();
    return 0;
}