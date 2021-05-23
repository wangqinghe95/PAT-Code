#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

void Split(int n, int *arr);
int Make(int *arr);
bool isSame(int *arr);

int main()
{
    int n;
    int arr[5] = {0};
    int max = 0;
    int min = 0;

    scanf("%d", &n);
    while (1)
    {
        Split(n, arr);        
        sort(arr, arr+4, cmp);
        int max_num = Make(arr);
        sort(arr, arr+4);
        int min_num = Make(arr);

        n = max_num - min_num;
        printf("%04d - %04d = %04d\n",max_num, min_num, n);

        if (n == 6174 || n == 0)
        {
            break;
        }
    }
    
    return 0;
}

void Split(int n, int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] = n % 10;
        n /= 10;
    }
}

int Make(int *arr)
{
    int num = 0;
    for (int i = 0; i < 4; i++)
    {
        num = arr[i] + num * 10;
    }
    return num;
}

bool isSame(int *arr)
{
    if (arr[0] == arr[1] && arr[1] == arr[2] && arr[2] == arr[3] && arr[4] == arr[3])
    {
        return true;
    }
    else
    {
        return false;
    }
    
}