/*
给一个根为R的非空树，和一个权重为w的节点Ti
从R节点到L节点的路径的权重和被称为R到L路径的权重
*/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 110;

struct Node
{
    int data;
    vector<int> child;
}node[maxn];

int path[maxn] = {0};   //存储路径

//index -- 访问节点数 numNode存储的是path数组的下标
//weight表示当前节点的权重 sum表示走过路径的权重和， s表示要找的权重和
void DFS(int index, int numNode,  int sum, int s);
bool cmp(int a, int b);

int main()
{
    int n, m, s;
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0 ; i < n; i++)
    {
        scanf("%d", &node[i].data);
    }

    int father, child_num, childID;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &father, &child_num);
        for (int j  = 0; j < child_num; j++)
        {
            scanf("%d", &childID);
            node[father].child.push_back(childID);
        }
        sort(node[father].child.begin(), node[father].child.end(), cmp);
    }

    DFS(0, 1, node[0].data, s);
}

bool cmp(int a, int b)
{
    return node[a].data > node[b].data;
}

void DFS(int index, int numNode,  int sum, int s)
{
    if (sum > s)    //加上当前节点的权重超过了s，直接退出
    {
        return ;
    }
    if (sum == s)
    {
        if (node[index].child.size() != 0)
        {
            return;
        }
        for (int i = 0; i < numNode; i++ )
        {
            printf("%d", node[path[i]].data);
            if (i < numNode - 1)
            {
                printf(" ");
            }
            else
            {
                printf("\n");
            }
            
        }
    }

    for (int i = 0; i < node[index].child.size(); i++)
    {
        int child = node[index].child[i];
        path[numNode] = child;
        DFS(child, numNode+1, sum+node[child].data, s);
    }
}
