//https://www.cnblogs.com/wanghao-boke/p/12006005.html
#include<cstdio>
#include<cstring>
#include<cstdlib>
const int maxn = 1000100;

int KMP(char *string, char *pattern);
void buildMatch(char *pattern, int *match);

int main()
{
	char string[maxn] = {0};
	char pattern[maxn] = {0};
	int n;
	
	scanf("%s", &string);
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", &pattern);
		int p = KMP(string, pattern);
		if (p != -1)
		{
			printf("%s", string+p);
		}
		else
		{
			printf("Not Found");
		}
		
		if (i < n-1)
		{
			printf("\n");
		}
	}
	
	return 0;
}

int KMP(char *string, char *pattern)
{
	int n = strlen(string);
	int m = strlen(pattern);
	
	if (n < m)
	{
		return -1;
	}
	int *match = (int *)malloc(sizeof(int) * m);
	
	buildMatch(pattern, match);
	
	int s = 0;
	int p = 0;
	while (s < n && p < m)
	{
		if (string[s] == pattern[p])
		{
			s++;
			p++;
		}
		else if(p > 0)
		{
			p = match[p-1] + 1;
		}
		else
		{
			s++;
		}
	}
	
	return (p == m) ? (s - m) : -1;
}

void buildMatch(char *pattern, int *match)
{
	int m = strlen(pattern);
	match[0] = -1;
	
	for (int j = 1; j < m; j++)
	{
		int i = match[j-1];
		while( (i >= 0) && (pattern[i + 1] != pattern[j]) )
		{
			i = match[i];
		}
		
		if (pattern[i + 1] == pattern[j])
		{
			match[j] = i + 1;
		}
		else
		{
			match[j] = -1;
		}
	}
}
