#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

const int maxn = 1010;

int main()
{
    int np, ng;
    int weight[maxn] = {0};
    int rank[maxn] = {0};
    scanf("%d%d", &np, &ng);

    for (int i = 0; i < np; i++)
    {
        scanf("%d", &weight[i]);
    }

    queue<int> q;
    int order;
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &order);
        q.push(order);
    }

    int temp = np;
    int nGroup;
    while(q.size() != 1)
    {
        if (temp % ng != 0)
        {
            nGroup = temp / ng  + 1;
        }
        else
        {
            nGroup = temp / ng;
        }        

        for (int i = 0; i < nGroup; i++)
        {
            int k = q.front();
            for (int j = 0; j < ng; j++)
            {
                if (j + ng * i >=  temp)
                {
                    break;
                }

                int front = q.front();
                if (weight[front] > weight[k])
                {
                    k = front;
                }
                rank[front] = nGroup + 1;
                q.pop();
            }
            q.push(k);
        }
        temp = nGroup;
    }

    rank[q.front()] = 1;

    for (int i = 0; i < np; i++)
    {
        printf("%d", rank[i]);
        if (i < np - 1)
        {
            printf(" ");
        }
    }
    return 0;
}
