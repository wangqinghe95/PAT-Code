/**
 * 判断八皇后问题，皇后不能在同一行、同一列、同一对角线（相邻列行数差一）
 * 
*/
#include <cstdio>
#include <cmath>

const int maxn = 1010;

int main()
{
    int k,n;
    scanf("%d", &k);

    for(int i = 0; i < k; ++i) {
        int arr[maxn] = {0};

        scanf("%d", &n);
 
        bool flag = true;
        for(int j = 1; j <= n; ++j) {
            scanf("%d", &arr[j]);
            for(int t = 1; flag && t < j; t++) {

                if(arr[t] == arr[j] || abs(t-j) == abs(arr[t]-arr[j])) {
                    flag = false;
                    break;
                }
            }

        }

        printf("%s", flag ? "YES\n" : "NO\n");
    }

    return 0;
}