#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;

int main()
{
    int arr[maxn] = {0};
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);


    int diff = 0;
    for(int i = 0; i < n/2; ++i) {
        diff += (arr[n-1-i] - arr[i]);
    }

    if(n % 2 == 0) {
        printf("0 %d\n", diff);
    }
    else{
        printf("1 %d\n", diff + arr[n/2]);
    }

    return 0;
}