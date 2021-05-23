/*
stripe	条纹
sew	缝纫
involved 作为一部份参与的

解题思路：将喜欢的颜色按照给出顺序存储，（有顺序要求）
再在给出的要搜寻的序列中剔除不喜欢的颜色
最后按照最小不降序查找最长子序列 
 
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

					0 1 2 3 4 5 6 7 8 9 10 11
favorite_color		                  3 1 2   4 5
sorted				          1 1 3 4 4 5 2 3 3 4 5
求sorted的最长不降序子列 
*/

#include<cstdio>

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	int favorite_color[201] = {0};
	int sorted[100010] = {0};
	int dp[100010] = {0};
	int n, l, m, x, num = 0;
	
	scanf("%d", &n);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &x);
		favorite_color[x] = i;
	}
	
	scanf("%d", &l);
	for (int i = 0; i < l; i++)
	{
		scanf("%d", &x);
		if (favorite_color[x] >= 1)
		{
			sorted[num++] = favorite_color[x];
		}
	}
	
	int nMax = 0;
	for (int i = 0; i < num; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (sorted[i] >= sorted[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		nMax = max(nMax, dp[i]);
	}
	
	printf("%d", nMax);
	return 0;
}
