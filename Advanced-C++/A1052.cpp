#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Node
{
	int key;
	int address, next;
	int flag;
}node[maxn];

bool cmp(Node a, Node b);
void init();

int main()
{
	int n;
	int address, next, value;
	int begin;
	
	init();
	scanf("%d %d", &n, &begin);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d", &address, &value, &next);
		node[address].key = value;
		node[address].next = next;
		node[address].address = address;
		node[address].flag = 1;
	}
	
	int p = begin;
	int count = 0;
	while(p != -1)
	{
		node[p].flag = 2;
		p = node[p].next;
		count++;
	}
	
	if (count == 0)
	{
		printf("0 -1");
		return 0;
	}
	
	sort(node, node+maxn, cmp);
	printf("%d %05d\n", count, node[0].address);
	for (int i = 0; i < count; i++)
	{
		printf("%05d %d ", node[i].address, node[i].key);
		if (i != count - 1)
		{
			printf("%05d\n", node[i+1].address);
		}
		else
		{
			printf("-1");
		}
	}
	
	return 0;	
}

void init()
{
	for (int i = 1; i <= maxn; i++)
	{
		node[i].flag = 0;
	}
}

bool cmp(Node a, Node b)
{
	if (a.flag != b.flag)
	{
		return a.flag > b.flag;
	}
	else
	{
		return a.key < b.key;
	}
}
