#include <cstdio>

using namespace std;
const int maxn = 100010;

struct Node
{
    int address;
    int val = -1;
    int next = -1;
}node[maxn];

void printNode(int node_num)
{
    if(node[node_num].next != -1)
        printf("%05d %d %05d\n", node[node_num].address, node[node_num].val, node[node_num].next);
    else 
        printf("%05d %d -1\n", node[node_num].address, node[node_num].val);
}

int main()
{
    int N, L1, L2;
    scanf("%d%d%d", &L1, &L2, &N);

    for(int i = 0; i < N; ++i) {
        int address;
        scanf("%d", &address);
        scanf("%d%d", &node[address].val, &node[address].next);
        node[address].address = address;
    }

    int length_L1 = 0, length_L2 = 0;

    int tmp = L1;
    while (tmp != -1)
    {
        length_L1++;
        tmp = node[tmp].next;
    }

    tmp = L2;
    while (tmp != -1)
    {
        length_L2++;
        tmp = node[tmp].next;
    }
    
    int shorter = -1, longer = -1;
    if(length_L2 >= 2 * length_L1) {
        shorter = L1;
        longer = L2;
    }
    else if(length_L1 >= 2 * length_L2) {
        shorter = L2;
        longer = L1;
    }
    else {
        return 0;
    }
    
    tmp = shorter;
    int pre = -1;
    while (tmp != -1)
    {
        int next = node[tmp].next;
        node[tmp].next = pre;
        pre = tmp;
        tmp = next;
    }

    shorter = pre;
    
    // printf("\n");

    int result = longer;
    while (shorter != -1)
    {
        longer = node[longer].next;
        int longer_next = node[longer].next;
        int shorter_next = node[shorter].next;

        node[longer].next = shorter;
        node[shorter].next = longer_next;
        longer = longer_next;
        shorter = shorter_next;
    }
    
    while (result != -1)
    {
        printf("%05d %d", result, node[result].val);
        if(node[result].next != -1) {
            printf(" %05d\n", node[result].next);
        }
        else {
            printf(" -1\n");
        }

        result = node[result].next;
    }
    
    return 0;
}