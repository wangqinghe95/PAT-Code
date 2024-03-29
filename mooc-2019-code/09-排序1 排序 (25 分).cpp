// https://www.cnblogs.com/wanghao-boke/p/11871838.html

#include<cstdio>
#include<cstdlib>
const int maxn = 100010;

//插入排序 
void insertion_sort(int arr[],int n);
//希尔排序 
void shell_sort(int arr[],int n);
void sedgewick_sort(int arr[], int n);

//选择排序 
void select_sort(int arr[], int n);

//最小堆排序 
void percdown(int arr[], int n, int i);
void heap_sort(int arr[], int n);

//冒泡排序 
void bubble(int arr[], int n);

//快速排序
void quick(int arr[], int n); 
void quick_sort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

//归并排序-循环方式
void merge_loop(int arr[], int n);
void msort_loop(int arr[], int low, int high); 
void merge_loop(int arr[], int low, int mid, int high);

//归并排序--递归方式
void merge_sort_recursive(int arr[], int n); 
void msort_recursive(int arr[], int tmp[], int low, int high);
void merge_recursive(int arr[], int tmp[], int low, int mid, int high);

int main()
{
	int n;
	int arr[maxn];
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	
	//Insertion_sort(arr, n);
	//shell_sort(arr, n);
	//sedgewick_sort(arr, n);
	//select_sort(arr, n);
	//heap_sort(arr, n);
	//bubble(arr, n);
	//quick(arr, n);
	//merge_loop(arr, n);
	merge_sort_recursive(arr, n);

	
	for (int i = 0; i < n; i++)
	{
		printf("%d",arr[i]);
		if (i < n - 1)
		{
			printf(" ");
		}
	}
	return 0;
}

void insertion_sort(int arr[],int n)
{
	for (int i = 0; i < n; i++)
	{
		int j = i;
		int tmp = arr[i]; 
		for (; j > 0 && arr[j - 1] > tmp; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = tmp;
	}
}

void shell_sort(int arr[],int n)
{
	for (int d = n/2; d > 0; d /= 2)
	{
		for (int i = d; i < n; i++)
		{
			int tmp = arr[i];
			int j = i;
			for (; j >= d && arr[j - d]  > tmp; j -= d)
			{
				arr[j] = arr[j - d];
			}
			arr[j] = tmp;
		}
	}
}

void sedgewick_sort(int arr[], int n)
{
	int si = 0;
	int sedgewick[] = {929, 505, 209, 103, 41, 19, 5, 1, 0};
	for (; sedgewick[si] >= n; si++)
	{
		;
	}
	
	for (; sedgewick[si] > 0; si++)
	{
		int d = sedgewick[si];
		for (int i = d; i < n; i++)
		{
			int tmp = arr[i];
			int j = i;
			for (; j >= d && arr[j - d] > tmp; j -= d)
			{
				arr[j] = arr[j - d];
			}
			arr[j] = tmp;
		}
	}
}

void select_sort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int tmp = arr[i];
		int t = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < tmp)
			{
				tmp = arr[j];
				t = j;
			}
		}
		arr[t] = arr[i];
		arr[i] = tmp;
	}
}

void heap_sort(int arr[], int n)
{
	for (int i = (n-2)/2; i >= 0; i--)
	{
		percdown(arr, n, i);
	}
	for (int i = n - 1; i > 0; i--)
	{
		int temp = arr[i];
		arr[i] = arr[0];
		arr[0] = temp;
		percdown(arr, i, 0);
	}
}

void percdown(int arr[], int n, int i)
{
	int parent = i;
	int child;
	int x = arr[parent];
	for (; parent * 2 + 1 < n; parent = child)
	{
		child = parent * 2 + 1;
		if (child < n - 1 && arr[child+1] > arr[child])
		{
			child++;
		}
		
		if (x > arr[child])
		{
			break;
		}
		else
		{
			arr[parent] = arr[child];
		}
	}
	arr[parent] = x;
}

void bubble(int arr[], int n)
{
	bool swap = true;
	while (swap)
	{
		swap = false;
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i+1])
			{
				arr[i] += arr[i+1];
				arr[i+1] = arr[i] - arr[i+1];
				arr[i] -= arr[i+1];
				swap = true;
			}
		}
	}
}

void quick(int arr[], int n)
{
	quick_sort(arr, 0, n-1);
}

void quick_sort(int arr[], int low, int high)
{
	if(low < high)
	{
		int pivotpos = partition(arr,low,high);
		quick_sort(arr,low,pivotpos-1);
		quick_sort(arr,pivotpos+1,high);
	}
}

int partition(int arr[], int low, int high)
{
	int tmp = arr[low];
	while(low < high)
	{
		while(low < high && arr[high] >= tmp)
		{
			high--;
		}
		arr[low] = arr[high];
		while(low < high && arr[low] <= tmp)
		{
			low++;
		}
		arr[high] = arr[low];
	}
	arr[low] = tmp;
	return low;
}

void merge_loop(int arr[], int n)
{
	msort_loop(arr, 0, n-1);
}

void msort_loop(int arr[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		msort_loop(arr, low, mid);
		msort_loop(arr, mid + 1, high);
		merge_loop(arr, low, mid, high);
	}
}

void merge_loop(int arr[], int low, int mid, int high)
{
	int i,j,k;
	
	int len_left = mid - low + 1;
	int len_right = high - mid ;
	
	int L[len_left];
	int R[len_right];
	
	for (i = 0 ; i < len_left; i++)
	{
		L[i] = arr[low + i];
	}
	for (i = 0; i < len_right; i++)
	{
		R[i] = arr[1 + mid + i];
	}
	
	i = 0;
	j = 0;
	k = low;
	while(i < len_left && j < len_right)
	{
		if (L[i] <= R[j])
		{
			arr[k++] = L[i++];
		}
		else
		{
			arr[k++] = R[j++];
		}
	}
	
	while(i < len_left)
	{
		arr[k++] = L[i++];
	}
	while (j < len_right)
	{
		arr[k++] = R[j++];
	}
}

void merge_sort_recursive(int arr[], int n)
{
	int* tmp = (int *)malloc(n * sizeof(int));
	msort_recursive(arr, tmp, 0, n-1);
	free(tmp);
}

void msort_recursive(int arr[], int tmp[], int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		msort_recursive(arr, tmp, low, mid);
		msort_recursive(arr, tmp, mid+1, high);
		merge_recursive(arr, tmp, low, mid, high);
	}
}

void merge_recursive(int arr[], int tmp[], int low, int mid, int high)
{
	int left = low;
	int right = mid + 1;
	int start = low;
	
	while (left <= mid && right <= high)
	{
		if (arr[left] <= arr[right])
		{
			tmp[start++] = arr[left++];
		}
		else
		{
			tmp[start++] = arr[right++];
		}
	}
	
	while (left <= mid)
	{
		tmp[start++] = arr[left++];
	}
	while(right <= high)
	{
		tmp[start++] = arr[right++];
	}
	
	for (; low <= high; low++)
	{
		arr[low] = tmp[low];
	}
}
