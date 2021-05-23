#include<cstdio>
const int maxn = 10000;

void Binary(int n,int radix);
bool isPalindromic(int *num,int len);
void print(int *num,int len);

int main()
{
	int n,b;

	scanf("%d%d",&n,&b);
	Binary(n,b);

	return 0;
}

void Binary(int n,int radix)
{
	int len = 0;
	int num[maxn];
	do
	{
		num[len++] = n % radix;
		n /= radix;
	}while(n > 0);
	
	if(isPalindromic(num,len))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	print(num,len);
}

bool isPalindromic(int *num,int len)
{
	for(int i = 0; i < len; i++)
	{
		if(num[i] != num[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

void print(int *num,int len)
{
	for(int i = len - 1; i >= 0; i--)
	{
		printf("%d",num[i]);
		if(i > 0) printf(" ");
	}
}
