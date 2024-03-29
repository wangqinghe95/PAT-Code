// https://www.cnblogs.com/wanghao-boke/p/11827748.html

#include<stdio.h>
#include<queue>
using namespace std;
const int maxn = 110;

int map[maxn][maxn],d[maxn];
int inDegree[maxn];

void init(int n);

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	init(n);
	
	int u,v,w;
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		map[u][v] = w;
		inDegree[v]++;
	}
	
	queue<int> q;
	
	for (int i  = 0; i < n; i++)
	{
		if (!inDegree[i])
		{
			q.push(i);
			d[i] = 0;
		}
	}
	
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		
		for (int i = 0; i < n; i++)
		{
			if (map[cur][i] != -1)
			{
				inDegree[i]--;
				if (d[i] < d[cur] + map[cur][i])
				{
					d[i] = d[cur] + map[cur][i];
				}
				if (!inDegree[i])
				{
					q.push(i);
				}
			}
		}
	}
	
	int maxCost = -1;
	bool flag = true;
	for (int i = 0; i < n; i++)
	{
		if (inDegree[i])
		{
			flag = false;
			break;
		}
		if (d[i] > maxCost)
		{
			maxCost = d[i];
		}
	}
	
	if (flag)
	{
		printf("%d",maxCost);
	}
	else
	{
		printf("Impossible");
	}
	
	return 0;
}

void init(int n)
{
	for (int i = 0 ; i < n; i++)
	{
		d[i] = -1;
		inDegree[i] = 0;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = map[j][i] = -1;
		}
	}
}
