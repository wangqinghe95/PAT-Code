
/**
 * 两点：
 * 1. 小于 2 的数不是素数
 * 2. signed int 的最大值是 0x7fffffff
*/
#include <cstdio>

const int max = 0x7fffffff;

bool isPrime(int x)
{
    if(x < 2) {
        return false;
    }

    for(int i = 2; i*i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

int findSexPrime(int x) 
{
    if(isPrime(x)) {
        if(isPrime(x-6)) {
            return x-6;
        }
        if(isPrime(x+6)) {
            return x+6;
        }
    }
    return -1;

}

int main()
{
    int x;
    scanf("%d", &x);

    int sex_prime = findSexPrime(x);
    if(sex_prime > 0) {
        printf("Yes\n");
        printf("%d\n", sex_prime);
    }
    else {
        printf("No\n");
        for(int i = x; i < max; ++i)
        {
            if(findSexPrime(i) > 0) {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}