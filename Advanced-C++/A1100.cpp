#define Solution_1 1
#if Solution_1
#include <iostream>
#include <string>

using namespace std;

string unitDigit[15] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[15] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

int findNum(const string& str, int mode)
{
    for(int i = 0; i < 13; ++i) {
        if(str == unitDigit[i]) {
            return i;
        }
    }

    for(int i = 0; i < 13; ++i) {
        if(str == tenDigit[i]) {
            return i*13;
        }
    }

    return 0;
}

int main()
{
    int n;
    scanf("%d%*c", &n);

    while (n--)
    {
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9') {
            int num = stoi(str);
            if(num > 12) {
                cout << tenDigit[num/13];
                if(num % 13 != 0) {
                    cout << " " << unitDigit[num%13];
                }
                cout << endl;
            }
            else {
                cout << unitDigit[num] << endl;
            }
        }
        else {
            if(str.length() > 4) {
                int numeber1 = findNum(str.substr(0,3), 2);
                int numeber2 = findNum(str.substr(4,3), 1);
                cout << numeber1 + numeber2 << endl;
            }
            else {
                int number1 = findNum(str.substr(0,3), 1);
                cout << number1 << endl;
            }
        }
    }
    
    return 0;
}
#else


#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

string unitDigit[15] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string tenDigit[15] = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

map<string,int> string2int;
string int2String[170];

void init()
{
    for(int i = 0; i < 13; ++i) {
        string2int[unitDigit[i]] = i;
        int2String[i] = unitDigit[i];

        string2int[tenDigit[i]] = i*13;
        int2String[i*13] = tenDigit[i];
    }

    for(int i = 1; i < 13; ++i) {
        for(int j = 1; j < 13; ++j) {
            string str = tenDigit[i] + " " + unitDigit[j];
            string2int[str] = i*13+j;
            int2String[i*13+j] = str;
        }
    }
}

int main()
{

    init();
    int n;
    scanf("%d%*c", &n);

    while (n--)
    {
        string str;
        getline(cin, str);
        if(str[0] >= '0' && str[0] <= '9') {
            int num = stoi(str);
            cout << int2String[num] << endl;
        }
        else {
            cout << string2int[str] << endl;
        }
    }
    
    return 0;
}

#endif