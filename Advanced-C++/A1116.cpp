#include <cstdio>

const int maxn = 10010;
int ranklist[maxn] = {0};

bool isPrime(int x)
{
    if(x <= 1) return false;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    scanf("%d", &n);

    int id;
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &id);
        if(1 == i) {
            ranklist[id] = 1;
        }
        else if(isPrime(i) == true) {
            ranklist[id] = 2;
        }
        else {
            ranklist[id] = 3;
        }
    }

    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &id);
        printf("%04d: ",id);
        if(ranklist[id] == 4) {
            printf("Checked\n");
        }
        else if(ranklist[id] == 1) {
            printf("Mystery Award\n");
            ranklist[id] = 4;
        }
        else if(ranklist[id] == 2) {
            printf("Minion\n");
            ranklist[id] = 4;
        }
        else if(ranklist[id] == 3) {
            printf("Chocolate\n");
            ranklist[id] = 4;
        }
        else {
            printf("Are you kidding?\n");
        }
    }

    return 0;
}