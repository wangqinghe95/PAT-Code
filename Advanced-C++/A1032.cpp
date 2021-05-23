#include<cstdio>
#include<cstring>
const int maxn = 100010;

struct Node
{
	int next;
	bool flag;
}node[maxn];

void init();

int main()
{
	init();
	int wordBegin_1;
	int wordBegin_2;
	int n;
	
	scanf("%d%d%d",&wordBegin_1,&wordBegin_2,&n);
	
	int address;
	int next;
	char c;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d %c %d",&address,&c,&next);
		node[address].next = next;
	}
	
	int tmp = wordBegin_1;
	while(tmp != -1)
	{
		node[tmp].flag = true;
		tmp = node[tmp].next;
	}
	
	tmp = wordBegin_2;
	while(tmp != -1)
	{
		if(node[tmp].flag)
		{
			break;
		}
		tmp = node[tmp].next;
	}
	
	if(tmp == -1)
	{
		printf("-1");
	}
	else
	{
		printf("%05d",tmp);
	}
	
	return 0;	
}

void init()
{
	for(int i = 0; i < maxn; i++)
	{
		node[i].flag = false;
	}
}
