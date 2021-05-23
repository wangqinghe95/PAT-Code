#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 1000010;

struct node
{
    int data;
    int next;
}node[maxn];

int List[maxn];

int main()
{
    int begin, n, k;
    scanf("%d%d%d", &begin, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int address, data, next;
        scanf("%d", &address);
        scanf("%d%d", &node[address].data,&node[address].next);
    }

    int count = 0;
    int p = begin;
    while (p != -1)
    {
        List[count++] = p;
        p = node[p].next;
    }

    for (int i = 0; i + k <= count; i += k)
    {
        reverse(&List[i], &List[i+k]);
    }

    for (int i = 0; i < count; i++)
    {
        printf("%05d %d", List[i], node[List[i]].data);
        if (i < count - 1)
        {
            printf(" %05d\n",List[i+1]);
        }
        else
        {
            printf("-1");
        }        
    }

    return 0;    
}



