#include <cstdio>
#include <algorithm>

using std::sort;

const int maxn = 10010;
int arr[maxn] = {0};

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    int result = arr[0];
    for(int i = 1; i < n; ++i) {
        result = (result + arr[i])/2;
    }

    printf("%d\n", result);
    return 0;
}