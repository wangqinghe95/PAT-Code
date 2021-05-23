//数组要放在全局变量里 
#include<cstdio>
#include<string.h>
const int maxn = 1020;
//double arr[maxn] = {0}; 
int main()
{
	int k;
	int total = 0;
	int exp;
	double coe;
	double arr[maxn] = {0};
	//memset(arr,0,sizeof(arr));
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%lf",&exp,&coe);
		arr[exp] += coe;
	}
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d%lf",&exp,&coe);
		arr[exp] += coe;
	}
	for(int i = 0; i < maxn; i++)
	{
		if(arr[i])
		{
			total++;
		}
	}
	printf("%d",total);
	for(int i = maxn - 1; i >= 0; i--)
	{
		if(arr[i])
		{
			printf(" %d %.1f",i,arr[i]);
		}
	}
	return 0;
}


