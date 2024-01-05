// 存在有节点不在链表之中，所以在输出时不能直接使用 n 作为输出节点的个数
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

const int key_maxn = 10010;

struct Node
{
    int address;
    int data;
    int next;
    int order;
}node[maxn];

bool bDeduplication[key_maxn] = {0};

int getAbs(int a) {
    return a < 0 ? -a : a;
}

bool cmp(Node& a, Node& b) {
    return a.order < b.order;
} 

int main()
{
    int begin;
    int n;
    scanf("%d %d", &begin ,&n);

    for(int i = 0;  i < maxn; ++i) {
        node[i].order = 2*maxn;
    }

    int address;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&address);
        scanf(" %d %d",&node[address].data, &node[address].next);
        node[address].address = address;

    } 

    int start = begin;
    int count_valid = 0;
    int count_removed = 0;
    while (start != -1)
    {
        int data = getAbs(node[start].data);
        if(bDeduplication[data] == false) {
            bDeduplication[data] = true;
            node[start].order = count_valid++;
        }
        else {
            node[start].order = maxn+count_removed++;
        }
        start = node[start].next;
    }
    
    sort(node,node+maxn, cmp);

    int count = count_valid + count_removed;
    for(int i = 0; i < count; ++i) {
        if(i != count_valid-1 && i != count-1) {
            printf("%05d %d %05d\n", node[i].address, node[i].data, node[i+1].address);
        }
        else {
            printf("%05d %d -1\n", node[i].address, node[i].data);
        }
    }

    return 0;
}