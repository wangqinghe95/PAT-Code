#include <cstdio>
#include <cstring>

const int maxn = 100010;
const int MODE = 1000000007;

int main()
{
    char str[maxn] = {0};
    fgets(str, maxn, stdin);

    int len = strlen(str);
    int* p_counts_p = new int[len];
    memset(p_counts_p, sizeof(p_counts_p), 0);
    for(int i = 0; i < len; ++i) {
        if(i > 0) {
            p_counts_p[i] = p_counts_p[i-1];
        }

        if(str[i] == 'P') {
            p_counts_p[i]++;
        }
    }

    int ans = 0;
    int n_counts_T = 0;
    for(int i = len-1; i >= 0; --i) {
        if(str[i] == 'T') {
            n_counts_T++;
        }
        else if(str[i] == 'A') {
            ans =  (ans + n_counts_T * p_counts_p[i])%MODE;
        }
    }

    printf("%d\n", ans);
    return 0;

}