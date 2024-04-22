#include <cstdio>

const int maxn = 1000100;

bool arr[maxn] = {false};

int main()
{
    int n;
    scanf("%d", &n);

    int v;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        if(v > 0 && v < 1000100) {
            arr[v] = 1;
        }
    }

    for(int i = 1; i <= maxn; ++i) {
        if(arr[i] == 0) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}