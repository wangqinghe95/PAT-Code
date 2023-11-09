// https://www.cnblogs.com/wanghao-boke/p/11748772.html

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1010;

int num[maxn];
int CBT[maxn];
int index = 0;

void inOrder(int root, int n);

int main()
{
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	
	inOrder(1,n);
	for (int i = 1; i <= n; i++)
	{
		printf("%d",CBT[i]);
		if (i < n)
		{
			printf(" ");
		}
	}
	
	return 0;
}

void inOrder(int root, int n)
{
	if (root > n)
	{
		return ;
	}
	
	inOrder(root*2, n);
	CBT[root] = num[index++];
	inOrder(root*2+1, n);
}
