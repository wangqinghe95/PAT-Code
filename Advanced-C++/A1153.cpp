#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>
#include <string>
#include <iostream>

using namespace std;

// 测试点 1、4 未过，不知道原因
namespace Solution_1
{

const int maxn = 100010;

struct Testee
{
    char level;
    int test_site_number;
    int test_date;
    int testee_number;
    int score;
    char card_number[16];
}testee[maxn];

struct SiteInfo
{
    int site_number;
    int site_cnt;
};

int N, M;


int convert2Int(const char* p, int start, int end)
{
    int res = 0;
    for(int i = start; i <= end; ++i) {
        res = res * 10 + (p[i] - '0');
    }
    return res;
}

bool cmp(Testee &a, Testee &b)
{
    if(a.score != b.score)  return a.score > b.score;
    else return strcmp(a.card_number,b.card_number) < 0;
}

bool cmpSite(SiteInfo& a, SiteInfo &b)
{
    if(a.site_cnt != b.site_cnt) return a.site_cnt > b.site_cnt;
    else return a.site_number < b.site_number;
}

void handleCase1(char c)
{
    vector<Testee> ans;
    for(int i = 0; i < N; ++i) {
        if(testee[i].level == c) {
            ans.push_back(testee[i]);
        }
    }
    if(ans.size() != 0) {
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); ++i) {
            printf("%s %d\n", ans[i].card_number, ans[i].score);
        }
    }
    else {
        printf("NA\n");
    }
}

void handleCase2(int site_num)
{
    int cnt = 0;
    int score = 0;
    for(int i = 0; i  < N; ++i) {
        if(testee[i].test_site_number == site_num) {
            cnt++;
            score += testee[i].score;
        }
    }
    if(cnt != 0) printf("%d %d\n", cnt, score);
    else printf("NA\n");
}

void handleCase3(int date)
{
    map<int,int> sitenumber2index;
    for(int i = 0; i < N; ++i) {
        if(testee[i].test_date == date) {
            sitenumber2index[testee[i].test_site_number]++;
        }
    }

    if(sitenumber2index.empty() == false) {
        vector<SiteInfo> ans;
        for(auto &it : sitenumber2index) {
            ans.push_back({it.first, it.second});
        }

        sort(ans.begin(), ans.end(), cmpSite);
        for(int i = 0; i < ans.size(); ++i) {
            printf("%d %d\n", ans[i].site_number, ans[i].site_cnt);
        }
    }
    else {
        printf("NA\n");
    }
}

void Solution()
{
    scanf("%d%d",&N,&M);

    for(int i = 0; i < N; i++){
        scanf("%*c%s %d", testee[i].card_number, &testee[i].score);
        testee[i].level = testee[i].card_number[0];
        testee[i].test_site_number = convert2Int(testee[i].card_number, 1, 3);
        testee[i].test_date = convert2Int(testee[i].card_number, 4, 9);
        testee[i].testee_number = convert2Int(testee[i].card_number, 10, 12);
    }

    for(int i = 1; i <= M; ++i) {
        int type;
        scanf("%d", &type);
        switch (type)
        {
        case 1:
        {
            char c;
            scanf("%*c%c", &c);
            printf("Case %d: %d %c\n", i, type, c);
            handleCase1(c);
            break;
        }
        case 2:
        {
            int site;
            scanf("%d", &site);
            printf("Case %d: %d %d\n", i, type, site);
            handleCase2(site);
            break;
        }
        case 3:
        {
            int date;
            scanf("%d", &date);
            printf("Case %d: %d %d\n", i, type, date);
            handleCase3(date);
            break;
        }
         
        default:
            break;
        }
    }
}
}

namespace Solution_2
{

const int maxn = 10010;

int N,M;

struct Testee_Tag
{
    int m_score;
    string m_site_number;
    string m_date;
    string m_card_number;
}Testee[10010];

struct Node 
{
    string site_index;
    int testee_cnt;
    Node(string _index, int _cnt) : site_index(_index), testee_cnt(_cnt){}
};

bool cmp(Testee_Tag& a, Testee_Tag& b)
{
    if(a.m_score != b.m_score) return a.m_score > b.m_score;
    else return a.m_card_number < b.m_card_number;
}

bool cmpNode(Node& a, Node& b)
{
    if(a.testee_cnt != b.testee_cnt) return a.testee_cnt > b.testee_cnt;
    else return a.site_index < b.site_index;
}

void handleCase1(string &para)
{
    vector<Testee_Tag> ans;
    for(int i = 0; i < N; ++i) {
        if(Testee[i].m_card_number[0] == para[0]) {
            ans.push_back(Testee[i]);
        }
    }

    if(ans.size() != 0) {
        sort(ans.begin(), ans.end(), cmp);
        for(int i = 0; i < ans.size(); ++i) {
            printf("%s %d\n", ans[i].m_card_number.data(), ans[i].m_score);
        }
    }
    else {
        printf("NA\n");
    }

}

void handleCase2(string& parameters)
{
    int total_cnt = 0;
    int total_score = 0;
    for(int i = 0; i < N; ++i) {
        if(Testee[i].m_site_number == parameters) {
            total_cnt++;
            total_score += Testee[i].m_score;
        }
    }

    if(total_cnt != 0) {
        printf("%d %d\n", total_cnt, total_score);
    }
    else {
        printf("NA\n");
    }
}

void handleCase3(string& parameters)
{
    map<string,int> mp;
    for(int i = 0; i < N; ++i) {
        if(Testee[i].m_date == parameters) {
            mp[Testee[i].m_site_number]++;
        }
    }

    if(mp.empty() == false) {
        vector<Node> res;
        for(auto &it : mp) {
            res.push_back(Node(it.first,it.second));
        }
        sort(res.begin(), res.end(), cmpNode);
        for(auto & it : res) {
            printf("%s %d\n", it.site_index.data(), it.testee_cnt);
        }
    }
    else {
        printf("NA\n");
    }
}

void Solution()
{
    // scanf("%d%d", &N, &M);
    cin >> N >> M;
    for(int i = 0; i < N; ++i) {
        cin >> Testee[i].m_card_number >> Testee[i].m_score;
        Testee[i].m_site_number = (Testee[i].m_card_number.substr(1,3));
        Testee[i].m_date = (Testee[i].m_card_number.substr(4,6));
    }

    for(int i = 1; i <= M; ++i) {
        int command;
        string parameters;
        cin >> command >> parameters;
        cout << "Case " << i << ": " << command << " " << parameters << endl;
        switch (command)
        {
        case 1:
            handleCase1(parameters);
            break;
        case 2:
            handleCase2(parameters);
            break;
        case 3:
            handleCase3(parameters);
            break;
        }
    }
}
}

int main()
{
    // Solution_1::Solution();
    Solution_2::Solution();
    return 0;
}