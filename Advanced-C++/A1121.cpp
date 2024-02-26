#include <cstdio>
#include <cstring>

const int maxn = 100010;

int ID[maxn];

int main()
{
    memset(ID, -1, sizeof(ID));
    int n;
    
    scanf("%d", &n);

    int couple1, couple2;
    for(int i = 0; i < n; ++i) {
        scanf("%d %d", &couple1, &couple2);
        ID[couple1] = couple2;
        ID[couple2] = couple1;
    }

    int k;
    scanf("%d", &k);

    int single[maxn];
    memset(single, -1, sizeof(single));
    
    for(int i = 0; i < k; ++i) {
        scanf("%d", &couple1);
        if(ID[couple1] == -1) {
            single[couple1] = 1;
        }
        if(single[ID[couple1]] == 1) {
            single[couple1] = 2;
            single[ID[couple1]] = 2;
        }
        else if(single[ID[couple1]] == -1) {
            single[couple1] = 1;
        }
        else {

        }

    }

    int count = 0;
    for(int i = 0; i < maxn; ++i) {
        if(single[i] == 1) {
            count++;
        }
    }

    printf("%d\n", count);
    for(int i = 0; i < maxn; ++i) {
        if(single[i] == 1) {
            printf("%05d%c", i, --count == 0 ? '\n' : ' ');
        }
    }

    return 0;
}