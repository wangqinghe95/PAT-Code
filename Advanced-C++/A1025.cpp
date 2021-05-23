#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 30010;

struct Student
{
	char id[15];
	int score;
	int location;
	int local_rank;
}stu[maxn];

bool cmp(Student a,Student b)
{
	if(a.score != b.score) return a.score > b.score;
	else return strcmp(a.id,b.id) < 0;
}

int main()
{
	int n,k;
	int num = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d",&k);
		for(int j = 0; j < k; j++)
		{
			//count the number of student from 0
			scanf("%s%d",stu[num].id,&stu[num].score);
			stu[num].location = i;
			num++;	
		}
		sort(stu+num-k,stu+num,cmp);
		stu[num-k].local_rank = 1;
		for(int j = num-k+1; j < num; j++)
		{
			if(stu[j].score != stu[j-1].score)
			{
				stu[j].local_rank = (j+1) - (num-k);
			}
			else
			{
				stu[j].local_rank = stu[j-1].local_rank;
			}
		}
	}
	
	sort(stu,stu+num,cmp);
	int r = 1;
	printf("%d\n",num);
	for(int i = 0; i < num; i++)
	{
		if(i > 0 && stu[i].score != stu[i-1].score)
		{
			r = i + 1;
		}
		printf("%s %d %d %d\n",stu[i].id,r,stu[i].location,stu[i].local_rank);
	}
	return 0;
}

