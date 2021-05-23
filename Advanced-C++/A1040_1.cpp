#include<cstdio>
#include<cstring>
const int maxn = 1010;

bool Symmetric(char *str, int low, int len)
{
	for (int i = low; i < len/2 + low; i++)
	{
		if (str[i] != str[low + len - (i - low) - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	char str[maxn];
	fgets(str, maxn, stdin);
	
	int len = strlen(str);
	int maxLen = 1;
	
	for (int i = 0; i < len; i++)
	{
		for (int j = 1; j <= len - i; j++)
		{
			if (Symmetric(str, i ,j) && j > maxLen)
			{
				maxLen = j;
			}
		}
	}
	
	printf("%d", maxLen);
	return 0;
}
