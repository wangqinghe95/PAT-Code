// C++ 版本，但是 STL + string 会导致一个测试点时间超限 
// https://pintia.cn/problem-sets/994805342720868352/exam/problems/994805371602845696?type=7&page=0
// cin 和 cout 影响程序的运行时间性能，替换成 scanf 和 printf
#include <map>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdio>

using namespace std;

const int maxn = 10010;

struct Car
{
    string id;
    string status;
    int time_stamp;
};

struct ValidCar
{
    string id;
    int start_time;
    int end_time;
};

int convertTime2int(const string& str_time)
{
    int hh = stoi(str_time.substr(0,2));
    int mm = stoi(str_time.substr(3,2));
    int ss = stoi(str_time.substr(6,2));
    return hh*3600 + mm*60 + ss;    
}

bool cmp(Car& a, Car& b) 
{
    if(a.id != b.id) return a.id < b.id;
    else return a.time_stamp < b.time_stamp;
}

bool cmpValid(ValidCar& a, ValidCar& b) 
{
    return a.start_time < b.start_time;
}

int main()
{
    int n,m;
    // cin >> n >> m;

    scanf("%d%d\n",&n,&m);

    // string id, str_time, status;

    char id[8] = {0};
    char str_time[10] = {0};
    char status[4] = {0};

    vector<Car> park;
    for(int i = 0; i < n; ++i) {
        // cin >> id >> str_time >> status;
        scanf("%s %s %s\n", id, str_time, status);
        Car tmp_car;
        tmp_car.id = id;
        tmp_car.status = status;
        tmp_car.time_stamp = convertTime2int(str_time);
        park.push_back(tmp_car);
    }

    sort(park.begin(), park.end(), cmp);

    vector<ValidCar> valid;
    map<string, int> park_time;
    int max_time = -1;
    for(int i = 0; i < n-1; ++i) {
        if(park[i].id == park[i+1].id && park[i].status == "in" && park[i+1].status == "out") {
            ValidCar tmp_valid_car;
            tmp_valid_car.id = park[i].id;
            tmp_valid_car.start_time = park[i].time_stamp;
            tmp_valid_car.end_time = park[i+1].time_stamp;
            valid.push_back(tmp_valid_car);

            if(park_time.find(tmp_valid_car.id) == park_time.end()) {
                park_time[tmp_valid_car.id] = (tmp_valid_car.end_time - tmp_valid_car.start_time);
            }
            else {
                park_time[tmp_valid_car.id] += (tmp_valid_car.end_time - tmp_valid_car.start_time);
            }

            max_time = park_time[tmp_valid_car.id] > max_time ? park_time[tmp_valid_car.id] : max_time;
        }
    }

    sort(valid.begin(), valid.end(), cmpValid);

    char c;
    for(int i = 0; i < m; ++i) {
        // cin >> str_time;
        scanf("%s%c", str_time, &c);
        int tmp_stamp = convertTime2int(str_time);
        int number_cars = 0;
        for(int j = 0; j < valid.size(); ++j) {
            if(valid[j].start_time <= tmp_stamp && valid[j].end_time > tmp_stamp){
                number_cars++;
            }
        }
        // cout << number_cars << endl;
        printf("%d\n", number_cars);
    }

    for(auto it = park_time.begin(); it != park_time.end(); ++it) {
        if(it->second == max_time) {
            // cout << it->first << " ";
            printf("%s ", it->first.data());
        }
    }

    // cout << setfill('0') << setw(2) << max_time/3600 << ":" << setfill('0') << setw(2) << max_time%3600/60 << ":" << setfill('0') << setw(2) << max_time%60 << endl;
    printf("%02d:%02d:%02d\n", max_time/3600, (max_time- (max_time/3600)*3600)/60, max_time%60);
    return 0;
}