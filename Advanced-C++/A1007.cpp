#include<cstdio>
const int maxn = 100010;

int arr[maxn],dp[maxn],s[maxn] = {0};
int main()
{
	int k;
	bool flag = false;
	scanf("%d",&k);
	for(int i = 0; i < k; i++)
	{
		scanf("%d",&arr[i]);
		if(arr[i] >= 0)
		{
			flag = true;
		}
	}
	if(!flag)
	{
		printf("0 %d %d",arr[0],arr[k - 1]);
		return 0;
	}
	else
	{
		dp[0] = arr[0];
		for(int i = 1; i < k; i++)
		{
			if(arr[i] > dp[i-1] + arr[i])
			{
				dp[i] = arr[i];
				s[i] = i;
			}
			else
			{
				dp[i] = dp[i-1] + arr[i];
				s[i] = s[i - 1];
			}
		}
	}
	int n = 0;
	for(int i = 0; i < k; i++)
	{
		if(dp[i] > dp[n])
		{
			n = i;
		}
	}
	printf("%d %d %d\n",dp[n],arr[s[n]],arr[n]);
	return 0;
}
