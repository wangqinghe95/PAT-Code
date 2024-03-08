#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n, m, s;
    scanf("%d%d%d", &m, &n, &s);

    map<string, int> winners;
    bool b_flag = false;
    int index = 1;
    for(int i = 1; i <= m; ++i) {
        string post_name;
        cin >> post_name;

        if(winners[post_name] == 1) s++;
        if(winners[post_name] == 0 && i == s) {
            winners[post_name] = 1;
            cout << post_name << endl;
            b_flag = true;
            s += n;
        }
    }

    if(!b_flag) {
        cout << "Keep going..." << endl;
    }

    return 0;
}