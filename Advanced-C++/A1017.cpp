#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 100;
const int INF = 100000000;

struct Customer
{
	int comeTime,serverTime;
}Newcustom;
vector<Customer> custom;

int convert(int h,int m,int s)
{
	return h * 3600 + m * 60 + s;
}

bool cmp(Customer a,Customer b)
{
	return a.comeTime <= b.comeTime;
}

int endTime[maxn];  //k个窗口的每个顾客服务结束时间

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	
	int stTime = convert(8,0,0);
	int edTime = convert(17,0,0);
	for(int i = 0 ; i < k; i++)
	{
	 		endTime[i] = stTime;	
	}
	
	for(int i = 0; i < n; i++)
	{
		int h,m,s,serTime;
		scanf("%d:%d:%d %d",&h,&m,&s,&serTime);
		int comeTime = convert(h,m,s);
		if(comeTime > edTime) continue;
		Newcustom.comeTime = comeTime;
		Newcustom.serverTime = serTime <= 60 ? serTime * 60 : 3600;
		custom.push_back(Newcustom);
	}
	sort(custom.begin(),custom.end(),cmp);
	
	int totTime = 0;
	for(int i = 0 ; i < custom.size(); i++)
	{
		int idx = -1,minTime = INF;
		for(int j = 0; j < k; j++)
		{
			if(minTime > endTime[j])
			{
				idx = j;
				minTime = endTime[j];
			}
		}
		if(custom[i].comeTime >= endTime[idx])
		{
			endTime[idx] = custom[i].comeTime + custom[i].serverTime;
		}
		else
		{
			totTime += (endTime[idx] - custom[i].comeTime);
			endTime[idx] += custom[i].serverTime;
		}
	}
	if(custom.size() == 0) printf("0 0");
	
	else
	{
		printf("%.1f",totTime/60.0/custom.size());
	}
	return 0;
} 
