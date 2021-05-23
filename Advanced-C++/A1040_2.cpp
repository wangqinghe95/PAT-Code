#include<cstdio>
#include<cstring>
const int maxn = 1010;

bool Symmetric(char *str, int low, int high)
{
	int mid = (low + high) / 2;
	for (int i = low; i <= mid; i++)
	{
		if (str[i] != str[high - i + low])
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
		for (int j = i + 1; j <= len; j++)
		{
			if (Symmetric(str, i ,j) && (j - i + 1) > maxLen)
			{
				maxLen = j - i + 1;
			}
		}
	}
	
	printf("%d", maxLen);
	return 0;
}
