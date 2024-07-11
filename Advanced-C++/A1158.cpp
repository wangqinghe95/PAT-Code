/**
 * 每天给不同人打 K 个 短电话，但是只有 20% 的电话会被回拨的人被认为是诈骗分子
 * 如果两个诈骗分子互相拨打电话，那么他们就是一个同伙。
 * 5 min 以内的电话被认为是短电话，<= 5 min 都是属于短电话
 * 
 * 3 个整数，K 短电话个数的阈值，N 不同电话号码的个数，M，电话记录
 * M 行电话记录格式如下：
 * caller receiver duration
 * caller 和 receiver 的编号都是从 1 到 N，持续时间一天不超过 1400 mins
 * 
 * 每一行打印一个犯罪组织的所有诈骗分子，编号升序打印
 * 犯罪组织以第一个成员的编号命名，犯罪组织以升序排序
 * 
 * 额外注意：
 * 
*/

#include <cstdio>
#include <map>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * 21/25
 * 最后一个测试点未过
*/
namespace solution_1
{

const int maxn = 1100;
int g_recorded[maxn][maxn] = {0};
int K, N, M;

bool isSuspects(int index)
{
    int number_call_shorter = 0;
    int number_call_back = 0;
    for(int i = 1; i <= N; ++i) {
        if(g_recorded[index][i] > 0 && g_recorded[index][i] <= 5) {
            number_call_shorter++;
            if(g_recorded[i][index] != 0) {
                number_call_back++;
            }
        }
    }

    return number_call_shorter > K && number_call_back * 5 <= (number_call_shorter);
}

int findFather(vector<int>& father, int x)
{
    int f = x;
    while (f != father[f])
    {
        f = father[f];
    }

    while (x != father[x])
    {
        int z = x;
        x = father[x];
        father[z] = f;
    }
    
    return f;
/*
    int a = x;
    while (a != gangs[a])
    {
        a = gangs[a];
    }

    while (x != gangs[x])
    {
        int z = x;
        x = gangs[x];
        gangs[z] = a;
        // int z = gangs[x];
        // gangs[x] = a;
        // x = z;
    }

    return a;   
*/    
}

void Union(vector<int>& gangs, int x, int y)
{
    int f1 = findFather(gangs,x);
    int f2 = findFather(gangs,y);
    if(f1 > f2) gangs[f1] = f2;
    else gangs[f2] = f1;
}

void Unify(vector<int>& father, int x)
{
    int f = x;
    while (f != father[f])
    {
        f = father[f];
    }

    while (x != father[x])
    {
        int z = x;
        x = father[x];
        father[z] = f;
    }
}

int Solution_1()
{
    scanf("%d%d%d", &K, &N, &M);

    int caller, receiver, duration;
    for(int i = 0; i < M; ++i) {
        scanf("%d%d%d", &caller, &receiver, &duration);
        g_recorded[caller][receiver] += duration;
    }

    vector<int> suspects;
    vector<int> gangs(N+1,0);

    for(int i = 1; i <= N; ++i) {
        if(isSuspects(i)) {
            suspects.push_back(i);
            gangs[i] = i;
        }
    }

    if(suspects.empty()) printf("None\n");

    for(int i = 0; i < suspects.size(); ++i) {
        for(int j = i+1; j < suspects.size(); ++j) {
            if(g_recorded[suspects[i]][suspects[j]] != 0 && g_recorded[suspects[j]][suspects[i]] != 0) {
                Union(gangs,suspects[i], suspects[j]);
            }            
        }
    }

    for(int i = 0; i < suspects.size(); ++i) {
        Unify(gangs, suspects[i]);
    }

    while (suspects.empty() == false){
        vector<int> tmp;
        int index = 0;
        printf("%d", suspects[index]);
        for(int j = index+1; j < suspects.size(); ++j) {
            if(gangs[suspects[j]] == gangs[suspects[index]]) {
            // if(findFather(gangs,suspects[index]) == findFather(gangs,suspects[j])) {
                printf(" %d", suspects[j]);
            }
            else {
                tmp.push_back(suspects[j]);
            }
        }
        printf("\n");
        swap(suspects, tmp);
    }
/*
    vector<vector<int>> gangs;
    while (suspects.empty() == false){
        int i = 0;
        vector<int> gang;
        vector<int> temp;
        gang.push_back(suspects[i]);
        for(int j = i + 1; j < suspects.size(); ++j) {
            if(g_recorded[suspects[i]][suspects[j]] != 0 && g_recorded[suspects[j]][suspects[i]] != 0) {
                gang.push_back(suspects[j]);
            }
            else {
                temp.push_back(suspects[j]);
            }
        }
        gangs.push_back(gang);
        swap(suspects, temp);
    }

    for(int i = 0; i < gangs.size(); ++i) {
        for(int j = 0; j < gangs[i].size(); ++j) {
            printf("%d%c", gangs[i][j], j == gangs[i].size()-1 ? '\n' : ' ');
        }
    }
*/
    return 0;    
}

int Solution()
{
    scanf("%d%d%d", &K, &N, &M);

    int caller, receiver, duration;
    for(int i = 0; i < M; ++i) {
        scanf("%d%d%d", &caller, &receiver, &duration);
        g_recorded[caller][receiver] += duration;
    }

    set<int> suspects;
    for(int i = 1; i <= N; ++i) {
        if(isSuspects(i)) {
            suspects.insert(i);
        }
    }

    if(suspects.empty()) printf("None\n");

    auto it = suspects.begin();
    while(it != suspects.end()) {

        printf("%d", *it);

        auto next_it = std::next(it);
        while(next_it != suspects.end()) {
            // if(g_recorded[*it][*next_it] != 0 && g_recorded[*next_it][*it] != 0) {   // 测试 2 未过
            if(g_recorded[*it][*next_it] != 0) {            // 测试点 4 未过
                printf(" %d", *next_it);
                next_it = suspects.erase(next_it);
            }
            else {
                next_it++;
            }
        }
        it = suspects.erase(it);

        if(it != suspects.end()) printf("\n");
    }

    return 0;
}

}

int main()
{
    solution_1::Solution_1();
    return 0;
}