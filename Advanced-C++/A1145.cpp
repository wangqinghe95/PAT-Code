#include <cstdio>

bool isPrime(int num) 
{
    if(num <= 1) return false;
    for(int i = 2; i * i <= num; ++i) {
        if(num % i == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
    int MSize, N, M;
    scanf("%d%d%d", &MSize, &N, &M);

    while (!isPrime(MSize))
    {
        MSize++;
    }
    
    int* hashTable = new int[MSize];
    for(int i = 0; i < MSize; ++i) {
        hashTable[i] = -1;
    }

    int v;
    for(int i = 0; i < N; ++i) {
        scanf("%d", &v);
        int flag = false;
        for(int step = 0; step <= MSize; ++step) {
            int pos = (v+step*step) % MSize;
            if(hashTable[pos] == -1) {
                hashTable[pos] = v;
                flag = true;
                break;
            }
        }
        if(!flag) {
            printf("%d cannot be inserted.\n", v);
        }
    }

    int ans = 0;
    for(int i = 0; i < M; ++i) {
        scanf("%d", &v);
        bool flag = false;
        for(int step = 0; step <= MSize; ++step) {
            int pos = (v+step*step) % MSize;
            ans++;
            if(hashTable[pos] == v || hashTable[pos] == -1) {
                flag = true;
                break;
            }
        }
    }
    printf("%.1f\n", (double)ans/M);

    return 0;
}