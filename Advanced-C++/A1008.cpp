#include<cstdio>

int main()
{
 	int curr = 0;
	int k;
	int next;
	scanf("%d",&k);
	int sum = 0;
	for(int i = 0; i < k; i++)
	{
	 	scanf("%d",&next);
		if(next > curr)
		{
		 	sum += (next - curr) * 6 + 5;	
		}	
		else
		{
			sum += (curr - next) * 4 + 5;
		}
		curr = next;
	}	
	printf("%d",sum);
	return 0;
} 
