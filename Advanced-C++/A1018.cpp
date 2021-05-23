#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn = 510;
const int INF = 100000000;

int G[maxn][maxn],weight[maxn];
int cmax,n,sp,m;
bool vis[maxn] = {false};
int d[maxn];  //原点到各点的最短路径 
vector<int> pre[maxn];
vector<int> path,tempPath;
int minRemain = INF,minNeed = INF;

void Dijkstra(int s);
void print(int v);
void DFS(int v); 

int main()
{
	scanf("%d%d%d%d",&cmax,&n,&sp,&m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&weight[i]);
		weight[i] -= cmax/2;
	}
	int u,v;
	fill(G[0],G[0]+maxn*maxn,INF);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u] = G[u][v];
	}
	Dijkstra(0);
	DFS(sp);
	printf("%d ",minNeed);
	for(int i = path.size() - 1; i >= 0; i--)
	{
		printf("%d",path[i]);
		if(i > 0) printf("->");
	}
	printf(" %d",minRemain);
	return 0;
}

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	d[s] = 0;
	for(int i = 0; i <= n; i++)
	{
		int u = -1,MIN = INF;
		for(int j = 0; j <= n; j++)
		{
			if(!vis[j] && d[j] < MIN)
			{
				u = j;
				MIN = d[j];
			}
		}
		if(-1 == u) return;
		vis[u] = true;
		for(int v = 0; v <= n; v++)
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
	if(v == 0)
	{
		tempPath.push_back(v);
		int remain = 0,need = 0;
		for(int i = tempPath.size() - 1; i >= 0; i--)
		{
			int id = tempPath[i];
			if(weight[id] > 0)
			{
				remain += weight[id];
			}
			else
			{
				if(remain > abs(weight[id]))
				{
					remain -= abs(weight[id]);
				}
				else
				{
					need += abs(weight[id]) - remain;
					remain = 0;
				}
			}
		}
		
		if(need < minNeed)
		{
			minNeed = need;
			minRemain = remain;
			path = tempPath;
		}
		else if(need == minNeed && remain < minRemain)
		{
			minRemain = remain;
			path = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i = 0 ; i < pre[v].size(); i++)
	{
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

void print(int v)
{
	for(int i = 0; i < pre[v].size(); i++)
	{
		print(pre[v][i]);
		printf("pre[%d][%d] = %d",v,i,pre[v][i]);
	}
	printf("\n");
}
