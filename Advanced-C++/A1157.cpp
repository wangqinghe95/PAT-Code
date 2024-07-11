#include <cstdio>
#include <map>
#include <string>
using namespace std;

int getAge(const char* p)
{
    int age = 0;
    for(int i = 6; i < 14; ++i) {
        age = age * 10 + (p[i] - '0');
    }
    return age;
}

int main()
{
    map<string, bool> mp_alumni;
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        char ID[24] = {0};
        scanf("%*c%s", ID);
        mp_alumni[ID] = true;
    }

    int m;
    int oldest_all = 20200000;
    int oldest_alumni = 20200000;
    int cnt_alumni = 0;
    string string_oldest_all, string_oldest_alunmi;

    scanf("%d", &m);
    for(int i = 0; i < m; ++i) {
        char ID[24] = {0};
        scanf("%*c%s", ID);

        int cur_age = getAge(ID);
        if(mp_alumni[ID] == true) {
            cnt_alumni++;
            if(cur_age < oldest_alumni) {
                oldest_alumni = cur_age;
                string_oldest_alunmi.clear();
                string_oldest_alunmi = ID;
            }
        }

        if(cur_age < oldest_all){
            oldest_all = cur_age;
            string_oldest_all.clear();
            string_oldest_all = ID;
        }
    }

    printf("%d\n%s\n", cnt_alumni, cnt_alumni == 0 ? string_oldest_all.data() : string_oldest_alunmi.data());
    return 0;
}