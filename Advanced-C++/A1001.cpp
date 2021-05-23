#include<stdio.h>
int main()
{
	int a,b;
	int arr[10];
	int sum;
	scanf("%d%d",&a,&b);
	sum = a + b;
	int len = 0;
	if(sum < 0)
	{
		printf("-");
		sum = -sum;
	}
	if(sum == 0)
	{
		printf("0\n");
	}
	while(sum)
	{
		arr[len++] = sum % 10;
	 	sum /= 10;
	}
	for(int i = len - 1; i >= 0; i--)
	{
		printf("%d",arr[i]);
		if(i % 3 == 0 && i != 0)
		{
			printf(",");
		}
	}
	return 0;
}
