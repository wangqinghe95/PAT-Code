#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int maxn = 100010;
int n;
int max_depth;
double price, rate;
int max_number_retailer = 0;    // initial value must be zero
vector<int> path[maxn];
vector<int> tmpPath;

void DFS(int v)
{
    if(path[v].size() == 0) {
        double temp_price = price;
        if(tmpPath.size() > max_depth) {
            max_depth = tmpPath.size();
            max_number_retailer = 1;
        }
        else if (tmpPath.size() == max_depth) {
            max_number_retailer++;
        }

        return;
    }

    tmpPath.push_back(v);
    for(int i = 0; i < path[v].size(); ++i){
        DFS(path[v][i]);
    }
    tmpPath.pop_back();
}

int main()
{
    int index_root;
    scanf("%d%lf%lf", &n, &price, &rate);
    rate /= 100;
    for(int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        if(x == -1) {
            index_root = i;
            continue;
        }
        path[x].push_back(i);
    }

    DFS(index_root);
    double final_price = price;
    for(int i = 0; i < max_depth; ++i) {
        final_price *= (1+rate);
    }
    printf("%.2f %d\n", final_price, max_number_retailer);

    return 0;
}