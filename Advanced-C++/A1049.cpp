/*
反正这道题我在考场上是做不出来的 
n = 132
a = 10
right = n % a
left = n / (a * 10)
now = n / a % 10
*/
#include<cstdio>
int main()
{
	int n;
	scanf("%d", &n);
	
	int a = 1;
	int left, now, right;
	int ans = 0;
	
	while( n / a)
	{
		now = n / a % 10;
		left = n / (a * 10);
		right = n % a;
		
		if (0 == now)
		{
			ans += left * a;
		}
		else if (1 == now)
		{
			ans += left * a + right + 1;
		}
		else
		{
			ans += (left + 1) * a;
		}
		 
		a *= 10;
	}
	
	printf("%d", ans);
	return 0;
}
