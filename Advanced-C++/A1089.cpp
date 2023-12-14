#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110;

int n;
int original[MAXN] = {0};
int sorted[MAXN] = {0};

bool judgeArraySame(int* arr1, int* arr2)
{
    for(int i = 0; i < n; ++i) {
        if(arr1[i] != arr2[i]) {
            return false;
        }
    }

    return true;
}

void printArray(int* arr)
{
    for(int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
        printf("%s", i < n-1 ? " " : "");
    }
    printf("\n");
}

bool InsertSort()
{
    bool flag = false;
    for(int i = 1; i < n; ++i) {
        if(i != 1 && judgeArraySame(original, sorted)) {
            flag = true;
        }
        int temp = original[i];
        int j = i-1;
        for(; j >= 0 && temp < original[j]; --j) {
            original[j+1] = original[j];
        }
        original[j+1] = temp;

        if(flag) return true;
    }

    return false; 
}


void mergeSort()
{
    bool flag = false;
    for(int step = 2; step/2 <= n; step *= 2) {
        if(step != 2 && judgeArraySame(sorted,original)) {
            flag = true;
        }
        for(int i = 0; i < n; i += step) {
            sort(original+i, original+min(i+step, n));
        }

        if(flag) {
            printArray(original);
            return;
        }
    }
}

int main()
{
    scanf("%d",&n);
    int backup_origin[MAXN] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d",&original[i]);
        backup_origin[i] = original[i];
    }
    for(int i = 0; i < n; ++i) {
        scanf("%d", &sorted[i]);
    }

    if(InsertSort()){
        printf("Insertion Sort\n");
        printArray(original);
    }
    else {
        printf("Merge Sort\n");
        memcpy(original, backup_origin, sizeof(original));
        mergeSort();    
    }

    return 0;
}