https://www.cnblogs.com/wanghao-boke/p/11878425.html

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 110;

int origin[maxn],tmpOri[maxn],change[maxn];

bool Insertion(int n);
void showArray(int arr[], int n);
bool Issame(int A[], int B[], int n);
void merge(int n);

int main()
{
	int n;
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&origin[i]);
		tmpOri[i] = origin[i];
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&change[i]);
	}
	
	if (Insertion(n))
	{
		printf("Insertion Sort\n");
		showArray(tmpOri,n);
	}
	else
	{
		printf("Merge Sort\n");
		for (int i = 0; i < n; i++)
		{
			tmpOri[i] = origin[i];
		}
		merge(n);
	}
	
	return 0;
}

bool Insertion(int n)
{
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		if (i != 1 && Issame(tmpOri, change, n))
		{
			flag = true;
		}
		
		int tmp = tmpOri[i];
		int j = i;
		while (j >= 1 && tmpOri[j - 1] > tmp)
		{
			tmpOri[j] = tmpOri[j-1];
			j--;
		}
		tmpOri[j] = tmp;
		
		if (flag)
		{
			return flag;
		}
	}
	return false;
}

void showArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d", arr[i]);
		if (i < n - 1)
		{
			printf(" ");
		}
	}
}

bool Issame(int A[], int B[], int n)
{
	for (int i = 0 ; i < n; i++)
	{
		if (A[i] != B[i])
		{
			return false;
		}
	}
	return true;
}

void merge(int n)
{
	bool flag = false;
	for (int step = 2; step / 2 <= n; step *= 2)
	{
		if (step != 2 && Issame(tmpOri, change, n))
		{
			flag = true;
		}
		
		for (int i = 0; i < n; i += step)
		{
			sort(tmpOri+i, tmpOri+min(i+step, n));
		}
		
		if (flag)
		{
			showArray(tmpOri, n);
			return ;
		}
	}
}
