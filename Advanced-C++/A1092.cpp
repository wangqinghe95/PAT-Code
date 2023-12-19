#include <cstdio>
#include <cstring>

const int maxn = 1010;
int hashtable[130] = {0};

int main()
{
    char str_shop_owner[maxn] = {0};
    char str_Eva[maxn] = {0};

    fgets(str_shop_owner, maxn, stdin);
    fgets(str_Eva, maxn, stdin);

    int len_str_shop = strlen(str_shop_owner);
    int len_str_Eva = strlen(str_Eva);

    for(int i = 0; i < len_str_shop; ++i) {
        hashtable[str_shop_owner[i]]++;
    }

#if 0
    bool flag = true;
    for(int i = 0; i < len_str_Eva; ++i) {
        hashtable[str_Eva[i]]--;
        if(hashtable[str_Eva[i]] < 0) {
            flag = false;
        }
    }

    int num_diff = 0;
    if(flag == false) {
        printf("No ");
        for(int i = 0; i < 130; ++i) {
            if(hashtable[i] < 0) {
                num_diff++;
            }
        }
        printf("%d\n", num_diff);
    }
    else {
        printf("Yes %d\n", (len_str_shop-len_str_Eva));
    }
#else
    int miss = 0;
    for(int i = 0; i < len_str_Eva; ++i) {
        hashtable[str_Eva[i]]--;
        if(hashtable[str_Eva[i]] < 0) {
            miss++;
        }
    }   

    if(miss < 0) printf("No %d\n", miss);
    else    printf("Yes %d\n", len_str_shop-len_str_Eva);
#endif
    return 0;
}