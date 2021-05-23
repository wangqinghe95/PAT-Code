#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 26*26*26*10 + 1;

vector<int> selectCourse[maxn];

int getID(char *name);

int main()
{
	int n,k;
	scanf("%d%d", &n, &k);
	
	int courseID, stu_num;
	char name[5];
	int id;
	for (int i = 0 ; i < k; i++)
	{
		scanf("%d%d", &courseID, &stu_num);
		for (int j = 0; j < stu_num; j++)
		{
			scanf("%s", name);
			id = getID(name);
			selectCourse[id].push_back(courseID);
		}
	}	
	
	for (int i = 0 ; i < n; i++)
	{
		scanf("%s", name);
		id = getID(name);
		sort(selectCourse[id].begin(), selectCourse[id].end());
		
		int len = selectCourse[id].size();
		printf("%s %d", name, len);
		for (int j = 0; j < len; j++)
		{
			printf(" %d",selectCourse[id][j]);
		}
		printf("\n");
	}
	
	return 0;
} 

int getID(char *name)
{
	int id = 0;
	for (int i = 0; i < 3; i++)
	{
		id = id * 26 + (name[i] - 'A'); 
	}
	
	id = id * 10 + (name[3] - '0');
	return id;
}
