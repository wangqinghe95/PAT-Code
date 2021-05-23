#include<cstdio>
const int maxn = 1000100;
struct Factor
{
    int x;
    int cnt;
}fac[10];

int prime[maxn];
int pNum = 0;

void Find_prime();
bool isPrime(int n);

int main()
{
    Find_prime();
    int n;
    scanf("%d", &n);

    if (n == 1)
    {
        printf("1=1");
    }
    else
    {
        printf("%d=", n);
        int num = 0;
        for (int i = 0;  i < pNum; i++)
        {
            if (n % prime[i] == 0)
            {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                      
                while(n % prime[i] == 0)
                {
                    fac[num].cnt++;
                    n /= prime[i]; 
                }
                num++;
            }

            if (n == 1)
            {
                break;
            }
        }
        if (n != 1)
        {
            fac[num].x = n;
            fac[num].cnt = 1;
        }

        for (int i = 0; i < num; i++)
        {
            if (i > 0)
            {
                printf("*");
            }

            printf("%d", fac[i].x);

            if (fac[i].cnt > 1)
            {
                printf("^%d", fac[i].cnt);
            }
        }    
    }
    
    return 0;
}

void Find_prime()
{
    for (int i = 0; i < maxn; i++)
    {
        if (isPrime(i))
        {
            prime[pNum++] = i;
        }
    }
}

bool isPrime(int n)
{
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}