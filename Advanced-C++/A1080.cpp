#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Student
{
    int stu_index;
    int perfered[3];
    int GE,GI;
    double grade;
};

struct School
{
    int num_quota;
    vector<Student> stu_admited;
};

bool cmpGrade(Student a, Student b) {
    if (a.grade != b.grade) return a.grade > b.grade;
    else return a.GE > b.GE;
}

bool cmpIndex(Student a, Student b) {
    return a.stu_index < b.stu_index;
}

int main()
{
    int n,m,k;
    cin >> n >> m >> k;

    vector<School> vec_sch;
    int temp = 0;
    for(int i = 0; i < m; ++i) {
        School sch;
        cin >> temp;
        sch.num_quota = temp;
        vec_sch.push_back(sch);
    }

    Student stu;
    vector<Student> vec_stu;
    for(int i = 0 ; i < n; ++i) {
        stu.stu_index = i;
        cin >> stu.GE >> stu.GI;
        for(int j = 0; j < k; ++j) {
            cin >> stu.perfered[j];
        }
        stu.grade = stu.GE + stu.GI;
        vec_stu.push_back(stu);
    }

    sort(vec_stu.begin(), vec_stu.end(), cmpGrade);
    for(int i = 0; i < n; ++i){
        Student cur_stu = vec_stu[i];
        for(int j = 0; j < k; ++j) {
            int sch_index = cur_stu.perfered[j];
            School& preferred_sch = vec_sch[sch_index];

            if(preferred_sch.num_quota > preferred_sch.stu_admited.size()) {
                vec_sch[sch_index].stu_admited.push_back(cur_stu);
                break;
            }
            else{
                Student& last_admited_stu = preferred_sch.stu_admited.back();
                if(cur_stu.grade == last_admited_stu.grade && cur_stu.GE == last_admited_stu.GE) {
                    preferred_sch.stu_admited.push_back(cur_stu);
                    break;
                }
            }
        }
    }

    for(int i = 0; i < m; ++i) {
        School& cur_sch = vec_sch[i];
        sort(cur_sch.stu_admited.begin(), cur_sch.stu_admited.end(), cmpIndex);
        for(int j = 0; j < cur_sch.stu_admited.size(); ++j) {
            cout << cur_sch.stu_admited[j].stu_index;
            if(j < cur_sch.stu_admited.size()-1){
                cout << " ";
            }
        }
        cout << endl;

    }

    return 0;
}