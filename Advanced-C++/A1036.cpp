#include<cstdio>

struct student
{
	char name[15];
	char ID[15];
	int score;
}F,M,temp;

void init();

int main()
{
	init();
	int n;
	scanf("%d",&n);
	
	char gender;
	for (int i = 0; i < n; i++)
	{
		scanf("%s %c %s %d",temp.name, &gender, temp.ID, &temp.score);
		if (gender == 'M' && temp.score < M.score)
		{
			M = temp;
		}
		if (gender == 'F' && temp.score > F.score)
		{
			F = temp;
		}
	}
	
	if (F.score == -1)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n",F.name, F.ID);
	}
	
	if (M.score == 101)
	{
		printf("Absent\n");
	}
	else
	{
		printf("%s %s\n",M.name, M.ID);
	}
	
	if (M.score == 101 || F.score == -1)
	{
		printf("NA");
	}
	else
	{
		printf("%d",F.score - M.score);
	} 
	 
	return 0;
}

void init()
{
	M.score = 101;
	F.score = -1;
}
