#include<cstdio>
const int maxn = 54;

int map[5] = {'S','H','C','D','J'};
int start[maxn+1], end[maxn+1], next[maxn+1];

int main()
{
	int k;
	scanf("%d", &k);
	for (int i = 1; i <= maxn; i++)
	{
		start[i] = i;
	}
	
	for (int i = 1; i <= maxn; i++)
	{
		scanf("%d", &next[i]);
	}
	
	for (int step = 0; step < k; step++)
	{
		for (int i = 1; i <= maxn; i++)
		{
			end[next[i]] = start[i];
		}
		
		for (int i = 1; i <= maxn; i++)
		{
			start[i] = end[i];
		}
	}
	
	for (int i = 1; i <= maxn; i++)
	{
		if (i > 1)
		{
			printf(" ");
		}
		start[i]--;	//map[0] ~ (S1,S13) -1以后除以13就可以获取map的位数了 
		printf("%c%d", map[start[i]/13], start[i]%13+1);
	}
	return 0;
}
