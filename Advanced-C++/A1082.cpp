#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;
const char digit[10][6] = {
    "ling ","yi ","er ","san ","si ","wu ","liu ","qi ","ba ","jiu ",
};

const char HexDigit[6][6] = {
    "Fu ","Shi ","Bai ","Qian ","Wan ","Yi "
};

void print4Digit(string num, string& result)
{
    bool bZero = false;

    for(int i = 0; i < num.size(); ++i) {
        if(num[i] != '0') {
            if(bZero) {
                result += digit[0];
            }
            result += digit[num[i]-'0'];
            if(num.size()-1-i != 0) {
                result += HexDigit[num.size()-1-i];
            }
            bZero = false;
        }
        else {
            bZero = true;
        }

    }
}

int main()
{
    string num, result;
    cin >> num;
    if(num[0] == '-') {
        result += HexDigit[0];
        num.erase(0,1);
    }

    if(num [0] == '0') {
        result += digit[0];
    }
    while (num[0] == '0')
    {
        num.erase(0,1);
    }
    

    if(num.size() > 8) {
        result += (digit[num[0]-'0'] );
        result += HexDigit[5];
        num.erase(0,1);
    }
    if(num.size() > 4) {
        print4Digit(num.substr(0,num.size()-4), result);
        result += HexDigit[4];
        num.erase(0, num.size()-4);
    }
    if(num.size() > 0) {
        print4Digit(num, result);
    }
    
    size_t endpos = result.find_last_not_of(" \t\n");
    if(endpos != string::npos) {
        result = result.substr(0, endpos+1);
    }
    cout << result << endl;
}