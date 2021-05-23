#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 100000000;

int n,m,st,ed;
int G[maxn][maxn],cost[maxn][maxn];
int d[maxn],c[maxn];
int pre[maxn];
bool vis[maxn] = {0};

void Dijkstra(int s);
void DFS(int v);

int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	fill(G[0],G[0]+maxn*maxn,INF);
	//fill(cost[0],cost[0]+maxn*maxn,INF);
	
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d%d",&G[u][v],&cost[u][v]);
		G[v][u] = G[u][v];
		cost[v][u] = cost[u][v];
	}
	Dijkstra(st);
	DFS(ed);
	
	printf("%d %d",d[ed],c[ed]);
	return 0;
}

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	fill(c,c+maxn,INF);
	d[s] = 0;
	c[s] = 0;
	
	for(int i = 0; i < n; i++)
	{
		int u = -1, MIN = INF;
		for(int j = 0; j < n; j++)
		{
			if(!vis[j] && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		
		if(u == -1) return;
		vis[u] = true;
		
		for(int v = 0; v < n; v++)
		{
			if(!vis[v] && G[u][v] != INF)
			{
				if(d[v] > d[u] + G[u][v])
				{
					d[v] = d[u] + G[u][v];
					c[v] = c[u] + cost[u][v];
					pre[v] = u;
				}
				else if(d[v] == d[u] + G[u][v])
				{
					if(c[v] > c[u] + cost[u][v])
					{
						c[v] = c[u] + cost[u][v];
						pre[v] = u;
					}
				}
			}
		}
	}
}

void DFS(int v)
{
	if(v == st)
	{
		printf("%d ",v);
		return;
	}
	DFS(pre[v]);
	printf("%d ",v);
}
