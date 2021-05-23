#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 1000000000;

int n,m,st,ed;
int weight[maxn],map[maxn][maxn];
int w[maxn],num[maxn];
int d[maxn];
bool vis[maxn] = {0};

void Dijkstra(int s)
{
	fill(d,d+maxn,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	d[s] = 0;
	w[s] = weight[s];
	num[s] = 1;
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
			if(!vis[v] && map[u][v] != INF)
			{
				if(d[v] > d[u] + map[u][v])
				{
					d[v] = d[u] + map[u][v];
					w[v] = w[u] + weight[v];
					num[v] = num[u];
				}
				else if(d[v] == d[u] + map[u][v])
				{
					if(w[v] < w[u] + weight[v])
					{
						w[v] = w[u] + weight[v];
					}
					num[v] += num[u];
				}
			}
		}
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&weight[i]);
	}
	int u,v,s;
	fill(map[0],map[0]+maxn*maxn,INF);
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&u,&v,&s);
		map[u][v] = map[v][u] = s;
	}
	Dijkstra(st);
 	printf("%d %d",num[ed],w[ed]);
 	return 0;
}
