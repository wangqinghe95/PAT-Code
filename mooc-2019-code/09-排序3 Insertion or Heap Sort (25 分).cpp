https://www.cnblogs.com/wanghao-boke/p/11886170.html

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 110;
int tempOri[maxn], origin[maxn], change[maxn];
int n;

bool Insertion();
bool isSame(int A[], int B[]);
void showArray(int A[]);
void Heap();
void downjust(int low, int high);

int main()
{

	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&origin[i]);
		tempOri[i] = origin[i];
	}
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d",&change[i]);
	}
	
	if (Insertion())
	{
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else
	{
		printf("Heap Sort\n");
		for (int i = 1; i <= n; i++)
		{
			tempOri[i] = origin[i];
		}
		Heap();
	}
	
	return 0;
}

bool Insertion()
{
	bool flag = false;
	for (int i = 2; i <= n; i++)
	{
		if (i != 2 && isSame(tempOri, change))
		{
			flag = true;
		}
		
		sort(tempOri,tempOri+i+1);
		if (flag)
		{
			return true;
		}
	}
	return false;
}

bool isSame(int A[], int B[])
{
	for (int i = 1; i <= n; i++)
	{
		if (A[i] != B[i])
		{
			return false;
		}
	}
	return true;
}

void showArray(int A[])
{
	for (int i = 1; i <= n; i++)
	{
		printf("%d",A[i]);
		if (i < n)
		{
			printf(" ");
		}
	}
}

void Heap()
{
	bool flag = false;
	for (int i = n/2; i >= 1; i--)
	{
		downjust(i,n);
	}
	
	for (int i = n; i > 1; i--)
	{
		if (i != n && isSame(tempOri, change))
		{
			flag = true;
		}
		swap(tempOri[i], tempOri[1]);
		downjust(1, i-1);
		
		if (flag)
		{
			showArray(tempOri); 
			return;
		}
	}
}

void downjust(int low, int high)
{
	int parent = low, child = parent * 2;
	while (child <= high)
	{
		if (child < high && tempOri[child+1] > tempOri[child])
		{
			child++;
		}
		
		if (tempOri[child] > tempOri[parent])
		{
			swap(tempOri[child], tempOri[parent]);
			parent = child;
			child *= 2;
		}
		else
		{
			break;
		}
	}
}
