// https://www.cnblogs.com/wanghao-boke/p/11794260.html

#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;

int G[maxn][maxn];
bool vis[maxn];
int n,m;

int BFS(int v);

int main()
{
	scanf("%d%d",&n,&m);
	int u,v;
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d: ",i);
		memset(vis,0,sizeof(vis));
		int count = BFS(i);
		double ratio = count * 100.0 / n;
		printf("%.2f%%\n",ratio);
	}
	return 0;
}

int BFS(int v)
{
	queue<int> q;
	vis[v] = true;
	q.push(v);
	int last = v;	//该层结束的判断 
	int tail;		//每层最后一个元素 
	int level = 0;
	int count = 1;
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && G[now][i] == 1)
			{
				vis[i] = true;
				q.push(i);
				count++;
				tail = i;
			}
		}
		
		if (now == last)
		{
			last = tail;
			level++;
		}
		
		if (level == 6)
		{
			return count;
		}
	}
}

