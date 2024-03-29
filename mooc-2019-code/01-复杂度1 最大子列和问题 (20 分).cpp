// https://www.cnblogs.com/wanghao-boke/p/11687800.html

#include<cstdio>
const int maxn = 100100;

int main()
{
	int a[maxn] = {0};
	int dp[maxn] = {0};
	int n;
	scanf("%d",&n);
	
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
	}
	
	dp[0] = a[0];
	for ( int i = 1; i < n; i++) 
	{
		//if ( dp[i-1] + a[i] > a[i] )
        if ( dp[i - 1] > 0 )
		{
			dp[i] = dp[i - 1] + a[i];	
		} 
		else
		{
			dp[i] = a[i];
		}
	}
	
	int max = -1;
	for ( int i = 0; i < n; i++)
	{
		if ( max < dp[i] )
		{
			max = dp[i];
		}
	}
	
	if ( max == -1 )
	{
		printf("0");
	}
	else
	{
		printf("%d",max);
	}
	return 0;
}
