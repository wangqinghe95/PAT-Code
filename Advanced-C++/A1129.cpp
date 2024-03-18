/**
 * 如何对一对数据中的 key 和 value 排序，且 value 可能还会变化
 * 如果用 map，map 如何保证 value 和 key 排序，且排序后还能找的到 key
*/
#include <cstdio>
#include <set>

using namespace std;

struct Item
{
    int key, value;
    bool operator<(const Item& item) const{ // error if there is no later const
        if(value != item.value) {
            return value > item.value;
        }
        else return key < item.key;
    }
};

int fre_accessed[50001] = {0};

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);

    set<Item> items;
    int v;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &v);
        if(i != 0) {
            printf("%d:", v);
            int temp_cnt = 0;
            for(auto it = items.begin(); temp_cnt++ < k && it != items.end(); ++it) {
                printf(" %d", it->key);
            }
            printf("\n");
        }

        auto it = items.find(Item{v, fre_accessed[v]});
        if( it != items.end()) {
            items.erase(it);
        }

        fre_accessed[v]++;
        items.insert(Item{v, fre_accessed[v]});
    }

    return 0;
}