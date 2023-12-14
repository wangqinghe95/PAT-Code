#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Fraction
{
    ll up,down;
};

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a%b);
}

void reduction(Fraction& f)
{
    if(f.down < 0) {
        f.up = -f.up;
        f.down = -f.down;
    }

    if(f.up == 0) {
        f.down = 1;
    }
    else {
        ll d = gcd(abs(f.up), f.down);
        if(1 != d) {
            f.up /= d;
            f.down /= d;
        }
    }
}

Fraction add(Fraction& a, Fraction& b)
{
    Fraction result;
    result.up = a.down*b.up + a.up*b.down;
    result.down = a.down*b.down;
    reduction(result);
    return result;
}

void showFraction(Fraction& a)
{
    reduction(a);
    if(a.up < 0) {
        printf("(");
    }

    if(a.down == 1) {
        printf("%lld", a.up);
    }
    else if(abs(a.up) > a.down) {
        printf("%lld %lld/%lld", a.up/a.down, abs(a.up)%a.down, a.down);
    }
    else {
        printf("%lld/%lld",a.up%a.down, a.down);
    }

    if(a.up < 0) {
        printf(")");
    }
}

Fraction subduction(Fraction& a, Fraction& b)
{
    Fraction result;
    result.up = a.up*b.down - a.down*b.up;
    result.down = a.down*b.down;
    reduction(result);
    return result;
}

Fraction multiply(Fraction& a, Fraction& b)
{
    Fraction result;
    result.up = a.up*b.up;
    result.down = a.down*b.down;
    reduction(result);
    return result;   
}

Fraction division(Fraction& a, Fraction& b)
{
    Fraction result;
    result.up = a.up*b.down;
    result.down = a.down*b.up;
    reduction(result);
    return result;   
}

int main()
{
    Fraction a,b;
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

    Fraction sum = add(a,b);
    showFraction(a);
    printf(" + ");
    showFraction(b);
    printf(" = ");
    showFraction(sum);
    printf("\n");

    Fraction diff = subduction(a,b);
    showFraction(a);
    printf(" - ");
    showFraction(b);
    printf(" = ");
    showFraction(diff);
    printf("\n");

    Fraction product = multiply(a,b);
    showFraction(a);
    printf(" * ");
    showFraction(b);
    printf(" = ");
    showFraction(product);
    printf("\n");

    Fraction quotient = division(a,b);
    showFraction(a);
    printf(" / ");
    showFraction(b);
    printf(" = ");
    if(b.up == 0) {
        printf("Inf");
    }
    else {
        showFraction(quotient);
    }
    printf("\n");

    return 0;
}