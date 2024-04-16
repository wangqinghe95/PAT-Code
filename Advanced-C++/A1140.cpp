/**
 * 如果 D 是 1 的话，那么应该是 1，11，13，1131
 * 如果 D 不是 1 的话，假如是 2，2，21，2111，2113
*/
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    int d, n;
    scanf("%d%d", &d, &n);

    string res;
    res.push_back(d+'0');

    while (--n)
    {
        string temp;

        int cnt = 0;
        char c = res[0];
        for(int i = 0; i < res.size(); ++i) {
            if(res[i] == c) {
                cnt++;
            }
            else {
                temp.push_back(c);
                temp.push_back(cnt+'0');
                cnt = 1;
                c = res[i];
            }
        }
        if(cnt != 0) {
            temp.push_back(c);
            temp.push_back(cnt+'0');            
        }
        res = move(temp);

    }
    
    printf("%s\n", res.data());

    return 0;
}