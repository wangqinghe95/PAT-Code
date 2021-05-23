#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1000010;

struct student
{
	int id;
	int grade[4];
}stu[2020];

int now;
int Rank[maxn][4] = {0};
char course[4] = {'A','C','M','E'};

bool cmp(student a,student b)
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; i++)
	{
		stu[i].grade[0] = 0;
		scanf("%d%",&stu[i].id);
  		for(int j = 1; j <= 3; j++)
  		{
  		 		scanf("%d",&stu[i].grade[j]);	
		  		stu[i].grade[0] += stu[i].grade[j];
		}	
	}
	
	for(now = 0; now < 4; now++)
	{
	 	sort(stu,stu+n,cmp);
		 Rank[stu[0].id][now] = 1;
		 for(int i = 1; i < n; i++)
		 {
		 	if(stu[i].grade[now] == stu[i-1].grade[now])
		 	{
		 		Rank[stu[i].id][now] = Rank[stu[i-1].id][now];
			}
			else
			{
				Rank[stu[i].id][now] = i+1;
			}		 	
		 }
	}
	int query;
	for(int i = 0 ; i < m; i++)
	{
		scanf("%d",&query);
		if(0 == Rank[query][0])
		{
			printf("N/A\n");
		}
		else
		{
			int k = 0;
			for(int j = 1; j <= 3; j++)
			{
				if(Rank[query][j] < Rank[query][k])
	  			    k = j;
			}
			printf("%d %c\n",Rank[query][k],course[k]);
		}
	 } 
	 return 0;
} 
