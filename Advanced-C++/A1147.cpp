/**
 * 判断一个数组是否是堆
 * 方法1：深度遍历，判断当前节点和它的子节点大小之比
 * 方法2：直接遍历数组，使用 arr[v] 与 arr[v/2] 比较，不需要走遍历
*/

#include <cstdio>
#include <vector>

using namespace std;

bool judgeValidNum(int a, int b, bool isMaxHeap)
{
    if(isMaxHeap) return a >= b;
    else return a <= b;
}

bool judgeHeap(vector<int> &heap, int index ,bool isMaxHeap)
{
    bool is_left_heap = true;
    if(index * 2 + 1 < heap.size()) {
        if(judgeValidNum(heap[index], heap[index*2+1], isMaxHeap) == false) return false;
        if(judgeHeap(heap, index*2+1, isMaxHeap) == false) return false;
    }
    if(index * 2 + 2 < heap.size()) {
        if(judgeValidNum(heap[index], heap[index*2+2], isMaxHeap) == false) return false;
        if(judgeHeap(heap, index*2+2, isMaxHeap) == false) return false;
    }

    return true;  
}

void postOrder(vector<int>& heap, int index) {
    if(index >= heap.size()) {
        return;
    }

    postOrder(heap, index*2+1);
    postOrder(heap, index*2+2);

    static int cnt = 0;
    printf("%d%c", heap[index], cnt++ == heap.size() - 1 ? '\n' : ' ');
    if(cnt == heap.size()) cnt = 0;
}

int main()
{
    int m, n;
    scanf("%d%d", &m, &n);

    for(int i = 0; i < m; ++i) {
        vector<int> heap(n);
        for(int j = 0; j < n; ++j) {
            scanf("%d",&heap[j]);
        }
        bool bMaxHeap = heap[0] > heap[1] ? true : false;
        if(true == judgeHeap(heap, 0, bMaxHeap)) {
            printf("%s\n", bMaxHeap ? "Max Heap" : "Min Heap");
        }
        else {
            printf("Not Heap\n");
        }
        postOrder(heap, 0);
    }

    return 0;
}