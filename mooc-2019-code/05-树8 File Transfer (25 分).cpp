// https://www.cnblogs.com/wanghao-boke/p/11761751.html

#include<cstdio>
const int maxn = 10100;

void Initialization( int n);
void Input_connection();
int FindFather(int x);
void Check_connection();
void Check_network(int n);
int arr[maxn];

int main()
{
	int n;
	char in;
	
	scanf("%d",&n);
	
	Initialization(n);
	
	do
	{
		getchar();
		scanf("%c",&in);
		switch(in)
		{
			
			case 'I':
			{
				Input_connection();
				break;
			}
			case 'C':
			{
				Check_connection();
				break;
			}
			case 'S':
			{
				Check_network(n);
				break;
			}
		}
	}while (in != 'S');
	return 0;

}

void Initialization( int n)
{
	for (int i = 0; i <= n; i++)
	{
		arr[i] = i;	
	}	
}

void  Input_connection()
{
	int u,v;
	scanf("%d %d",&u,&v);
	int faA = FindFather(u);
	int faB = FindFather(v);
	if (faA != faB)
	{
		arr[faA] = faB;
	}
}

int FindFather(int x)
{
#if 0
	int a = x;
	while (x != arr[x])
	{
		x = arr[x];
	}
	
	while (a != arr[a])
	{
		int z = a;
		a = arr[a];
		arr[z] = x;
	}
#endif
	if (arr[x] == x)
	{
		return x;
	}
	else
	{
		return arr[x] = FindFather(arr[x]);
	}
}

void Check_connection()
{
	int u,v;
	scanf("%d %d",&u,&v);
	int faA = FindFather(u);
	int faB = FindFather(v);
	if (faA != faB)
	{
		printf("no\n");
	}	
	else
	{
		printf("yes\n");
	}
}

void Check_network(int n)
{
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i] == i)
		{
			cnt++;
		}
	}
	
	if (1 == cnt)
	{
		printf("The network is connected.");
	}
	else
	{
		printf("There are %d components.",cnt);
	}
}
