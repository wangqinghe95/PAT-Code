#include<cstdio>
#include<map>
using namespace std;

int main()
{
    int n,m;
    scanf("%d%d", &n, &m);
    map<int, int> count;

    int col;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &col);
            if (count.find(col) != count.end())
            {
                count[col]++;
            }
            else
            {
                count[col] = 1;
            }
        }
    }

    int max_num = -1;
    int max_ID = -99999;
    for (map<int, int>::iterator it = count.begin(); it != count.end(); it++)
    {
        if (it->second > max_num)
        {
            max_num = it->second;
            max_ID = it->first;
        }
    }

    printf("%d", max_ID);
    return 0;
}
