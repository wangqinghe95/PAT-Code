#include <cstdio>
#include <vector>
using namespace std;

vector<int> fac;
vector<int> ans, temp;

int g_max_index_sum = -1;

int n,k,p;

int getPower(int base, int p)
{
    int ans = 1;
    for(int i = 0; i < p; ++i) {
        ans *= base;
    }
    return ans;
}

void init()
{
    int tmp = 0;
    int index = 0;
    while (tmp <= n)
    {
        fac.push_back(tmp);
        tmp = getPower(++index, p);
    }
}

void DFS(int index, int index_cnt, int fac_sum, int index_sum)
{
    if(fac_sum == n && index_cnt == k) {
        if(index_sum > g_max_index_sum) {
            ans = temp;
            g_max_index_sum = index_sum;
        }
        return;
    }

    if(fac_sum > n || index_cnt > k ) {
        return;
    }

    if(index >= 1) {
        temp.push_back(index);
        DFS(index, index_cnt+1, fac_sum+fac[index], index_sum+index);
        temp.pop_back();
        DFS(index-1, index_cnt, fac_sum, index_sum);
    }
}

int main()
{
    scanf("%d%d%d",&n, &k, &p);
    init();

    DFS(fac.size()-1, 0,0,0);

    if(g_max_index_sum == -1) {
        printf("Impossible\n");
    }
    else {
        printf("%d = %d^%d", n, ans[0],p);
        for(int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], p);
        }
    }

    return 0;
}