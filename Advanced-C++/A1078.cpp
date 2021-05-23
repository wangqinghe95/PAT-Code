/*
 Quadratic 二次的
 probing    探索
*/
#include<cstdio>
const int maxn = 10010;
bool hashTable[maxn] = {0};

bool isPrime(int n);
void print(int pos, int i);

int main()
{
    int n,m;
    scanf("%d%d", &m, &n);

    while(!isPrime(++m));

    int x;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        int pos = x % m;

        if (!hashTable[pos])
        {
            hashTable[pos] = 1;
            print(pos, i);
        }
        else
        {
            int step = 1;
            for (; step <= m; step++)   //平方探测发的结束判断条件是step大于数组大小时
            {
                int tempPos = (pos + step * step) % m;
                if (!hashTable[tempPos])
                {
                    hashTable[tempPos] = 1;
                    print(tempPos, i);
                    break;
                }
            }

            if (step >= m)
            {
                print(-1, i);
            }
        }        
    }

    return 0;
}

bool isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

void print(int pos, int i)
{
    if (i > 0)
    {
        printf(" ");
    }

    if(pos >= 0)     //找到空位
    {
        printf("%d", pos);
    }
    else
    {
        printf("-");
    }    
}