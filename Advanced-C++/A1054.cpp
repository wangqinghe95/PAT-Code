#include<cstdio>

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    int max_num = 0;
    int max_ID = -99999;
    int x;
    for (int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &x);

            if (x != max_ID)
            {
                if (0 == max_num)
                {
                    max_ID = x;
                    max_num = 1; 
                }
                else
                {
                    max_num--;      
                }               
            }
            else
            {
                max_num++;
            }            
        }
    }

    printf("%d", max_ID);
    return 0;
}
