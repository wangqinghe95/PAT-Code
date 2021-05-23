/*
N 所有成员 id 0 ~ n-1
P 供应商提供的价格
r 每个环节可以提高的价格比率数

K[i] ID[1] ... ID[Ki] 号人表示从第i个供应商或经销商处获取货物

*/

#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn = 100100;
struct Node
{
    double data;
    vector<int> child;
}node[maxn];

double p, r, ans;

void DFS(int index, int depth);

int main()
{
    int n;
    scanf("%d%lf%lf", &n, &p, &r);
    r /= 100;

    int k, child;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (0 == k)
        {
            scanf("%lf", &node[i].data);
        }
        else
        {
            for (int j = 0; j < k; j++)
            {
                scanf("%d", &child);
                node[i].child.push_back(child);
            }
        }        
    }

    DFS(0, 0);

    printf("%.1f", p*ans);
    return 0;
}

void DFS(int index, int depth)
{
    if (node[index].child.size() == 0)
    {
        ans += node[index].data * pow(1+r, depth);
        return;
    }
    for (int i = 0; i < node[index].child.size(); i++)
    {
        DFS(node[index].child[i], depth+1);
    }
}