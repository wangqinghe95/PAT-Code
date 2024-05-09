#include <cstdio>
#include <vector>
#include <map>

using namespace std;

bool checkGoodsDangerous(vector<int>& v1, vector<int>& v2)
{
    for(auto& x : v1) {
        for(auto& y : v2) {
            if(x == y) {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    map<int, vector<int>> incompatible;
    int n, m;

    scanf("%d%d", &n, &m);

    int v1, v2;
    for(int i = 0; i < n; ++i) {
        scanf("%d%d", &v1, &v2);
        incompatible[v1].push_back(v2);
        incompatible[v2].push_back(v1);
    }

    int k;
    for(int i = 0; i < m; ++i) {
        scanf("%d%d", &k, &v1);
        vector<int> checkedList;
        checkedList.push_back(v1);
        bool bDangerous = false;
        for(int j = 1; j < k; ++j) {
            scanf("%d", &v1);
            if(bDangerous == true) continue;
            checkedList.push_back(v1);
            if(checkGoodsDangerous(incompatible[v1],checkedList) == true) {
                bDangerous = true;
            }
        }
        printf("%s\n", bDangerous == true ? "No" : "Yes");
    }


    return 0;
}
