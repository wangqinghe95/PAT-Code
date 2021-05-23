#include<cstdio>
#include<cstring>
const int maxn = 1010;

struct Node
{
	char user[maxn], pwd[maxn];
	bool isChange;
}T[maxn];

void Modify(Node &t, int &cnt);

int main()
{
	int n;
	scanf("%d",&n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s %s",&T[i].user, &T[i].pwd);
		T[i].isChange = false;
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		Modify(T[i],cnt);
	}
	
	if (0 == cnt)
	{
		if (1 == n)
		{
			printf("There is 1 account and no account is modified");
		}
		else
		{
			printf("There are %d accounts and no account is modified",n);	
		}
	}
	else
	{
		printf("%d\n",cnt);
		for (int i = 0; i < n; i++)
		{
			if (T[i].isChange)
			{
				printf("%s %s\n",T[i].user, T[i].pwd);	
			} 			
		}
	}
	return 0;
}

void Modify(Node &t, int &cnt)
{
	int len = strlen(t.pwd);
	
	for (int i = 0; i < len; i++)
	{
		switch(t.pwd[i])
		{
			case '1':
				{
					t.pwd[i] = '@';
					t.isChange = true;
					break;
				}
			case '0':
				{
					t.pwd[i] = '%';
					t.isChange = true;
					break;
				}
			case 'l':
				{
					t.pwd[i] = 'L';
					t.isChange = true;
					break;
				}
			case 'O':
				{
					t.pwd[i] = 'o';
					t.isChange = true;
					break;
				}								
		}
	}
	if (t.isChange)
	{
		cnt++;
	}
}
