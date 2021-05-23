#include<cstdio>
const int maxn = 2020; //前两个点过不了 

double arr[maxn] = {0};
double mul[maxn] = {0};

int main()
{
	int exp;
	double coe;
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %lf",&exp,&coe);
		arr[exp] = coe;
	}
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %lf",&exp,&coe);
		for(int j = 0; j < maxn ; j++)
		{
			if(arr[j] != 0.0)
			{
				mul[j + exp] += coe * arr[j];
			}
 		} 
	}
	int count = 0;
	for(int i = 0; i < maxn ; i++)
	{
		if(mul[i] != 0.0)
		{
			count++;
		}
	}

	printf("%d",count);
	if(count == 0) printf(" 0");
	else
	{
		for(int i = maxn; i >= 0; i--)
		{
			if(mul[i] != 0)
			{
				printf(" %d %.1f",i,mul[i]);
			}
		}
	}	
	return 0;
}
