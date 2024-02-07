#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10100;

int g_householders[maxn] = {0};
int g_estates[maxn] = {0};
int g_areas[maxn] = {0};
int n;

struct Family
{
    int m_householderId = -1;
    int m_member_cnt = 0;
    int m_sum_estates = 0;
    int m_sum_areas = 0;

    double m_average_estate = 0;
    double m_average_areas = 0;
}family[maxn];

void initID(int id)
{
    if(g_householders[id] == -1) {
        g_householders[id] = id;
    }
}

int findHouseholder(int x)
{
    int householderId = x;
    while (householderId != g_householders[householderId])
    {
        householderId = g_householders[householderId];
    }

    while (x != g_householders[x])
    {
        int f = x;
        x = g_householders[x];
        g_householders[f] = householderId;
    }

    return householderId;
}

void unionFamily(int a, int b)
{
    int faA = findHouseholder(a);
    int faB = findHouseholder(b);
    if(faA != faB) {
        int smaller = faA > faB ? faB : faA;
        int larger = faA + faB - smaller;
        g_householders[larger] = smaller;
    }
}

bool cmp(Family a, Family b)
{
    if(a.m_average_areas != b.m_average_areas) {
        return a.m_average_areas > b.m_average_areas;
    }
    else {
        return a.m_householderId < b.m_householderId;
    }
}

int main()
{
    scanf("%d", &n);
    memset(g_householders, -1, sizeof(g_householders));

    int ID, fatherId, motherId, k, childId;
    for(int i = 0 ; i < n; ++i) {
        scanf("%d %d %d %d", &ID, &fatherId, &motherId, &k);
        if(g_householders[ID] == -1) {
            g_householders[ID] = ID;
        }

        if(fatherId != -1) {
            initID(fatherId);
            unionFamily(ID, fatherId);
        }
        if(motherId != -1) {
            initID(motherId);
            unionFamily(ID, motherId);
        }

        for(int j = 0; j < k; ++j) {
            scanf("%d", &childId);
            initID(childId);
            unionFamily(ID, childId);
        }

        scanf("%d %d", &g_estates[ID], &g_areas[ID]);
    }

    for(int i = 0; i < maxn; ++i) {
        if(g_householders[i] != -1){
            int householderId = findHouseholder(i);
            family[householderId].m_householderId = householderId;
            family[householderId].m_member_cnt++;
            family[householderId].m_sum_areas += g_areas[i];
            family[householderId].m_sum_estates += g_estates[i];
        }
    }

    int family_number = 0;
    for(int i = 0; i < maxn; ++i) {
        if(family[i].m_householderId != -1) {
            family_number++;
            family[i].m_average_estate = 1.0*family[i].m_sum_estates/family[i].m_member_cnt;
            family[i].m_average_areas = 1.0*family[i].m_sum_areas/family[i].m_member_cnt;
        }
    }

    sort(family, family + maxn, cmp);

    printf("%d\n",family_number);
    for(int i = 0; i < family_number; ++i) {
        printf("%04d %d %.3f %.3f\n", family[i].m_householderId
                                    , family[i].m_member_cnt
                                    , family[i].m_average_estate
                                    , family[i].m_average_areas);
    }

    return 0;
}