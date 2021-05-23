/*
L   talent和virtue高于L才列入排序
H   都高于H sages 1
    virtue > H talen  < H  noblemen 2 
    virtue < H talent < H virtue < talent fool man  3
    rest    4
*/

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Person
{
    char ID[10];
    int virtual_grade;
    int talent_grade;
    int total_grade;
    int level;
}per[maxn];

bool cmp(Person a, Person b);

int main()
{
    int n, H, L;
    scanf("%d%d%d", &n, &L, &H);

    char name[10];
    int virutal;
    int talent;
    int valid = n;
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d", &per[i].ID, &per[i].virtual_grade, &per[i].talent_grade);
        per[i].total_grade = per[i].talent_grade + per[i].virtual_grade;
        if (per[i].virtual_grade < L || per[i].talent_grade < L)
        {
            per[i].level = 5;
            valid--;
        }
        else if (per[i].virtual_grade >= H && per[i].talent_grade >= H)
        {
            per[i].level = 1;
        }
        else if (per[i].virtual_grade >= H && per[i].talent_grade < H)
        {
            per[i].level = 2;
        }
        else if (per[i].virtual_grade >= per[i].talent_grade)
        {
            per[i].level = 3;
        }
        else
        {
            per[i].level = 4;
        }        
    }

    sort(per, per+n, cmp);

    printf("%d", valid);
    for (int i = 0; i < valid; i++)
    {
        printf("\n%s %d %d", per[i].ID, per[i].virtual_grade, per[i].talent_grade);
    }

    return 0;
}

bool cmp(Person a, Person b)
{
    if (a.level != b.level)
    {
        return a.level < b.level;
    }
    else if (a.total_grade != b.total_grade)
    {
        return a.total_grade > b.total_grade;
    }
    else if (a.virtual_grade != b.virtual_grade)
    {
        return a.virtual_grade> b.virtual_grade;
    }
    else
    {
        return strcmp(a.ID, b.ID) < 0;
    }    
}