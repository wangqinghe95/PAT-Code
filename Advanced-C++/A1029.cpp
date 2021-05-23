#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int INF = 10000000;

int main()
{
	int n;

	int sum = 0;
	scanf("%d",&n);
	
	sum += n;
	int *arr1 = (int *)malloc(n * sizeof(int));
	for( i = 0; i < n; i++)
	{
		scanf("%d",&arr1[i]);
	}
	arr1[i] = INF;
	
	scanf("%d",&n);
	sum += n;
	int *arr2 = (int *)malloc(n * sizeof(int));
	for( i = 0 ; i < n; i++)
	{
		scanf("%d",&arr2[i]);
	}
	arr2[i] = INF;
	
	sum = (sum-1)/2;
	int i = 0;
	int j = 0;
	int mid;
	while(sum--)
	{
		if(arr1[i] >= arr2[j])
		{
			//mid = arr2[j];
			j++;
		} 
		else
		{
			//mid = arr1[i];
			i++;
		}
	}
	printf("%d",min(arr1[i],arr2[j]));
	return 0;
}
