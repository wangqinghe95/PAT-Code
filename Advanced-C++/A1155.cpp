#include<cstdio>
#include<vector>
using namespace std;

const int maxn = 1010;

int heap[maxn] = {0};

int n;
bool bMaxHeap;
bool bHeap = true;

void DFS(vector<int>& path, int index)
{
    path.push_back(heap[index]);

    if(index * 2 + 1 >= n) {
        printf("%d", path[0]);
        for(int i = 1; i < path.size(); ++i) {
            printf(" %d", path[i]);
            if(bMaxHeap && path[i] > path[i-1]) bHeap = false;
            if(!bMaxHeap && path[i] < path[i-1]) bHeap = false;
        }
        printf("\n");
        path.pop_back();
        return;
    }
    
    if(index*2+2 < n)  DFS(path, index*2+2);
    if(index*2+1 < n)  DFS(path, index*2+1);

    path.pop_back();
}

int main()
{
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &heap[i]);
    }

    bMaxHeap = ((heap[0] >= heap[1]) && (heap[0] >= heap[2]));
    vector<int> path;
    DFS(path, 0);
    
    if(!bHeap) printf("Not Heap\n");
    else if(bMaxHeap) printf("Max Heap\n");
    else printf("Min Heap\n");

    return 0;
}