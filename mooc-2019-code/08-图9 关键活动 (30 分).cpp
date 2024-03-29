// https://www.cnblogs.com/wanghao-boke/p/11827697.html

#include<cstdio>
#include<cstring>

const int maxn = 110;
const int INF = 1000000000;

int map[maxn][maxn],d[maxn];
int inDegree[maxn],outDegree[maxn];
int earliest[maxn],latest[maxn];

void init(int n);
int early_time(int n);
int max(int a,int b);
int min(int a,int b);
void late_time(int n,int flag);

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	
	int u,v,w;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d",&u,&v);
		scanf("%d",&map[u][v]);
		inDegree[v]++;
		outDegree[u]++;
	}
	
	int flag = early_time(n);
	
	if (-1 == flag)
	{
		printf("0");
	}
	else
	{
		printf("%d\n",flag);
		late_time(n,flag);
		
		for (int i = 1; i <= n; i++)
		{
			if (earliest[i] != latest[i])
			{
				continue;
			}
			
			for (int j = n; j >= 1; j--)
			{
				if (map[i][j] >= 0 && 
					earliest[j] == latest[j] &&
					map[i][j] == latest[j] - earliest[i])
				{
					printf("%d->%d\n",i,j);
				}
			}	
		}	
	}	
	
	return 0;
}

void init(int n)
{
	for (int i = 1; i <= n; i++)
	{
		inDegree[i] = 0;
		outDegree[i] = 0;
		earliest[i] = 0;
		latest[i] = INF;
		
		for (int j = 1; j <= n; j++)
		{
			map[i][j] = -1;
		}
	}
}

int early_time(int n)
{
	int q[maxn];
	int front = -1;
	int rear = -1;
	int cnt = 0;
	
	for (int i = 1; i <= n; i++)
	{
		if (!inDegree[i])
		{
			q[++rear] = i;
		}
	}
	
	while (front < rear)
	{
		int now = q[++front];
		cnt++;
		for (int i = 1; i <= n; i++)
		{
			if (map[now][i] >= 0)
			{
				inDegree[i]--;
				earliest[i] = max(earliest[i],earliest[now] + map[now][i]);
				if (!inDegree[i])
				{
					q[++rear] = i;
				}
			}
		}
	}
	
	int ans = 0;
	if (cnt != n)
	{
		ans = -1;
	}
	else
	{
		//ans = earliest[0];
		for (int i = 1; i <= n; i++)
		{
			if (ans < earliest[i])
			{
				ans = earliest[i];
			}
		}
	}
	return ans;
}

int max(int a,int b)
{
	return a > b ? a : b;
}

int min(int a,int b)
{
	return a < b ? a : b;
}

void late_time(int n,int x)
{
	int queue[maxn];
	int front = -1;
	int rear = -1;
	
	for (int i = 1; i <= n; i++)
	{
		if (!outDegree[i])
		{
			queue[++rear] = i;
			latest[i] = x;
		}
	}
	
	while (front < rear)
	{
		int now = queue[++front];
		
		for (int i = 1; i <= n; i++)
		{
			if (map[i][now] >= 0)
			{
				outDegree[i]--;
				latest[i] = min(latest[i], latest[now]-map[i][now]);
				if (!outDegree[i])
				{
					queue[++rear] = i;
				}
			}
		}
	}
}
