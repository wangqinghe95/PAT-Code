// https://www.cnblogs.com/wanghao-boke/p/11748779.html

#include<cstdio>
const int maxn = 1010;
const int MIN = -1000100; 

int H[maxn];
int size;

void init();
void Insert(int x);

int main()
{
	init();
	int n,m;
	int v;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&v);
		Insert(v);
	}
	
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&v);
		
		printf("%d",H[v]);
		while (v > 1)
		{
			v /= 2;
			printf(" %d",H[v]);
		}
		printf("\n");
	}
	
	return 0;
}

void init()
{
	H[0] = MIN;
	size = 0;
}

void Insert(int x)
{
	int i;
	for (i = ++size; H[i/2] > x; i /= 2)
	{
		H[i] = H[i/2];
	}
	H[i] = x;
}
