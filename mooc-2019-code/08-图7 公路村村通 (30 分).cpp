// https://www.cnblogs.com/wanghao-boke/p/11827644.html

#include<cstdio>
const int maxn = 1010;
const int INF = 100000000;

int map[maxn][maxn];
int c[maxn];
bool vis[maxn] = {0};


void init(int n);
void prim(int n);

int main()
{
	int n,m;		
	scanf("%d%d",&n,&m);
	
	init(n);
	
	int u,v;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&map[u][v]);
		map[v][u] = map[u][v];
	}
	
	prim(n);
	
	return 0;
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = INF;
		}
		map[i][i] = 0;
	}
}

void prim(int n)
{
	vis[1] = true;
	int sum = 0;
	bool flag = true;
	
	for (int i = 1; i <= n; i++)
	{
		c[i] = map[i][1];
	}
	
	for (int i = 2; i <= n; i++)
	{
		int u = -1, min = INF;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && c[j] < min)
			{
				u = j;
				min = c[j];	
			} 
		}
		
		if (-1 == u)
		{
			flag = false;
			break;
		}
		
		sum += min;
		vis[u] = true;
		
		for (int v = 1; v <= n; v++)
		{
			if (!vis[v] && c[v] > map[u][v])
			{
				c[v] = map[u][v];
			}
		}
	}
	
	if (flag)
	{
		printf("%d",sum);
	}
	else
	{
		printf("-1");
	}
	
	
}
