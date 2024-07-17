#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;

int m, K;

// map<int,LL> result;
pair<int,int> result[10010];
int cnt_valid = 0;

int gcd(int a, int b) 
{
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int isPrime(int a)
{
    if(a <= 1) return false;
    for(int i = 2; i * i <= a; ++i) {
        if(a % i == 0) return false;
    }

    return true;
}

void DFS(int current_K, int current_m, LL current_A)
{
    if(current_K > K || current_m > m) return ;
    if(m > 9*(K-current_K) + current_m) return ;    // 如果后续全是 9，但是加上当前的 sum 也不够 m 的话说明当前分支不对

    if(current_K == K && current_m == m) {
        LL y = current_A + 1;

        // 找到 A+1 的 n
        int n = 0;
        while (y != 0)
        {
            n += (y % 10);
            y /= 10;
        }

        int common_divisor = gcd(n,m);
        if(common_divisor > 2 && isPrime(common_divisor)) 
            result[cnt_valid++] = {n, current_A};
        return;
    }

    for(int i = 0; i <= 9; ++i) {
        if(current_m == 0 && i == 0) continue;
        DFS(current_K+1, current_m+i, current_A*10+i);
    }
}

int main()
{
    int N;
    scanf("%d", &N);
    for(int i = 1; i <= N; ++i) {
        scanf("%d%d", &K, &m);
        cnt_valid = 0;

        printf("Case %d\n", i);
        DFS(0,0,0);

        if(0 == cnt_valid) {
            printf("No Solution\n");
        }
        else {
            // 不排序第三个测试点不过
            sort(result, result+cnt_valid);
            for(int j = 0; j < cnt_valid; ++j) {
                printf("%d %lld\n", result[j].first, result[j].second);
            }
        }
    }
    return 0;
}