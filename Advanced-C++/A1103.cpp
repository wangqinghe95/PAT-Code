#include <iostream>
#include <vector>

using namespace std;

vector<int> fac;
vector<int> ans, temp;

int g_max_fac_sum = -1;

int n,k,p;

int getPower(int base, int power)
{
    int ans = 1;
    for(int i = 0; i < power; ++i) {
        ans *= base;
    }
    return ans;
}

void init()
{
    int tmp = 0;
    int index = 1;
    while (tmp <= n)
    {
        fac.push_back(tmp);
        tmp = getPower(index++, p);
    }
}

void DFS(int index, int fac_cnt, int n_sum, int fac_sum)
{
    if(n_sum == n && fac_cnt == k) {
        if(fac_sum > g_max_fac_sum) {
            g_max_fac_sum = fac_sum;
            ans = temp;
        }
    }

    if(n_sum > n || fac_cnt > k) {
        return;
    }

    if(index >= 1) {
        temp.push_back(index);
        DFS(index, fac_cnt+1, n_sum+fac[index], fac_sum+index);
        temp.pop_back();
        DFS(index-1, fac_cnt, n_sum, fac_sum);
    }
    
}


int main()
{
    scanf("%d%d%d",&n, &k, &p);

    init();
    DFS(fac.size()-1, 0, 0, 0);

    if(g_max_fac_sum == -1) {
        printf("Impossible\n");
    }
    else {
        printf("%d = %d^%d", n, ans[0], p);
        for(int i = 1; i < ans.size(); ++i) {
            printf(" + %d^%d", ans[i], p);
        }
    }

    return 0;
    
}