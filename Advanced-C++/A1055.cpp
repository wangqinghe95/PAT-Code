/*
给出N个人的财富数量，在一个年龄段中统计最富的M个人
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Person
{
    char name[10];
    int age;
    int worth;
}per[maxn];

bool cmp(Person a, Person b);

int main()
{
    int n, k;
    scanf("%d%d",&n, &k);

    char l_name[10];
    int l_age;
    int l_worth;
    int count = 0; //统计有效人数
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", l_name, &l_age, &l_worth);
        if (l_age > 0 && l_age <= 200)
        {
            count++;
            strcpy(per[i].name, l_name);
            per[i].age = l_age;
            per[i].worth = l_worth;
        }
    }

    sort(per, per+count, cmp);

    int m, min_age, max_age;
    int num_valid = 0;
    for (int i = 1; i <= k; i++)
    {
        scanf("%d%d%d", &m, &min_age, &max_age);
        printf("Case #%d:\n", i);
        num_valid = 0;
        for (int j = 0; j < count && num_valid < m; j++)
        {
            if (per[j].age >= min_age && per[j].age <= max_age && m > 0)
            {
                printf("%s %d %d\n", per[j].name, per[j].age, per[j].worth);
                num_valid++;
            }
        }
        if (num_valid == 0)
        {
            printf("None\n");
        }
    }
    return 0;
}

bool cmp(Person a, Person b)
{
    if (a.worth != b.worth)
    {
        return a.worth > b.worth;
    }
    else if (a.age != b.age)
    {
        return a.age < b.age;
    }
    else
    {
        return strcmp(a.name, b.name) < 0;
    }
    
}
