#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10010;
int In[maxn] = {0};
int nIndex = 0;
int n;

void InOrder(int root, int *arr);

int main()
{
    scanf("%d", &n);
    int arr[maxn] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    InOrder(1, arr);

    for (int i = 1; i <= n; i++)
    {
        printf("%d", In[i]);
        printf("%s", i < n ? " " : "");
        
    }
    return 0;
}

void InOrder(int root, int *arr)
{
    if (root > n)
    {
        return ;
    }
    InOrder(root*2, arr);
    In[root] = arr[nIndex++];
    InOrder(root*2+1, arr);
}