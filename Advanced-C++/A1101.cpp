#include <cstdio>

const int maxn = 100010;
const int INF = 1000000000;

int main()
{
    int arr[maxn] = {0};
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int left[maxn] = {0};
    int right[maxn] = {0};

    left[0] = arr[0];
    right[n-1] = arr[n-1];

    int count = 0;
    for(int i = 1; i < n; ++i)
    {
        left[i] = left[i-1] > arr[i] ? left[i-1] : arr[i];

        right[n-i-1] = right[n-i] > arr[n-i] ? arr[n-i] : right[n-i];
    }

    for(int i = 0; i < n; ++i) {
        if(arr[i] >= left[i] && right[i] >= arr[i]) {
            count++;
        }
    }

    printf("%d\n", count);
    for(int i = 0; i < n; ++i) {
        if(arr[i] >= left[i] && arr[i] <= right[i]) {
            printf("%d", arr[i]);
            count--;
            // printf("%c", count > 0 ? ' ' : '\n');
            if(count > 0) printf(" ");
        }
    }

    printf("\n");   // 如果 count 是 0 的话，还是需要一个空行

    return 0;
}