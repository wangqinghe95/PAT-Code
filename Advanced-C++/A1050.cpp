#include<cstdio>
#include<cstring>
const int maxn = 10010;

int main()
{
	char str1[maxn] = {0};
	char str2[maxn] = {0};
	int hashTable[130] = {0};
	//scanf("%s", str1);
	//scanf("%s", str2);
	fgets(str1, maxn, stdin);
	fgets(str2, maxn, stdin);
	
	int len_str1 = strlen(str1);
	int len_str2 = strlen(str2);
	for (int i = 0; i < len_str2; i++)
	{
		hashTable[str2[i]] = 1;
	}
	
	for (int i = 0; i < len_str1; i++)
	{
		if (hashTable[str1[i]] == 0)
		{
			printf("%c", str1[i]);
		}
	}
	return 0;
}
