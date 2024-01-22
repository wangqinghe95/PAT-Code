#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100010;

vector<int> ID[maxn];

int number_lowest = maxn;
int length_lowest = maxn;
vector<int> temp;

void DFS(int v)
{
    temp.push_back(v);
    if(ID[v].size() == 0) {
        if(temp.size() < length_lowest) {
            length_lowest = temp.size();
            number_lowest = 1;
        }
        else if (temp.size() == length_lowest) {
            number_lowest++;
        }
        temp.pop_back();
        return;
    }

    for(int i = 0; i < ID[v].size(); ++i) {
        DFS(ID[v][i]);
    }
    temp.pop_back();
}

int main()
{
    int n;
    double p, r;

    scanf("%d %lf %lf",&n, &p, &r);
    r /= 100;

    int k;
    int tempId;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&k);
        for(int j = 0; j < k; ++j) {
            scanf("%d", &tempId);
            ID[i].push_back(tempId);
        }
    }

    DFS(0);

    double min_price = p;
    for(int i = 0; i < length_lowest-1; ++i) {
        min_price *= (1+r);
    }

    printf("%.4f %d\n", min_price, number_lowest);

    return 0;
}
