#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100100;

struct Node
{
    int address;
    int data;
    int next;
    int primary;
}node[maxn];

bool cmp(Node& a, Node& b) {
    return a.primary < b.primary;
}

int main()
{
    int n,k, start;
    scanf("%d%d%d", &start, &n, &k);

    for(int i = 0; i < maxn; ++i) {
        node[i].primary = 2*maxn;
    }

    int address;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &address);
        scanf("%d%d", &node[address].data, &node[address].next);
        node[address].address = address;
    }

    int valid_cnt = 0;
    int index = start;
    while (index != -1)
    {
        if(node[index].data < 0) {
            node[index].primary = valid_cnt;
        }
        else if (node[index].data >= 0 && node[index].data <= k) {
            node[index].primary = valid_cnt + 1000;
        }
        else {
            node[index].primary = maxn + valid_cnt;
        }
        valid_cnt++;
        index = node[index].next;
    }
    
    sort(node, node+maxn, cmp);

    for(int i= 0; i < valid_cnt-1; ++i) {
        printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);   
    }

    printf("%05d %d -1\n", node[valid_cnt-1].address, node[valid_cnt-1].data);

    return 0;
}