/**
 * 两个狼，有一个狼人在说慌，但是也有一个好人在说谎
*/
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<int> player(n+1);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", &player[i]);
    }

    for(int i = 1; i <= n; ++i) {
        for(int j = i+1; j <= n; ++j) {
            vector<int> lies;
            vector<int> wolf(n+1, 1);
            wolf[i] = -1;
            wolf[j] = -1;

            for(int k = 1; k <= n; ++k) {
                if(player[k] * wolf[abs(player[k])] < 0) {
                    lies.push_back(k);
                }
            }
            if(lies.size() == 2 && wolf[lies[0]] + wolf[lies[1]] == 0) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }

    printf("No Solution\n");
    return 0;
}