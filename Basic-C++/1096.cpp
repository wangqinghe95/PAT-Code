/**
 * 若正整数 N 可以整除它的 4 个不同正因数之和
 * a % b == 0, 表示 a 可以被 b 整除，即 b 可以整除 a
 * 所以应该是 (a+b+c+d) % n == 0
*/
#include <cstdio>
#include <vector>
using namespace std;
const int maxn = 10010;

// 18 1 2 3 6 9 18
// 40 1 2 4 5 8 10 20 40
bool isBigNumer(int n)
{
#if 0
    vector<int> res;
    // res.push_back(1);
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            res.push_back(i);
        }
    }

    if(res.size() < 4) {
        return false;
    }
    for(int i = 0; i < res.size(); ++i){
        for(int j = i+1; j < res.size(); ++j){
            for(int u = j+1; u < res.size(); ++u){
                for(int v = u+1; v < res.size(); ++v){
                    if(0 == (res[i] + res[j] + res[u] + res[v]) % n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
#else 
    int res[maxn] = {0};
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        if(n % i == 0){
            res[cnt++] = i;
        }
    }
    if(cnt < 4) {
        return false;
    }
    for(int i = 0; i < cnt; ++i){
        for(int j = i+1; j < cnt; ++j){
            for(int u = j+1; u < cnt; ++u){
                for(int v = u+1; v < cnt; ++v){
                    if(0 == (res[i] + res[j] + res[u] + res[v]) % n){
                        return true;
                    }
                }
            }
        }
    }
    return false;
#endif
}

int main()
{
    int n = 0;
    int res = scanf("%d", &n);
    (void)res;
    int num = 0;
    for(int i = 0; i < n; ++i)
    {
        res = scanf("%d", &num);
        if(true == isBigNumer(num))
        {
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    return 0;
}