#include <cstdio>

const int maxn = 50;

int getSum(int num)
{
    int sum = 0;
    while (num != 0)
    {
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int num;
    int friendsId[maxn] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%d", &num);
        int id = getSum(num);
        friendsId[id] = 1;
    }

    int cnt = 0;
    for(int i = 0; i < maxn; ++i) {
        if(friendsId[i] != 0) {
            cnt++;
        }
    }

    printf("%d\n", cnt);
    for(int i = 0; i < maxn; ++i) {
        if(friendsId[i] != 0) {
            cnt--;
            printf("%d%c", i, cnt != 0 ? ' ' : '\n');
        }
    }

    return 0;
}