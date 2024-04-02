#include <cstdio>
#include <map>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int maxn = 10010;

struct Student
{
    int grade_program;
    int grade_mid = -1;
    int grade_final = -1;
    int grade_all;
    string stu_ID;    
}stu[maxn];

map<string, int> mp;

bool cmp(Student &a, Student& b)
{
    if(a.grade_all != b.grade_all) {
        return a.grade_all > b.grade_all;
    }
    else {
        return (a.stu_ID < b.stu_ID);
    }
}

int main()
{
    int P, M, N;
    scanf("%d%d%d%*c", &P, &M, &N);

    int n_grade;

    for(int i = 0; i < P; ++i) {
        char str_ID[32] = {0};

        scanf("%s %d%*c", str_ID, &n_grade);
        if(n_grade >= 200) {
            stu[i].grade_program = n_grade;
            stu[i].stu_ID = str_ID;
            mp[stu[i].stu_ID] = i;
        }
    }

    for(int i = 0; i < M; ++i) {
        char str_ID[32] = {0};
        scanf("%s %d%*c", str_ID, &n_grade);
        if(mp.find(str_ID) != mp.end()) {
            stu[mp[str_ID]].grade_mid = n_grade;
        }
    }

    for(int i = 0; i < N; ++i) {
        char str_ID[32] = {0};
        scanf("%s %d%*c", str_ID, &n_grade);
        if(mp.find(str_ID) != mp.end()) {
            int index = mp[str_ID];
            stu[index].grade_final = n_grade;
            if(stu[index].grade_mid > stu[index].grade_final) {
                stu[index].grade_all = int(stu[index].grade_mid * 0.4 + stu[index].grade_final * 0.6 + 0.5);
            }
            else {
                stu[index].grade_all = stu[index].grade_final;
            }
        }
    }

    sort(stu, stu+P, cmp);

    for(int i = 0; i < P; ++i) {
        if(stu[i].grade_program < 200 || stu[i].grade_all < 60)  break;
        printf("%s %d %d %d %d\n", stu[i].stu_ID.data(), stu[i].grade_program, stu[i].grade_mid, stu[i].grade_final, stu[i].grade_all);
    }

    return 0;
}