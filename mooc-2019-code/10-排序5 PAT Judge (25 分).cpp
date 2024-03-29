//https://www.cnblogs.com/wanghao-boke/p/11915653.html

//用户id 00001 - N
//问题id 1 - K
//p[i] 第i个问题的满分

//M行 用户id 问题id 得分(-1提交未能通过编译，[0-p[i]分]) 

/*
输入格式
rank user_id total_score s[1]...s[k] 
rank 名次，总分相同，名词相同 按满分数量和 按id非递减方式排序 
s[1]...s[k] 提交问题获得的分数，如果没有提交输出- ，提交数次取最高分
没有提交任何解决方案或者任何解决方案都没有通过编译的就不进行排序了 
*/ 

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

struct Student
{
	int id;
	int score[6]; //总分以及1-k(<=5)问题得分 总分初始化为0，各题目初始化-1 
	int num_full;	//满分题目数，初始化0
	bool isSummit;
}stu[maxn];

void init(int n,int k);
bool cmp(Student a, Student b);

int main()
{
	int n,k,m;
	int full_mark[6];
	scanf("%d%d%d", &n, &k, &m);

	init(n,k);
	
	for (int i = 1; i <= k; i++)
	{
		scanf("%d",&full_mark[i]);
	}
	
	int id, num_ques, nGrade;
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d",&id, &num_ques, &nGrade);
		
		stu[id].id = id;
		if (nGrade == -1 && stu[id].score[num_ques] == -1) 
		{
			stu[id].score[num_ques] = 0;
		}
		if (nGrade != -1)
		{
			stu[id].isSummit = true;
		}
		if (stu[id].score[num_ques] < nGrade) //分数大于已保存的，更替 
		{

			stu[id].score[num_ques] = nGrade;
			if (nGrade == full_mark[num_ques])	//满分时，满分数量+1 
			{
				stu[id].num_full++;
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].score[j] != -1)
			{
				stu[i].score[0] += stu[i].score[j];	
			}	
		} 
	}
	
	sort(stu+1, stu+n+1, cmp);
	
	int rank = 1;
	for (int i = 1; i <= n; i++)
	{
		if (!stu[i].isSummit)
		{
			break;
		}
		if (i != 1 && stu[i].score[0] != stu[i-1].score[0])
		{
			rank = i;	
		}	
		printf("%d %05d %d ", rank, stu[i].id, stu[i].score[0]);
		for (int j = 1; j <= k; j++)
		{
			if (stu[i].score[j] == -1)
			{
				printf("-");
			}
			else
			{
				printf("%d",stu[i].score[j]);
			}
			
			if (j < k)
			{
				printf(" ");
			}
			else
			{
				printf("\n");
			}
		}
	} 
	
	return 0;
}

void init(int n,int k)
{
	for (int i = 1; i <= n; i++)
	{
		stu[i].score[0] = 0;
		stu[i].num_full = 0;
		stu[i].isSummit = false;
		for (int j = 1; j <= k; j++)
		{
			stu[i].score[j] = -1;
		}
	}
}

bool cmp(Student a, Student b)
{
	if (a.isSummit != b.isSummit)
	{
		return a.isSummit > b.isSummit;
	}
	else if (a.score[0] != b.score[0])
	{
		return a.score[0] > b.score[0];
	}
	else if (a.num_full != b.num_full)
	{
		return a.num_full > b.num_full;
	}
	else
	{
		return a.id < b.id;
	}
}
