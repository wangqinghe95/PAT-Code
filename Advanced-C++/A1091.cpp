#include <cstdio>
#include <queue>
using namespace std;

int M,N,L,T;
int pixel[1290][130][61];
bool visited[1290][130][61] = {false};

struct Node
{
    int x,y,z;
};

int X[6] = {1,-1,0,0,0,0};
int Y[6] = {0,0,1,-1,0,0};
int Z[6] = {0,0,0,0,1,-1};

bool judge(int x,int y, int z) {
    if(x >= M || x < 0 || y >= N || y < 0 || z >= L || z < 0) {
        return false;
    }
    if(visited[x][y][z] == true || pixel[x][y][z] == 0) {
        return false;
    }

    return true;
}

int BFS(int x, int y, int z)
{
    Node node;
    node.x = x;
    node.y = y;
    node.z = z;

    queue<Node> que;
    que.push(node);
    visited[x][y][z] = true;

    int total = 0;
    while (!que.empty())
    {
        Node top = que.front();
        que.pop();

        total++;
        for(int i = 0; i < 6; ++i) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            int newZ = top.z + Z[i];

            if(judge(newX,newY,newZ)) {
                node.x = newX;
                node.y = newY;
                node.z = newZ;
                que.push(node);
                visited[newX][newY][newZ] = true;
            }
        }
    }

    if(total >= T) {
        return total;
    }
    return 0;
    
}

int main()
{
    scanf("%d%d%d%d",&M, &N, &L, &T);

    for(int z = 0; z < L; ++z) {
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; ++j) {
                scanf("%d",&pixel[i][j][z]);
            }
        }
    }

    int ans = 0;
    for(int z = 0; z < L; ++z) {
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; ++j) {
                if(pixel[i][j][z] == 1 && visited[i][j][z] == false) {
                    ans += BFS(i,j,z);
                }
            }
        }
    }

    printf("%d\n",ans);

    return 0;
}