/*
i 	0 1 2 3 4  5
arr	  1 2 4 14 9
dp	  1 3 7 21 30
给的距离只有相邻的两个位置的距离
要问的两个点的距离，要么正向 n-m两点的距离，要么是m-n绕了一圈的距离 
*/

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100100;

int main()
{
	int n;
	int arr[maxn] = {0};
	int dp[maxn] = {0};
	scanf("%d", &n);
	
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		dp[i] = sum;
	}
	
	int m, l, r;
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &l, &r);
		if (l > r) swap(l, r);
		int temp = dp[r-1] - dp[l-1];
		printf("%d\n", min(temp, sum-temp));
	}
	return 0;
}
