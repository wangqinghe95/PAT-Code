#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 510;
const int INF = 100000000;

int n,m,st,ed;
int G[maxn][maxn],cost[maxn][maxn];
int d[maxn],minCost = INF;
vector<int> pre[maxn];
vector<int> path,tempPath;
bool vis[maxn] = {0};

void Dijkstra(int s);
void DFS(int v);

int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	fill(G[0],G[0]+maxn*maxn,INF);
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
	
	for(int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d ",path[i]);
	}
	printf("%d %d",d[ed],minCost);
	return 0;
} 

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	d[s] = 0;
	
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
		
		if(-1 == u) return ;
		vis[u] = true;
		
		for(int v = 0; v < n; v++)
		{
			if(!vis[v] && G[u][v] != INF)
			{
				if(d[v] > d[u] + G[u][v])
				{
					d[v] = d[u] + G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if(d[v] == d[u] + G[u][v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
}

void DFS(int v)
{
	if(v == st)
	{
		tempPath.push_back(v);
		int tempCost = 0;
		for(int i = tempPath.size() - 1; i > 0; i--)
		{
			int id = tempPath[i];
			int idNext =  tempPath[i - 1];
			tempCost += cost[id][idNext];
		}
		if(tempCost < minCost)
		{
			minCost = tempCost;
			path = tempPath;
		}
		tempPath.pop_back();
		return ;
	}
	
	tempPath.push_back(v);
	for(int i = 0; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}
