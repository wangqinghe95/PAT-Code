// https://www.cnblogs.com/wanghao-boke/p/11729453.html

//遍历方式是层次遍历
#include<cstdio>
#include<queue>
using namespace std; 
const int maxn = 15;
struct Node
{
	int left,right;
}node[maxn];

bool isRoot[maxn];
int num = 0;

void init();
int change(char c);
int FindRoot(int n);
void BFS(int root);
void print(int v);

int main()
{
	init();
	int n;
	char a,b;
	scanf("%d",&n);
	
	for (int i= 0; i < n; i++)
	{
		getchar();
		scanf("%c %c",&a,&b);
		node[i].left = change(a);
		node[i].right = change(b);
	}
	
	int root = FindRoot(n);
	BFS(root);
	return 0;
}

void init()
{
	for (int i = 0; i < maxn; i++)
	{
		isRoot[i] = true;
	}
}

int change(char c)
{
	int iRet = -1;
	if (c != '-')
	{
		iRet = c - '0';
		isRoot[iRet] = false;
	}
	return iRet;
}

int FindRoot(int n)
{
	for (int i = 0; i < n; i++)
	{
		if (isRoot[i])
		{
			return i;
		}
	}
}

void BFS(int root)
{
#if 0	//使用数组模拟队列 
	int front = -1;  //头 
	int rear = -1;	//尾
	int queue[maxn] = {0};
	
	queue[++front] = root;
	while (front != rear)
	{
		int now = queue[++rear];
		if (node[now].left == -1 && node[now].right == -1)
		{
			print(now);
		}
		if (node[now].left != -1)
		{
			queue[++front] = node[now].left;	
		}
		if (node[now].right != -1)
		{
			queue[++front] = node[now].right;
		}		
	}
#else	//使用c++的queue 
	queue<int> q;
	q.push(root);
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (node[now].left == -1 && node[now].right == -1)
		{
			print(now);
		}
		if (node[now].left != -1)
		{
			q.push(node[now].left);	
		}
		if (node[now].right != -1)
		{
			q.push(node[now].right);
		}
	}

#endif
}

void print(int v)
{
	if (0 == num)
	{
		printf("%d",v);
		num++;
	}
	else
	{
		printf(" %d",v);
	}
}
/*
void BFS(int root)  先序遍历
{
	if (node[root].left == -1 && node[root].right == -1)
	{
		if (1 == num)
		{
			printf("%d",root);
			num++;
		}
		else
		{
			printf(" %d",root);
		}
		return;
	}
	
	if (node[root].left != -1)
	{
		BFS(node[root].left);
	}
	if (node[root].right != -1)
	{
		BFS(node[root].right);
	}
}
*/
