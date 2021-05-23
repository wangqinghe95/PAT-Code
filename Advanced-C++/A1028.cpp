#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Student
{
	int id;
	char name[10];
	int grade;
}stu[maxn];

bool cmpID(Student a,Student b)
{
	return a.id < b.id;
}

bool cmpName(Student a,Student b)
{
	int s = strcmp(a.name,b.name);
	if(s != 0) 
		return s < 0;
	else
		return a.id < b.id;
}

bool cmpGrade(Student a,Student b)
{
	if(a.grade != b.grade)
		return a.grade < b.grade;
	else
		return a.id < b.id;
}

int main()
{
	int n;
	int c;
	scanf("%d%d",&n,&c);
	for(int i = 0; i < n; i++)
	{
		scanf("%d %s %d",&stu[i].id,stu[i].name,&stu[i].grade); //加了\n会出错，不知道为何
		//scanf("%d",&stu[i].id);
		//getchar();
		//scanf("%s %d",stu[i].name,&stu[i].grade);
	}
	switch(c)
	{
		case 1:
			sort(stu,stu+n,cmpID);
			break;
		case  2:
			sort(stu,stu+n,cmpName);
			break;
		case  3:
			sort(stu,stu+n,cmpGrade);
			break;			
	}
	for(int i = 0; i < n; i++)
	{
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].grade);
	}
	return 0;
}
