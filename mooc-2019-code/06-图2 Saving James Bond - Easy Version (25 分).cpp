// https://www.cnblogs.com/wanghao-boke/p/11785432.html

#include<cstdio>
#include<cmath>

const int maxn = 110;
const double ISLAND_RADIUS = 15.0/2;
const double DIS_SAVE = 50;

typedef struct Point
{
	double x,y;
}Position;

int n;
double d;
Position P[maxn];
bool vis[maxn] = {0};

void Save007();
bool FirstJump(int v);
bool DFS(int v);
bool Judge(int v);
bool Jump(int v1,int v2);

int main()
{
	scanf("%d%lf",&n,&d);
	for (int i = 0; i < n; i++)
	{
		scanf("%lf%lf",&P[i].x,&P[i].y);
	}
	Save007();
	return 0;
}

void Save007()
{
	bool isSave = false;
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && FirstJump(i))
		{
			isSave = DFS(i);
			if (isSave)
			{
				break;
			}
		}
	}
	
	if (isSave)
	{
		printf("Yes");
	}
	else
	{
		printf("No");
	}
}

bool FirstJump(int v)
{
	double x = pow(P[v].x,2);
	double y = pow(P[v].y,2);
	double dis = pow((d+ISLAND_RADIUS),2);
	return x+y <= dis;
}

bool DFS(int v)
{
	vis[v] = true;
	bool answer = false;
	
	if (Judge(v))
	{
		return true;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (!vis[i] && Jump(v,i))
		{
			answer = DFS(i);
			if (answer)
			{
				break;
			}
		}
	}
	return answer;
}

//当前点位的坐标加上跳的距离大于50表示可以跳到岸边 
bool Judge(int v)
{
	int dis_x = abs(P[v].x) + d ;
	int dis_y = abs(P[v].y) + d;
	return dis_x >= DIS_SAVE || dis_y >= DIS_SAVE;
}

bool Jump(int v1,int v2)
{
	int dis_x = pow(P[v1].x - P[v2].x, 2);
	int dis_y = pow(P[v1].y - P[v2].y, 2);
	int dis = pow(d + ISLAND_RADIUS, 2);
	return dis_x + dis_y <= dis;
}
