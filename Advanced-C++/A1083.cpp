#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::sort;

const int maxn = 10010;

struct Student
{
    string name;
    string id;
    int grade;
}stu[maxn];

bool cmp(const Student& a, const Student& b)
{
    return a.grade > b.grade;
}

int main()
{
    int n;
    int grade1, grade2;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> stu[i].name >> stu[i].id >> stu[i].grade;
    }

    cin >> grade1 >> grade2;

    sort(stu, stu+n, cmp);

    bool bFlag = false;
    for(int i = 0; i < n; ++i) {
        if(stu[i].grade >= grade1 && stu[i].grade <= grade2) {
            cout << stu[i].name << " " << stu[i].id << endl;
            bFlag = true;
        }
    }

    if(!bFlag) {
        cout << "NONE" << endl;
    }

    return 0;
}