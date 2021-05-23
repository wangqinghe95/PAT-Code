#include<iostream>
#include<string>
using namespace std;

string deal(string s, int &e, int n);

int main()
{
    int n;
    string str1, str2;

    cin >> n >> str1 >> str2;

    int e1 = 0, e2 = 0;
    string s1 = deal(str1, e1, n);
    string s2 = deal(str2, e2, n);

    if (s1 == s2 && e1 == e2)
    {
        cout << "YES 0." << s1 << "*10^" << e1 << endl;
    }
    else
    {
        cout << "NO 0." << s1 << "*10^" << e1 << " 0." << s2 << "*10^" << e2 << endl;
    }
    
    return 0;
}

string deal(string s, int &e, int n)
{
    int k = 0;
    while (s.length() > 0 && s[0] == '0')
    {
        s.erase(s.begin());
    }

    if (s[0] == '.')
    {
        s.erase(s.begin());
        while (s.length() > 0 && s[0] == '0')
        {
            s.erase(s.begin());
            e--;
        }
    }
    else
    {
        while (k < s.length() && s[k] != '.')
        {
            k++;
            e++;
        }
        if (k < s.length())
        {
            s.erase(s.begin()+k);
        }
    }

    if (s.length() == 0)
    {
        e = 0;
    }

    int num = 0;
    k = 0;
    string res;
    while(num < n)
    {
        if (k < s.length())
        {
            res += s[k++];
        }
        else
        {
            res += '0';
        }  
        num++;
    }
    return res;
}