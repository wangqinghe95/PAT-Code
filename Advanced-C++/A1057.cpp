/*
这道题有个坑是PeekMedian求的是中间值，不是中间位置值。所以不能单纯的找arr[median]
因为考虑到数值较大，所以采用了分块思想。
具体算法来自算法笔记
*/
#include<cstdio>
#include<cstring>
#include<stack>
#include<cmath>
using namespace std;
const int maxn = 100010;
const int sqrN = sqrt(maxn);

int block[maxn] = {0};
int table[maxn] = {0};

stack<int> st;

void Push(int x);
void Pop();
void PeekMedian(int k);

int main()
{
    int n;
    int x;
    scanf("%d", &n);

    char cmd[20] = {0};
    while(n--)
    {
        scanf("%s", cmd);
        if (strcmp(cmd, "Push") == 0)
        {
            scanf("%d", &x);
            Push(x);
        }
        else if (strcmp(cmd, "Pop") == 0)
        {
            if (st.empty() == true)
            {
                printf("Invalid\n");
            }
            else
            {
                Pop();
            }            
        }
        else if (strcmp(cmd, "PeekMedian") == 0)
        {
            if (st.empty() == true)
            {
                printf("Invalid\n");
            }
            else
            {
                int k = st.size();
                if (k % 2 == 0)
                {
                    k = k / 2;
                }
                else
                {
                    k = (k+1) / 2;
                }

                PeekMedian(k);
            }
            
        }
    }
}
void Push(int x)
{
    st.push(x);
    block[x/sqrN]++;
    table[x]++;
}
void Pop()
{
    int x = st.top();
    st.pop();
    block[x/sqrN]--;
    table[x]--;
    printf("%d\n",x);
}
void PeekMedian(int k)
{
    int sum = 0;
    int idx = 0;
    while (sum + block[idx] < k)
    {
        sum += block[idx++];
    }

    int num = idx * sqrN;
    while (sum + table[num] < k)
    {
        sum += table[num++];
    }

    printf("%d\n", num);
}
