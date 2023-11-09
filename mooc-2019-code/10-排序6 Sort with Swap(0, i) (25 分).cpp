//https://www.cnblogs.com/wanghao-boke/p/11924679.html

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

int main()
{
	int n;
	int num;	//数组存储方式调换，便于交换arr[0]和arr[arr[0]] 
	int arr[maxn] = {0};
	scanf("%d",&n);
	
	int left = n - 1; //控制循环次数，需要交换数的个数，0除外 
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&num);
		arr[num] = i;
		if (num == i && num != 0)
		{
			left--;
		}
	}
	
	int k = 1;	//如果排序还未最终完成但是 0 已经回到arr[0]处，交换arr[k]值
	int ans = 0;	//纪录交换的次数 
	while (left > 0)
	{
		if (arr[0] == 0)
		{
			while (k < n)
			{
				if (arr[k] != k)
				{
					swap(arr[0], arr[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		else
		{
			swap(arr[0], arr[arr[0]]);
			ans++;
			left--;
		}
	}
	
	printf("%d", ans);
	return 0;
}
