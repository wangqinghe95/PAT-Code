/*
* N 学生数 K 题目数 M 提交数
* 用户ID从00001-N 题目ID从1-K
* 
* 下一行是K个问题的满分数
* 
* 接下来 M 行 是提交信息表格式为：
* 用户id 题目ID 得分
* 其中得分 -1是提交但没有通过编译 [0-[full_mark]]
* 
* 对于每个实例，按照以下格式输出
* 排名 用户id 总分 每道题的分数
* 排名是根据总分排序，所有用户参与排序
* 没有提交的题目输出 - ， 一个用户一道题提交数次去最高分
* 排名按非递减顺序排列，排名相同的按满分数非递增排序
* 如果还相同就按照id递增排序
* 对于提交的代码没有通过数或者没有提交任何题目的人不参与排序
*/

#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn = 100010;

struct Person
{
    int id;
    int rank;
    int grade[6];
    int numFullMark;
    bool flag;
}stu[maxn];

void init(int n);
bool cmp(Person a, Person b);

int main()
{
    int n, k, m;
    int weight[6] = {0};
    scanf("%d%d%d", &n, &k, &m);

    init(n);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &weight[i]);
    }

    int id, ques, score;
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &id, &ques, &score);
        if (score != -1)
        {
            stu[id].flag = 1;
        }

        if (score == -1 && stu[id].grade[ques] == -1)
        {
            stu[id].grade[ques] = 0;
        }

        if (score > stu[id].grade[ques])
        {
            stu[id].grade[ques] = score;
            if (score == weight[ques])
            {
                stu[id].numFullMark++;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if(stu[i].grade[j] != -1)
            {
                stu[i].grade[0] += stu[i].grade[j];
            }
        }
    }

    sort(stu+1, stu+n+1, cmp);
    stu[1].rank = 1;
    for (int i = 1; i <= n; i++)
    {
        if(stu[i].flag == false)
        {
            continue;
        }

        if (i > 1 && stu[i].grade[0] == stu[i-1].grade[0])
        {
            stu[i].rank = stu[i-1].rank;
        }
        else
        {
            stu[i].rank = i;
        }
        printf("%d %05d", stu[i].rank, stu[i].id);
        for (int j = 0; j <= k; j++)
        {
            int grade = stu[i].grade[j];
            if (-1 == grade)
            {
                printf(" -");
            }
            else
            {
                printf(" %d", grade);
            }            
        }
        printf("\n");        
    }
    return 0;
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        stu[i].id = i;
        stu[i].numFullMark = 0;
        stu[i].rank = 0;
        memset(stu[i].grade, -1, sizeof(stu[i].grade));
        stu[i].grade[0] = 0;
        stu[i].flag = 0;
    }
}

bool cmp(Person a, Person b)
{
    if (a.flag != b.flag)
    {
        return a.flag > b.flag;
    }
    else if (a.grade[0] != b.grade[0])
    {
        return a.grade[0] > b.grade[0];
    }
    else if (a.numFullMark != b.numFullMark)
    {
        return a.numFullMark > b.numFullMark;
    }
    else
    {
        return a.id < b.id;
    }
}
