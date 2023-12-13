#include <cstdio>
#include <string>
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using std::string;
using std::map;
using std::cin;
using std::cout;
using std::fill;
using std::vector;

const int MAXN = 210;
const int INF = 100000000;

int G[MAXN][MAXN];
int weight[MAXN];
int d[MAXN];
bool visited[MAXN] = {false};
map<string,int> city2Index;
map<int,string> index2City;

vector<int> pre[MAXN];
vector<int> path, tempPath;

int n,k;
int num = 0;
int maxWeight = 0;
double averageWeight = 0;

void Dijkstra(int s)
{
    fill(d,d+MAXN, INF);
    d[s] = 0;

    for(int i = 0; i < n; ++i) {
        int u = -1;
        int MIN = INF;
        for(int j = 0; j < n; ++j) {
            if(visited[j] == false && MIN > d[j]) {
                MIN = d[j];
                u = j;
            }
        }

        if(-1 == u) return;
        visited[u] = true;

        for(int v = 0; v < n; ++v) {
            if(d[v] > d[u] + G[u][v]) {
                d[v] = d[u] + G[u][v];
                pre[v].clear();
                pre[v].push_back(u);
            }
            else if(d[v] == d[u] + G[u][v]) {
                pre[v].push_back(u);
            }
        }
    }
}

void DFS(int v)
{
    if(0 == v) {
        tempPath.push_back(v);
        int tempWeight = 0;
        num++;
        for(int i = 0; i < tempPath.size(); ++i) {
            int id = tempPath[i];
            tempWeight += weight[id];
        }

        double tempAverageWeight = tempWeight * 1.0 / (tempPath.size()-1);
        if(tempWeight > maxWeight) {
            maxWeight = tempWeight;
            averageWeight = tempAverageWeight;
            path = tempPath;
        }
        else if (tempWeight == maxWeight && averageWeight < tempAverageWeight) {
            averageWeight = tempAverageWeight;
            path = tempPath;
        }
        tempPath.pop_back();
        return;
    }

    tempPath.push_back(v);
    for(int i = 0; i < pre[v].size(); ++i) {
        DFS(pre[v][i]);
    }
    tempPath.pop_back();
}

int main()
{
    string start, city1, city2;
    cin >> n >> k >> start;

    city2Index[start] = 0;
    index2City[0] = start;
    for(int i = 1; i < n; ++i) {
        cin >> city1 >> weight[i];
        city2Index[city1] = i;
        index2City[i] =  city1;
    }

    int cost = 0;
    fill(G[0], G[0]+MAXN*MAXN, INF);
    for(int i = 0; i < k; ++i) {
        cin >> city1 >> city2 >> cost;
        int c1 = city2Index[city1];
        int c2 = city2Index[city2];
        G[c1][c2] = G[c2][c1] = cost;
    }

    Dijkstra(0);
    int indexROM = city2Index["ROM"];
    DFS(indexROM);

    printf("%d %d %d %d\n", num, d[indexROM], maxWeight, (int)averageWeight);
    for(int i = path.size()-1; i >= 0 ; --i) {
        cout << index2City[path[i]];
        if(i > 0) cout << "->";
    }

    return 0;
}