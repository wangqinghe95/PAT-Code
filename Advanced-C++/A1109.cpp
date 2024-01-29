#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

using namespace std;

const int maxn = 10010;

struct People
{
    char name[15];
    int height;
}peo[maxn];

/**
 * 后三个测试点时间超时
*/
namespace Solution_A
{
    int group[maxn][maxn] = {0};

    void storeRow(int row, int start, int end, int number_line)
    {
        int centric_point = number_line / 2;
        group[row][centric_point] = end;

        int right = centric_point+1;
        int left = centric_point-1;
        int index = end - 1;

        while (index >= start)
        {
            if (index >= start && left >= 0)
            {
                group[row][left--] = index--;
            }
            if(index >= start && right <= number_line-1) {
                group[row][right++] = index--;
            }
        }
    }
    void Solution()
    {
        int n, k;
        scanf("%d %d%*c",&n,&k);

        for(int i = 0; i < n; ++i) {
            scanf("%s %d%*c", peo[i].name, &peo[i].height);
        }

        auto cmp = [](People a, People b){
            if(a.height != b.height) {
                return a.height < b.height;
            }
            else {
                return strcmp(a.name, b.name) > 0;
            }
        };

        sort(peo, peo+n, cmp);

        int row = n / k;

        for(int i = 0; i < row-1; ++i) {
            storeRow(i,i*row,(i+1)*row-1,k);
        }
        storeRow(row-1,(row-1)*k,n-1, n%k+k );


        int number_last_row = k+n%k;
        for(int j = 0; j < number_last_row; ++j) {
            printf("%s", peo[group[row-1][j]].name);
            if(j < number_last_row-1) printf(" ");
            else printf("\n");
        }

        for(int i = row-2; i >= 0; --i) {
            for(int j = 0; j < k; j++) {
                printf("%s", peo[group[i][j]].name);
                if(j < k-1) printf(" ");
            }
            printf("\n");
        }
    }
}

namespace Solution_B
{
    bool cmp(People a, People b) 
    {
        if(a.height != b.height) {
            return a.height > b.height;
        }
        else {
            return strcmp(a.name, b.name) < 0;
        }
    }

    void printGroup(int start, int count)
    {
        int groupArr[count] = {0};
        groupArr[count/2] = start;

        int left = count/2 - 1;
        int right = count/2 + 1;

        int index = start + 1;
        while (left >= 0 || right < count)
        {
            if(left >= 0) groupArr[left--] = index++;
            if(right < count) groupArr[right++] = index++;
        }

        for(int i = 0; i < count; ++i) {
            printf("%s%c", peo[groupArr[i]].name, i == count-1 ? '\n' : ' ');
        }
        
    }
    void Solution() 
    {
        int n,k;
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; ++i) {
            scanf("%s %d", peo[i].name, &peo[i].height);
        }

        sort(peo, peo+n, cmp);

        int cnt = n/k;
        printGroup(0, cnt+n%k);
        for(int i = cnt+n%k; i < n ; i += cnt){
            printGroup(i, cnt);
        }
    }
}

int main()
{

    // Solution_A::Solution();
    Solution_B::Solution();
    return 0;
}