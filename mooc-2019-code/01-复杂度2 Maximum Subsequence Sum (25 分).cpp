// https://www.cnblogs.com/wanghao-boke/p/11688678.html

#include<cstdio>
const int maxn = 100100;

int main()
{
	int a[maxn];
	int dp[maxn];
	int s[maxn];
	
	int n;
	bool flag = false;
	scanf("%d",&n);
	for ( int i = 0; i < n; i++ )
	{
		scanf("%d",&a[i]);
		if ( !flag && ( a[i] >= 0 ) )
		{
			flag = true;
		}
	}
	
	if ( !flag )
	{
		printf("0 %d %d",a[0],a[n-1]);
	}
	else
	{
		dp[0] = a[0];
		s[0] = 0;
		for ( int i = 1; i < n; i++ )
		{
			if ( dp[i - 1] + a[i] >= a[i] )
			{
				dp[i] = dp[i - 1] + a[i];
				s[i] = s[i - 1];
			}
			else
			{
				dp[i] = a[i];
				s[i] = i;
			}
		}
		
		int k = -1;
		int max = -1;
		for ( int i = 0; i < n; i++)
		{
			if ( dp[i] > max)
			{
				max = dp[i];
				k = i;
			}
		}
		
		printf("%d %d %d",max,a[s[k]],a[k]);
	}
	return 0;
}
