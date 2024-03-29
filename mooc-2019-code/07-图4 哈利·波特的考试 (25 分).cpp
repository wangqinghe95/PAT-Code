// https://www.cnblogs.com/wanghao-boke/p/11794553.html

#include<cstdio>
const int maxn = 110;
const int INF = 100000000;

int n,m;
int G[maxn][maxn];

void init();
void Floyd();	

int main()
{
	scanf("%d%d",&n,&m);
	init();	
	
	int u,v,w;	
	for (int i = 0 ; i < m; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		G[u][v] = G[v][u] = w;
	}
	
	Floyd();
	
	int min = INF;
	int minIndex;
	for (int i = 1; i <= n; i++)
	{
		int max = -1;
		for (int j = 1; j <= n; j++)
		{
			if (max < G[i][j])
			{
				max = G[i][j];
			}
		}
		
		if (max == INF)
		{
			printf("0\n");
			return 0;
		}
		
		if (min > max)
		{
			min = max;
			minIndex = i;
		}
	}
	
	printf("%d %d",minIndex,min);
	return 0;
}

void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			G[i][j] = INF;	
		}	
		G[i][i] = 0;
	}	
} 

void Floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (G[i][k] + G[k][j] < G[i][j])
				{
					G[i][j] = G[i][k] + G[k][j];
				}
			}
		}
	}
}
