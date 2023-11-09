#include <cstdio>
#include <algorithm>

struct Fraction
{
    int up, down;
    Fraction():up(0),down(1){}
};

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a%b);
}

void reduction(Fraction& result)
{
    if(result.up < 0) {
        result.down = -result.down;
        result.up = -result.up;
    }

    if(result.up == 0) {
        result.down = 1;
    }
    else {
        int d = gcd(result.up,result.down);
        result.up /= d;
        result.down /= d;
    }
}

void add(Fraction& a, Fraction& b)
{
    a.up = a.up*b.down + a.down*b.up;
    a.down *= b.down;
    reduction(a);
}

void showResult(Fraction& a)
{
    reduction(a);
    if(a.down == 1) {
        printf("%d",a.up);
    }
    else if (abs(a.up) > abs(a.down)) {
        printf("%d %d/%d", a.up/a.down, a.up%a.down, a.down);
    }
    else {
        printf("%d/%d", a.up,a.down);
    }
    printf("\n");
}

int main()
{
    int n;
    scanf("%d",&n);

    Fraction sum, temp;
    for(int i = 0; i < n; ++i) {
        scanf("%d/%d", &temp.up, &temp.down);
        add(sum, temp);
    }

    showResult(sum);

    return 0;
}

/**
 *  version 1
*/
/*
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>

using namespace std;

class RationalNumber
{
private:
    long long m_numberaotr;
    long long m_denominator;
public:
    RationalNumber():m_numberaotr(0),m_denominator(1){}
    ~RationalNumber(){}
    RationalNumber(string str)
    {
        int index = 0;
        bool bPositive = true;
        if(str[0] == '-'){
            bPositive = false;
            index = 1;
        }

        long long num = 0;
        for(int i = index; i < str.size(); ++i) {
            if(str[i] >= '0' && str[i] <= '9') {
                num = num * 10 + (str[i] - '0');
            }
            else if (str[i] == '/') {
                m_numberaotr = num;
                num = 0;
            }
        }
        m_denominator = num;

        simply(m_numberaotr, m_denominator);

        if(bPositive == false) {
            m_numberaotr = -m_numberaotr;
        }
    }

    void simply(long long& a, long long& b) {
        long long gcd_num = 0;
        if(a > b) {
            gcd_num = gcd(a, b);
        }
        else {
            gcd_num = gcd(b,a);
        }

        if(gcd_num > 1) {
            a /= gcd_num;
            b /= gcd_num;
        }
    }

    long long getGCD(long long a, long long b) {
        return a > b ? gcd(a,b) : gcd(b,a);
    }

    long long gcd(long long a, long long b) {
        if (0 == b) {
            return a;
        }
        return gcd(b, a%b);
    }

    void printRationalNumber()
    {
        if(m_denominator == 1) {
            cout << m_numberaotr << endl;
        }
        else if (abs(m_numberaotr) > abs(m_denominator)) {
            cout << m_numberaotr/m_denominator << " " << m_numberaotr%m_denominator << "/" << m_denominator << endl;
        }
        else {
            cout << m_numberaotr << "/" << m_denominator << endl;
        }
    }
    
    RationalNumber& operator+=(const RationalNumber& rhs) {
        if(m_denominator == rhs.m_denominator) {
            m_numberaotr += rhs.m_numberaotr;
        }
        else {
            m_numberaotr = m_numberaotr*rhs.m_denominator + m_denominator*rhs.m_numberaotr;
            m_denominator *= rhs.m_denominator;
        }
        simply(m_numberaotr, m_denominator);
    }
};

int solution_1()
{
    int n;
    cin >> n;
    string str;
    RationalNumber CRationalNum;
    for(int i = 0; i < n; ++i) {
        cin >> str;
        CRationalNum+=RationalNumber(str);
    }

    CRationalNum.printRationalNumber();

    return 0; 
}

*/
/**
 * version 2
*/
/*
class Fraction
{
private:
    int m_up, m_down;
public:
    Fraction():m_up(0),m_down(1){};
    Fraction(int up, int down):m_up(up),m_down(down){};

    Fraction& operator+=(const Fraction& rhs)
    {
        m_up = m_up*rhs.m_down + m_down*rhs.m_up;
        m_down *= rhs.m_down;
        return *this;
    }

    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b,a%b);
    }

    Fraction& reduction(Fraction& frac)
    {
        if(frac.m_down < 0) {
            frac.m_down = -frac.m_down;
            frac.m_up = -frac.m_up;
        }

        if(frac.m_up == 0) {
            frac.m_down = 1;
        }
        else {
            int d = gcd(abs(frac.m_down), frac.m_up);
            frac.m_down /= d;
            frac.m_up /= d;
        }

        return frac;
    }

    void showResult(){
        reduction(*this);
        if(m_down == 1) {
            cout << m_up << endl;
        }
        else if (abs(m_down) < abs(m_up)) {
            cout << m_up/m_down << " " << m_up%m_down << "/" << m_down << endl;
        }
        else {
            cout << m_up << "/" << m_down << endl;
        }
    }
};

int main()
{
    int n;
    scanf("%d",&n);
    int up, down;
    Fraction CFrac;
    for(int i = 0; i < n; ++i) {
        scanf("%d/%d", &up, &down);
        CFrac += Fraction(up,down);
    }

    CFrac.showResult();
    return 0;
}
*/


