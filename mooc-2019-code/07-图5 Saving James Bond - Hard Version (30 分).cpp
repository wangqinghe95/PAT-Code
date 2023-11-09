// https://www.cnblogs.com/wanghao-boke/p/11802088.html

#include<cstdio>
#include<queue>
#include<stack>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 110;
const int minLen = 50 - 15.0/2;

struct Point
{
	int x,y;
}point[maxn];

int path[maxn] = {0};
bool vis[maxn] = {0};
int n,d;

void BFS();
void init(int b[]);
bool cmp(int x,int y);
int FirstJump(int v);
bool isSafe(int v);
bool Jump(int v1,int v2);

int main()
{
	scanf("%d%d",&n,&d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d",&point[i].x,&point[i].y);
	}
	
	if (d >= minLen)
	{
		printf("1\n");
	}
	else
	{
		BFS();
	}
	return 0;
}

void BFS()
{
	int b[maxn];
	init(b);
	sort(b,b+n,cmp);
	
	queue<int> q;
	int last;
	int tail;
	int step = 2;
	
	for (int i = 0; i < n; i++)
	{
		if(FirstJump(b[i]))
		{
			q.push(b[i]);
			vis[b[i]] = true;
			last = b[i];
		}
	}
	
	while(!q.empty())
	{
		int now = q.front();
		q.pop();
		
		if (isSafe(now))
		{
			int k =1;
			stack<int> s;
			cout << step << endl;
			
			while (k < step)
			{
				s.push(now);
				now = path[now];
				k++;
			}
			
			while (!s.empty())
			{
				now = s.top();
				s.pop();
				cout << point[now].x << " " << point[now].y << endl;
			}
			return;
		}
		
		for (int i = 0; i < n; i++)
		{
			if (!vis[i] && Jump(now,i))
			{
				q.push(i);
				vis[i] = true;
				tail = i;
				path[i] = now;
			}
		}
		
		if (last == now)
		{
			last = tail;
			step++;
		}
	}
	
	if (q.empty())
	{
		cout << "0" << endl;
	}
}

void init(int b[])
{
	for (int i = 0; i < n; i++)
	{
		b[i] = i;
	}
}

bool cmp(int x,int y)
{
	return FirstJump(x) < FirstJump(y);
}

int FirstJump(int v)
{
	int dis = pow(point[v].x,2) + pow(point[v].y,2);
	int dis_Jump = pow(15.0/2 + d,2);
	if (dis <= dis_Jump)
	{
		return dis;
	}
	else
	{
		return 0;
	}
}

bool isSafe(int v)
{
	int dis_safe = 50 - d;
	return abs(point[v].x) >= dis_safe || abs(point[v].y) >= dis_safe;
}

bool Jump(int v1,int v2)
{
	int dis_x = pow(point[v1].x-point[v2].x, 2);
	int dis_y = pow(point[v1].y-point[v2].y, 2);
	if (dis_x + dis_y <= d*d)
	{
		return true;
	}
	else
	{
		return false;
	}
}
