#include<cstdio>
const int maxn = 100010;

int main()
{
	int arr[maxn], hashTable[maxn] = {0};
	
	int n;
	scanf("%d",&n);
	for (int i = 0 ; i < n; i++)
	{
		scanf("%d",&arr[i]);
		hashTable[arr[i]]++;
	}
	
	for (int i = 0; i < n; i++)
	{
		if (hashTable[arr[i]] == 1)
		{
			printf("%d",arr[i]);
			return 0;
		}
	}
	
	printf("None");
	return 0;
}
