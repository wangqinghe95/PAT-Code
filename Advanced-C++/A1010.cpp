思路：确保N1为已知基数的数
1.将N1转化为10进制的数-N1Num。
2.找N2字符串最大的数，它的进制最少比它大1，设为low
3.N2字符串的最高进制为high = max(low,N1Num) + 1；
4.二分法，从（low,high）区间内找符合要求的进制。

//int范围不够
//三个点不过
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 20;
const int INF = 100000000;
int map[257] = {0};

int init()
{
	for(char c = '0'; c <= '9'; c++)
	{
		map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++)
	{
		map[c] = c - 'a' + 10;
	}
}

int Convert2Num(char *str,int radix,int Max)
{
	int num = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		num = num * radix + map[str[i]];
		if(num < 0 || num > Max) return -1;
	}
	return num;
}

int FindLargest(char *str)
{
	int len = strlen(str);
	int iMax = -1;
	for(int i = 0; i < len; i++)
	{
		if(iMax < map[str[i]])
		{
			iMax = map[str[i]];
		}
	}
	return iMax + 1;
}

//1 mid is bigger
//-1 mid is smaller 
int cmp(char *N2,int radix,int N1Num)
{
	int N2Num = Convert2Num(N2,radix,N1Num);
	if(N2Num < 0 ) return 1;
	if(N2Num > N1Num) return 1;
	else if(N2Num < N1Num) return -1;
	else return 0;
}

int Binary(char *N2,int low,int high,int N1Num)
{
	int mid = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		int ans = cmp(N2,mid,N1Num);
		if(1 == ans) high = mid - 1;
		else if(-1 == ans) low = mid + 1;
		else return mid; 
	} 
	return -1;
}

int main()
{
	init();
	char N1[maxn],N2[maxn],temp[maxn];
	int radix,tag;
	scanf("%s%s%d%d",N1,N2,&tag,&radix);
	if(2 == tag)
	{
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	int N1Num = Convert2Num(N1,radix,INF);
	int low = FindLargest(N2);
	int high = max(N1Num,low) + 1;
	int ans = Binary(N2,low,high,N1Num);
	if(-1 == ans) printf("Impossible\n");
	else printf("%d",ans);
	return 0;
}

//还有10号点过不去
//不过是因为两个函数的返回值是int
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 12;
//const int INF = 100000000;
LL INF = (1LL << 63) - 1;
LL map[257] = {0};

void init()
{
	for(char c = '0'; c <= '9'; c++)
	{
		map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++)
	{
		map[c] = c - 'a' + 10;
	}
}

LL Convert2Num(char *str,LL radix,LL Max)
{
	LL num = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++)
	{
		num = num * radix + map[str[i]];
		if(num < 0 || num > Max) return -1;
	}
	return num;
}

LL FindLargest(char *str)
{
	int len = strlen(str);
	int iMax = -1;
	for(int i = 0; i < len; i++)
	{
		if(iMax < map[str[i]])
		{
			iMax = map[str[i]];
		}
	}
	return iMax + 1;
}

//1 mid is bigger
//-1 mid is smaller 
LL cmp(char *N2,LL radix,LL N1Num)
{
	LL N2Num = Convert2Num(N2,radix,N1Num);
	if(N2Num < 0 ) return 1;
	if(N2Num > N1Num) return 1;
	else if(N2Num < N1Num) return -1;
	else return 0;
}

LL Binary(char *N2,LL low,LL high,LL N1Num)
{
	LL mid = 0;
	while(low <= high)
	{
		mid = (low + high) / 2;
		int ans = cmp(N2,mid,N1Num);
		if(1 == ans) high = mid - 1;
		else if(-1 == ans) low = mid + 1;
		else return mid; 
	} 
	return -1;
}

int main()
{
	init();
	char N1[maxn],N2[maxn],temp[maxn];
	int radix,tag;
	scanf("%s%s%d%d",N1,N2,&tag,&radix);
	if(2 == tag)
	{
		strcpy(temp,N1);
		strcpy(N1,N2);
		strcpy(N2,temp);
	}
	LL N1Num = Convert2Num(N1,radix,INF);
	LL low = FindLargest(N2);
	LL high = max(N1Num,low) + 1;
	LL ans = Binary(N2,low,high,N1Num);
	if(-1 == ans) printf("Impossible\n");
	else printf("%lld",ans);
	return 0;
}
