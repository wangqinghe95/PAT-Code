// https://www.cnblogs.com/wanghao-boke/p/11709209.html

一种是使用C++提供的库函数reverse
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define MAXSIZE 1000010

struct node
{
	int data;
	int next;	
} node[MAXSIZE];

int List[MAXSIZE];

int main()
{
	int begin,n,k;
	cin >> begin >> n >> k;
	int Address,Data,Next;
	for (int i = 0; i < n; i++)
	{
		cin >> Address >> Data >> Next;
		node[Address].data = Data;
		node[Address].next = Next;
	}
	
	int count = 0;
	int p = begin;
	while (p != -1) 
	{
		List[count++] = p;
		p = node[p].next;
	}

	for(int i = 0; i + k <= count; i += k)
	{
		reverse(&List[i],&List[i+k]);		
	}
		
	for(int i = 0; i < count; i++)
	{
		if(i < count - 1)
		{
			printf("%05d %d %05d\n",List[i],node[List[i]].data,List[i+1]);		
		}
		else
		{
			printf("%05d %d -1",List[i],node[List[i]].data);		
		}	
	}

	return 0;
}

一种是直接反转
https://www.cnblogs.com/wanghao-boke/p/10650794.html
