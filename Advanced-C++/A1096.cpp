#include <cstdio>
#include <cmath>

using ll = long long;

int main()
{   
    ll n;
    scanf("%lld", &n);

    ll sqr = (int)sqrt(1.0*n);
    ll ans_len = 0;
    ll ans_index = 0;
    for(ll i = 2; i <= sqr; ++i) {
        ll temp = 1;
        ll j = i;
        while (1)
        {
            temp *= j;
            if(n % temp != 0) break;
            if(j - i + 1 > ans_len) {
                ans_len = j-i+1;
                ans_index = i;
            }
            j++;
        }
    }

    if(ans_len == 0) {
        printf("1\n%lld\n", n);
    }
    else {
        printf("%lld\n", ans_len);
        for(ll i = 0; i < ans_len; ++i) {
            printf("%lld", ans_index+i);
            if(i < ans_len - 1) printf("*");
        }
    }
    return 0;
}