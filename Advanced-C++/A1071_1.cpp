#include<iostream>
#include<string>
#include<map>
using namespace std;

bool check(char c);

int main()
{
    string str;

    map<string, int> mp;

    getline(cin, str);

    int len = str.length();
    int i = 0;
    while(i < len)
    {
        string word;
        while ( i < len && check(str[i]))
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
            word += str[i];
            i++;
        }
        if (word != " " && (!word.empty()))
        {
            if (mp.find(word) != mp.end())
            {
                mp[word]++;
            }
            else
            {
                mp[word] = 1;
            }          
        }
        while(i < len && (!check(str[i])))
        {
            i++;
        }
    }

    string ans;
    int max = 0;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        if (it->second > max)
        {
            ans = it->first;
            max = it->second;
        }
    }

    cout << ans << " " << max << endl;
    return 0;
}

bool check(char c)
{
    if (c >= '0' && c <= '9')
    {
        return true;
    }
    else if (c >= 'a' && c <= 'z')
    {
        return true;
    }
    else if (c >= 'A' && c <= 'Z')
    {
        return true;
    }

    return false;
}