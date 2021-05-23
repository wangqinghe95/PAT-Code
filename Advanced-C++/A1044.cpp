#include<cstdio>
const int maxn = 100010;
const int INF = 100000000;

int sum[maxn] = {0};

//返回大于x的sum数组最小坐标 
int upper_bound(int left, int right, int x)
{
	while (left < right)
	{
		int mid = (left + right) / 2;
		if (sum[mid] > x)
		{
			right = mid;
		}
		else
		{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	int n,s;
	int nearS = INF;
	
	scanf("%d%d", &n, &s);
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];
	}
	
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n+1, sum[i-1] + s);
		if (sum[j-1] - sum[i-1] == s)
		{
			nearS = s;
			break;
		}
		else if (j <= n && sum[j] - sum[i-1] < nearS)
		{
			nearS = sum[j] - sum[i-1];
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		int j = upper_bound(i, n+1, sum[i-1] + nearS); 
		if (sum[j-1] - sum[i-1] == nearS)
		{
			printf("%d-%d\n", i, j-1);
		}
	}
	return 0;
}
