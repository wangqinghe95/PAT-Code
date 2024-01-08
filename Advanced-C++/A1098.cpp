#include<iostream>

const int maxn = 110;

int original[maxn] = {0};
int backup[maxn] = {0};
int goal[maxn] = {0};

void printArray(int *arr, int n)
{
    for(int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        printf("%c", i < n-1 ? ' ' : '\n');
    }
}

bool isSameWith2Arrays(int *arr1, int *arr2, int n)
{
    for(int i = 0; i < n; ++i) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

bool insertionSort(int *arr, int n)
{
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(i != 0 && isSameWith2Arrays(arr, goal, n)) {
            flag = true;
        }

        int j = i+1;
        int temp = arr[j];
        while (j > 0 && arr[j-1] > temp)
        {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;

        if(flag == true) {
            return true;
        }
    }
    return false;
}

void swap(int* a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void downAdjusted(int* arr, int low, int high) 
{
    int i = low;
    int j = i*2+1;
    while (j < high)
    {
        if( j < high-1 && arr[j+1] > arr[j]) {
            j++;
        }
        if(arr[j] > arr[i]) {
            swap(&arr[j], &arr[i]);
            i = j;
            j = j*2+1;
        }
        else {
            break;
        }
    }
}

void heapSort(int *arr, int n) 
{
    printf("Heap Sort\n");
    for(int i = (n-1)/2; i >= 0; --i) {
        downAdjusted(arr, i, n);
    }

    bool flag = false;
    for(int i = n-1; i > 0; i--) {
        if(i != n-1 && isSameWith2Arrays(arr, goal, n)) {
            flag = true;
        }
        swap(&arr[i], &arr[0]);
        downAdjusted(arr, 0, i);

        if(flag == true) {
            printArray(arr, n);
            return;
        }
    }
    return ;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i) {
        scanf("%d",&original[i]);
        backup[i] = original[i];
    }
    
    for(int i = 0; i < n; ++i) {
        scanf("%d",& goal[i]);
    }

    if(insertionSort(original, n)) {
        printf("Insertion Sort\n");
        printArray(original, n);
    }
    else {
        heapSort(backup, n);
    }

    return 0;
}