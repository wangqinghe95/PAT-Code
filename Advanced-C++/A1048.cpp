//https://www.cnblogs.com/wanghao-boke/p/8655324.html 
//博客里有hash法，两种二分法

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
bool BinarySearch(int index, int right, int value, int *arr)
{
	int left = 0;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if (mid == index) return false;
		if (arr[mid] > value)
		{
			right = mid - 1;
		}
		else if (arr[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			return true;
		} 
	}
	return false;
}

int main()
{
	int arr[maxn];
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+n);
	
	bool flag = false;
	for (int i = 0; i < n ; i++)
	{
		if (BinarySearch(i, n, m - arr[i], arr))
		{
			printf("%d %d", arr[i], m-arr[i]);
			flag = true;
			break;
		}
	}
	
	if (!flag)
	{
		printf("No Solution");
	}
	return 0;
}

/*#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int BinarySearch(int index, int right, int value, int *arr)
{
	int left = 0;
	while(left <= right)
	{
		int mid = (left + right) / 2;
		//if (mid == index) return false;
		if (arr[mid] > value)
		{
			right = mid - 1;
		}
		else if (arr[mid] < value)
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		} 
	}
	return -1;
}

int main()
{
	int arr[maxn];
	int n, m;
	scanf("%d%d", &n, &m);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	sort(arr, arr+n);
	
	bool flag = false;
	for (int i = 0; i < n ; i++)
	{
		int pos = BinarySearch(i, n, m - arr[i], arr);
		if (pos != -1 && pos != i)
		{
			printf("%d %d", arr[i], arr[pos]);
			flag = true;
			break;
		}
	}
	
	if (!flag)
	{
		printf("No Solution");
	}
	return 0;
}*/
