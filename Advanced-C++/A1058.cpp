#include<cstdio>
int main()
{
    int a[4];
    int b[4];
    int c[4];
    int carry = 0;

    scanf("%d.%d.%d %d.%d.%d", &a[1], &a[2], &a[3], &b[1], &b[2], &b[3]);

    c[3] = (a[3] + b[3]) % 29;
    carry = (a[3] + b[3]) / 29;
    c[2] = (a[2] + b[2] + carry) % 17;
    carry = (a[2] + b[2] + carry) / 17;
    c[1] = (a[1] + b[1] + carry) ;

    printf("%d.%d.%d",c[1], c[2], c[3]);
    return 0;
}