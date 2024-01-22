#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int maxn = 10010;

const int matrix_maxn = 110;

int arr[maxn] = {0};
int matrix[maxn][maxn] = {0};

bool cmp(int a, int b) {
    return a > b;
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    if(n == 1) {
        printf("%d", arr[0]);
        return 0;
    }

    sort(arr, arr+n, cmp);

    int row = (int)ceil(sqrt(1.0*n));
    while (n % row != 0)
    {
        row++;
    }

    int col = n / row;

    int upper = 0, bottom = row-1;
    int left = 0, right = col-1;

    int i = 0, j = 0, now = 0;
    while (now < n)
    {
        while (now < n && j < right)
        {
            matrix[i][j++] = arr[now++];
        }

        while (now < n && i < bottom)
        {
            matrix[i++][j] = arr[now++];
        }

        while (now < n && j > left)
        {
            matrix[i][j--] = arr[now++];
        }
        while (now < n && i > upper)
        {
            matrix[i--][j] = arr[now++];
        }
        
        upper++;
        bottom--;
        left++;
        right--;

        i++;
        j++;

        if(now == n-1) {
            matrix[i][j] = arr[now++];
        }  
    }
      
    for(int i = 0; i < row; ++i) {
        for(int j = 0; j < col; ++j) {
            printf("%d%c", matrix[i][j], j != col-1 ? ' ' : '\n');
        }
    }

    return 0;
}