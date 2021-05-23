/*
1.两个数组长度的中间位置 是 (n+m-1)/2  
2.如果要按照比较数组值大小来逼近中间数，必须在两个数组的最后面加一个最大数
	主要是为了防止有一个数组的最小数大于另一个数组最大数的情况
3.数组比较结束两个指向两个数字的位置，小的那个才是中间数 
*/
#include<cstdio>
#include<cstdlib>

const int INF = 1000000000;

int* GetNum(int *sum);

int main()
{
	int sum = 0;
	
	int *arr1 = GetNum(&sum);
	
	int *arr2 = GetNum(&sum);
	
	sum = (sum - 1)/2;
	int i = 0;
	int j = 0;
	while(sum--)
	{
		if(arr1[i] >= arr2[j])
		{
			j++;
		} 
		else
		{
			i++;
		}
	}
	printf("%d",arr1[i] > arr2[j] ? arr2[j] : arr1[i] );
	
	return 0;
}

int* GetNum(int *sum)
{
	int n;
	scanf("%d",&n);
	*sum += n;
	
	int *arr = (int *)malloc(n * sizeof(int));
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	arr[n] = INF;
	return arr;
}
