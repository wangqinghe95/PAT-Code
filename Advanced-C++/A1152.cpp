/**
 * 20023 中，如果 K = 4 时，0023 是一个解决方案，但是 002 不能当一个解决方案
 * 所以打印的时候也需要注意，0023 不能以数字的形式打印
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

bool isPrime(int number)
{
    if(number < 2) return false;
    for(int i = 2; i * i <= number; ++i) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int convertNum(const char* str, int start, int end)
{
    int num = 0;
    for(int i = start; i < end; ++i) {
        num = str[i] - '0' + num*10;
    }

    return num;
}

int main()
{
    int L, K;
    scanf("%d%d", &L, &K);

    char* str = new char[L+1];
    scanf("%*c%s", str);

    for(int i = 0; i < L - K + 1; i++)
    {
        string s(str+i, str+i+K);
        int number = stoi(s);
        if(isPrime(number)) {
            printf("%s", s.data());
            return 0;
        }
    }

    printf("404");
    return 0;    
}