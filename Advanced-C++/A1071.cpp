#include<iostream>
#include<string>
#include<map>
using namespace std;

int main()
{
    string str;
    string word;
    string ans;
    map<string, int> mp;
    int maxn = 0;

    getline(cin, str);
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]) && !isalpha(str[i]))
        {
            if (word != "")
            {
                if (++mp[word] > maxn)
                {
                    maxn = mp[word];
                    ans = word;
                }
                word = "";
            }
        }
        else
        {
            word += tolower(str[i]);
        }        
    }
    if (word != "")
    {
        if (++mp[word] > maxn)
        {
            maxn = mp[word];
            ans = word;
        }
    }

    cout << ans << " " << maxn << endl;
    return 0;
}