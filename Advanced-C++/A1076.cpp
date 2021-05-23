/*
计算最大可能转发的数量，只计算L层。
N 用户数  <= 1000    L 计算转发的层数 <= 6
用户ID从1-N
M[i]表示被 user[i]关注的数量
最后一个k表示K个询问数

7 3
3 2 3 4
0
2 5 6
2 3 1
2 3 4
1 4
1 5

2 2 6
用户2 1
用户1 4
用户4 5，6

用户6 3
用户3 1，4，5
用户1 4 用户5 7
*/

#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 1010;
const int INF = 100000000;

vector<int> G[maxn];
bool inq[maxn] = {0};

int BFS(int s, int l);

int main()
{
    int n, l, k;
    scanf("%d%d", &n, &l);

    //fill(G[0], G[0]+maxn*maxn, INF);
    int num_follow = 0;
    int user = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &num_follow);
        for (int j = 0; j < num_follow; j++)
        {
            scanf("%d", &user);
            G[user].push_back(i);
        }
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &user);
        memset(inq, 0 ,sizeof(inq));
        printf("%d\n", BFS(user, l));
    }

    return 0;
}

int BFS(int s, int l)
{
   int numForward = 0; 
   int numLevel = 0;
    int last = s;   //每层结束的判断
    int tail;

   inq[s] = 1;
   queue<int> q;
   q.push(s);
   while( !q.empty())
   {
       int now = q.front();
       q.pop();
       for (int i = 0; i < G[now].size(); i++)
       {
           int next = G[now][i];
           if (inq[next] == false)
           {
                inq[next] = 1;
                numForward++;
                q.push(next);
                tail = next;
           }
       }
        if (now == last)
        {
            numLevel++;
            last = tail;
        }

        if (numLevel == l)
        {
            return numForward;
        }
    }
}
