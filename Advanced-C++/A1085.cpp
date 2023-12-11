/**
 * 二分法查找时，如果使用 left <= right 时，如果要寻找的数据比整个数组中最大的元素都要大时，如果没有前置的判断，就会出现 left 返回 n（有效下标时 n-1）
 * p <= 10^9 时，再乘以一个数，有可能超出 int 的表示返回
*/

#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100100;

int getPerfectSubSeqenceMaxn(int* arr, int n, int start, long long pivot)
{
    if(arr[n-1] <= pivot) {
        return n-start;
    }
    int right = n;
    int left = start;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(arr[mid] > pivot) {
            right = mid - 1;
        }
        else if(arr[mid] <= pivot) {
            left = mid + 1;
        }
    }
    
    return (left - start);
}

int main()
{
    int n,p;
    int arr[MAXN] = {0};

    scanf("%d %d",&n, &p);
    for(int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }

    sort(arr, arr+n);

    int max_len = 0;
    int max_perfect = arr[0];
    for(int i = 0; i < n && i + max_len < n; ++i) {
        int len = getPerfectSubSeqenceMaxn(arr, n, i, (long long)arr[i]*p);
        if(max_len < len) {
            max_len = len;
        }
    }

    printf("%d\n", max_len);

    return 0;

}