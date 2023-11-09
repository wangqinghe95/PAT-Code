// https://www.cnblogs.com/wanghao-boke/p/11783776.html

#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 15;
const int INF = 100000000;

bool vis[maxn];
int G[maxn][maxn];

void DFS(int v,int n);
void BFS(int v,int n);

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	fill(G[0], G[0]+maxn*maxn, INF);
	
	for (int i = 0; i < m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		G[u][v] = G[v][u] = 1;
	}
	
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			printf("{");
			DFS(i,n);
			printf(" }\n");
		}
	}
	
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < n; i++)
	{
		if (!vis[i])
		{
			printf("{");
			BFS(i,n);
			printf(" }\n");
		}
	}
}

void DFS(int v,int n)
{
	vis[v] = true;
	printf(" %d",v);
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && G[v][i] == 1)
		{
			DFS(i,n);
		}
	}
}

void BFS(int v,int n)
{
	queue<int> q;
	vis[v] = true;
	printf(" %d",v);
	q.push(v);
	
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		for (int i = 0; i < n; i++)
		{
			if (!vis[i] && G[now][i] == 1)
			{
				vis[i] = true;
				printf(" %d",i);
				q.push(i);
			}
		}
	}
}

