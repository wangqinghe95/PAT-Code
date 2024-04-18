#include <cstdio>
#include <algorithm>
#include <map>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

namespace Solution_1
{
const int maxn = 100010;

struct Institution
{
    int number_stu ;
    double score_all ;
    string school_name;
    Institution(int num, double score,string name) : number_stu(num), score_all(score), school_name(name){}
    Institution(){}
}g_institu[maxn];

map<string,int> g_Institution2Inedx;

bool cmp(Institution& a, Institution& b) {
    if(a.score_all != b.score_all) return a.score_all > b.score_all;
    else if(a.number_stu != b.number_stu) return a.number_stu < b.number_stu;
    else return a.school_name < b.school_name;
}

void Solution()
{
    int n;
    scanf("%d", &n);

    double score;
    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        char ID[8] = {0};
        char school[8] = {0};        
        scanf("%*c%s %lf %s",ID, &score, school);
        for(int j = 0; j < strlen(school); ++j) {
            if(school[j] >= 'A' && school[j] <= 'Z') {
                school[j] = school[j] - 'A' + 'a';
            }
        }

        if(ID[0] == 'B') score /= 1.5;
        else if(ID[0] == 'T') score *= 1.5;
        else {}

        if(g_Institution2Inedx.find(school) == g_Institution2Inedx.end()) {
            Institution tmp(1, score, school);
            g_institu[cnt] = tmp;
            g_Institution2Inedx[school] = cnt++;
        }
        else {
            Institution& tmp = g_institu[g_Institution2Inedx[school]];
            tmp.score_all += score;
            tmp.number_stu++;
        }        
        /*
        auto it = g_Institution2Inedx.find(school);
        int index = 0;
        if(it != g_Institution2Inedx.end()) {
            index = g_Institution2Inedx[school];
            // index = it->second;
        }
        else {
            index = g_Institution2Inedx.size();
            g_institu[index].school_name = school;
            g_Institution2Inedx[school] = index;
        }
        g_institu[index].number_stu++;
        if(ID[0] == 'B') g_institu[index].score_all += score/1.5;
        else if(ID[0] == 'A') g_institu[index].score_all += score;
        else if(ID[0] == 'T') g_institu[index].score_all += score*1.5;
        */
    }

    // int size = g_Institution2Inedx.size();
    printf("%d %d", cnt, (int)g_Institution2Inedx.size());
    int size = cnt--;
    printf("%d\n", size);

    // 在这里强转成int，第 1，5 测试点不过
    // 在后面强转，第 5 测试点不过
    // 都没问题，是 cmp 内部有误
    for(int i = 0; i < size; i++){
        // g_institu[i].score_all = (int)(g_institu[i].score_all);
        g_institu[i].score_all = static_cast<int>(g_institu[i].score_all);
    }
    sort(g_institu, g_institu+size, cmp);

    int rank = 1;

    // g_institu[0].score_all = (int)g_institu[0].score_all;
    printf("%d %s %d %d\n",rank, g_institu[0].school_name.data(), (int)g_institu[0].score_all, g_institu[0].number_stu);

    for(int i = 1; i < size; ++i) {
        // g_institu[i].score_all = (int)g_institu[i].score_all;
        if(g_institu[i].score_all != g_institu[i-1].score_all) {
            rank = i+1;
        }
        printf("%d %s %d %d\n",rank, g_institu[i].school_name.data(), (int)g_institu[i].score_all, g_institu[i].number_stu);

    }
}

}

namespace Solution_2
{
struct School
{
    int m_number;
    double m_grade;
    string m_name;
    School(int num, double grade, string name): m_number(num), m_grade(grade), m_name(name){}
    bool operator<(const School& a) const {
        if(m_grade != a.m_grade) return m_grade > a.m_grade;
        else if(m_number != a.m_number) return m_number < a.m_number;
        else return m_name < a.m_name;
    } 

};

bool cmp(School& a, School& b) {
    if(a.m_grade != b.m_grade) return a.m_grade > b.m_grade;
    else if(a.m_number != b.m_number) return a.m_number < b.m_number;
    else return a.m_name < b.m_name;
}

void Solution()
{
    int n;
    scanf("%d", &n);

    double score;
    
    vector<School> sch;
    map<string, int> mp_institution2index;
    
    int index = 0;
    for(int i = 0; i < n; ++i) {
        char str[8] = {0};
        char id[8] = {0};
        scanf("%*c%s %lf %s", id, &score, str);
        for(int j = 0; j < strlen(str); ++j) {
            if(str[j] >= 'A' && str[j] <= 'Z') {
                str[j] = str[j] - 'A' + 'a';
            }
        }

        if(id[0] == 'B') score /= 1.5;
        else if(id[0] == 'T') score *= 1.5;
        else {}

        if(mp_institution2index.find(str) == mp_institution2index.end()) {
            School tmp(1, score, str);
            sch.push_back(tmp);
            mp_institution2index[str] = index++;
        }
        else {
            School& tmp = sch[mp_institution2index[str]];
            tmp.m_grade += score;
            tmp.m_number++;
        }
    }


    for(int i = 0; i < sch.size(); ++i) {
        sch[i].m_grade = static_cast<int>(sch[i].m_grade);
    }

    // sort(sch.begin(), sch.end(),cmp);
    sort(sch.begin(), sch.end());

    int rank = 1;
    printf("%d\n", (int)sch.size());
    printf("%d %s %d %d\n", rank, sch[0].m_name.data(), (int)sch[0].m_grade, sch[0].m_number);
    for(int i = 1; i < sch.size(); ++i) {
        if(sch[i].m_grade != sch[i-1].m_grade) {
            rank = i+1;
        }
        printf("%d %s %d %d\n", rank, sch[i].m_name.data(), (int)sch[i].m_grade, sch[i].m_number);
    }
}

}

int main()
{
    Solution_1::Solution();
    // Solution_2::Solution();

    return 0;
}