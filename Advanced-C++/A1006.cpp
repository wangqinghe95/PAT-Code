/***
file1
***/
#include<stdio.h>
#include<string.h>
#define MAX  -1
#define MIN  24*60*60
const int maxn = 20;

int transfer(int hh,int mm,int ss)
{
	return hh*60*60 + mm * 60 + ss;
}

int main()
{
	int n;
	scanf("%d",&n);
	char minStr[maxn],maxStr[maxn],str[maxn];
	int hh,mm,ss;
	int min = MIN,max = MAX;
	int temp;
	
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d",str,&hh,&mm,&ss);
		temp = transfer(hh,mm,ss);
		if(temp < min)
		{
			min = temp;
			strcpy(minStr,str);
		}
		scanf("%d:%d:%d",&hh,&mm,&ss);
		temp = transfer(hh,mm,ss);
		if(temp > max)
		{
			max = temp;
			strcpy(maxStr,str);
		}

	}
	printf("%s %s",minStr,maxStr);
	return 0;
}

/***
file2
***/
#include<cstdio>
#include<algorithm>
using namespace std;

struct person
{
	char id[20];
	int hh,mm,ss;
}temp,early,late;

void init()
{
	//将最早的时间初始化位25：00：00不行 
	early.hh = 24,early.hh = 60,early.ss = 60;
	late.hh = 0,late.mm = 0,late.ss = 0; 
}

//a的时间大于b的时间 ==>a的时间晚于b的时间 
bool bigger(person a,person b)
{
	if(a.hh != b.hh) return a.hh > b.hh;
	else if(a.mm != b.mm) return a.mm > b.mm;
	else return a.ss > b.ss;
}

int main()
{
	int n;
	init();
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%s %d:%d:%d",temp.id,&temp.hh,&temp.mm,&temp.ss);
		//如果temp的时间比early时间大是假 ==> temp时间早于early时间 
		if(bigger(temp,early) == false) early = temp;
		scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
		//temp时间 晚于 late 的时间 
		if(bigger(temp,late) == true) late = temp;
	}
	
	printf("%s %s",early.id,late.id);
	return 0;
}
