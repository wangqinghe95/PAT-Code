// https://www.cnblogs.com/wanghao-boke/p/11802107.html

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 550;
const int INF = 100000000;

int G[maxn][maxn],cost[maxn][maxn];
int d[maxn],c[maxn];
bool vis[maxn] = {0};
int n,m,st,ed;

void Dijkstra(int s);

int main()
{
	int u,v;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	fill(G[0],G[0]+maxn*maxn,INF);
	
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	
	Dijkstra(st);
	
	printf("%d %d",d[ed],c[ed]);
	return 0;	
}

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	d[s] = 0;
	c[s] = 0;
	
	for (int i = 0; i < n; i++)
	{
		int u = -1, min = INF;
		for (int j = 0; j < n; j++)
		{
			if (!vis[j] && d[j] < min)
			{
				u = j;
				min = d[j];
			}
		}
		
		if (-1 == u)
		{
			return;
		}
		vis[u] = true;
		
		for (int v = 0; v < n; v++)
		{
			if (!vis[v] && G[u][v] != INF)
			{
				if (d[v] > G[u][v] + d[u])
				{
					d[v] = G[u][v] + d[u];
					c[v] = cost[u][v] + c[u];
				}
				else if(d[v] == G[u][v] + d[u])
				{
					if (c[v] > cost[u][v] + c[u])
					{
						c[v] = cost[u][v] + c[u];
					}
				}
			}
		}
	}
}
