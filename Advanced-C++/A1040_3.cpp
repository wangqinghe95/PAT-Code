#include<cstdio>
#include<cstring>
const int maxn = 1010;

int dp[maxn][maxn] = {0};

int main()
{
	char str[maxn];
	fgets(str, maxn, stdin);
	
	int len = strlen(str);
	int ans = 1;
	
	for (int i = 0 ; i < len; i++)
	{
		dp[i][i] = 1;
		if (str[i] == str[i+1])
		{
			dp[i][i+1] = 1;
			ans = 2;
		}
	}
	
	for (int L = 3 ; L <= len; L++)
	{
		for (int i = 0; i + L - 1 < len; i++)
		{
			int j = i + L - 1;
			if (str[i] == str[j] && dp[i+1][j-1] == 1)
			{
				dp[i][j] = 1;
				ans = L;
			}
		}
	}
	
	printf("%d", ans);
	return 0;
}
