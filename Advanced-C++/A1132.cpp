#include <cstdio>
#include <cstring>

bool CuttingAnInteger(long long z)
{
    long long x = z;

    int cnt_z = 0;
    while (x != 0)
    {
        x /= 10;
        cnt_z++;
    }

    x = z;
    cnt_z /= 2;
    long long pow = 1;
    for(int i = 0; i < cnt_z; ++i) {
        x /= 10;
        pow *= 10;
    }

    int low_digit = z - x * pow;
    if(low_digit == 0) {
        return false;
    }
    long long result = x * low_digit;

    if(z % result == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    long long Z;
    for(int i = 0; i < n; ++i) {
        scanf("%lld", &Z);
        if(CuttingAnInteger(Z)) {
            printf("Yes\n");
        }
        else {
            printf("No\n");
        }
    }

    return 0;
}