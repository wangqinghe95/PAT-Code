// https://www.cnblogs.com/wanghao-boke/p/11716657.html

#include<iostream>
#include<stack>
using namespace std;

const int maxn = 1010;

int check(int *a,int n,int m);

int main()
{
	int arr[maxn] = {0};
	int n,m,k;
	scanf("%d%d%d",&m,&n,&k);
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d",&arr[j]);
		}
		if(check(arr,n,m))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
}

int check(int *a,int n,int m)
{
	int iRet = -1;
	stack<int> s;
	int current = 1;
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		s.push(i);
		if (s.size() > m)
		{
			flag = false;
			break;
		}		
		while (!s.empty() && a[current] == s.top())
		{
			current++;
			s.pop();
		}
	}
	
	if (flag && s.empty())
	{
		iRet = 1;
	}
	else
	{
		iRet = 0;
	}
	
	return iRet;
}
