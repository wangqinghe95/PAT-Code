/**
 * 保存 4 位数 ID 时判断两个人是否是同性为什么会有问题呢。
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;

const int maxn = 20000;

vector<int> g_friends_gender[maxn];
map<int, bool> g_friends_all;


bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int main()
{
    int n,m,k;
    scanf("%d%d%*c", &n, &m);

    int p1, p2;
#if 0
    // 第三个测试点过不去
    for(int i = 0; i < m; ++i) {
        scanf("%d%d",&p1, &p2);

        // 推测是同性的判断有误，猜测是不是因为 0 导致的
        bool is_same_sex = ((p1 ^ p2) > 0);

        // p1 = p1 < 0 ? -p1 : p1;
        // p2 = p2 < 0 ? -p2 : p2;

        p1 = abs(p1);
        p2 = abs(p2);

        if(is_same_sex) {
            g_friends_gender[p1].push_back(p2);
            g_friends_gender[p2].push_back(p1);
        }
        g_friends_all[p1*10000 + p2] = g_friends_all[p2*10000 + p1] = true;
    }
#else
    for(int i = 0; i < m; ++i) {
        char str1[8] = {0};
        char str2[8] = {0};
        scanf("%s %s%*c", str1, str2);
        int id1 = (atoi(str1));
        // int id1 = abs(stoi(str1));
        int id2 = (atoi(str2));
        // int id2 = abs(stoi(str2));
        id1 = id1 < 0 ? -id1 : id1; 
        id2 = id2 < 0 ? -id2 : id2; 
        if(strlen(str1) == strlen(str2)) {
            g_friends_gender[id1].push_back(id2);
            g_friends_gender[id2].push_back(id1);            
        }
        g_friends_all[id1*10000 + id2] = g_friends_all[id2*10000 + id1] = true;

    }
#endif
    scanf("%d", &k);
    for(int i = 0; i < k; ++i) {
        scanf("%d%d", &p1, &p2);

        p1 = p1 < 0 ? -p1 : p1;
        p2 = p2 < 0 ? -p2 : p2;

        vector<pair<int,int>> result;
        for(auto &x : g_friends_gender[p1]) {
            for(auto &y : g_friends_gender[p2]) {
                if(x == p2 || y == p1) continue;
                else if(g_friends_all[10000*x+y] == true) {
                    result.push_back({x,y});
                }
            }
        }

        sort(result.begin(), result.end(), cmp);
        printf("%d\n", result.size());
        for(auto &it : result) {
            printf("%04d %04d\n", it.first, it.second);
        }
        
    }

    return 0;
}