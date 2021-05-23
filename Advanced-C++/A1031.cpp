#include<cstdio>
#include<cstring>
const int maxn = 85;

int main()
{
	char str[maxn];
	scanf("%s",str);
	
	int N = strlen(str);
	int n1 = ( N + 2) / 3;
	int n3 = n1;
	int n2 = N + 2 - n1 - n3;
	
	for( int i = 0; i < n1 - 1; i++ )
	{
		printf("%c",str[i]);
		for( int j = 0; j < n2 -2; j++ )
		{
			printf(" ");
		}
		printf("%c\n",str[N - i - 1]);
	}
	
	for(int i = 0; i < n2 ; i++)
	{
		printf("%c",str[n1 + i - 1]);
	}
	return 0;
}
