#include<cstdio>
const int maxn = 100100;

bool isPrime(int x)
{
	if(x <= 1) return false;
	for(int i = 2; i * i <= x; i++ )
	{
		if(x % i == 0) return false;
	}
	return true;
}

bool reverse(int n,int d)
{
	int num[maxn] = {0};
	int ans = 0;
	int index = 0;
	do
	{
		num[index++] = n % d;
		n /= d;
	}while(n);
	
	for(int i = 0; i < index; i++)
	{
		ans = ans * d + num[i];
	}
	if(isPrime(ans))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	int n,d;
	while(1)
	{
		scanf("%d",&n);
		if( n < 0)
			break;
			
		scanf("%d",&d);
		if(isPrime(n) && reverse(n,d))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}		
	}
	return 0;
}

