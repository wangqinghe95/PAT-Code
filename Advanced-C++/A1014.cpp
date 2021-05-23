#include<cstdio>
#include<queue>
using namespace std; 
const int maxn = 1010;

struct Window{
	int popTime,endTime;
	queue<int> q;
}window[30];

int needTime[maxn],ans[maxn];

int convertTominute(int h,int m)
{
	return h * 60 + m;
 } 

int main()
{
	int n,k,m,q;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i = 0; i < k; i++)
	{
		scanf("%d",&needTime[i]);
	}
	for(int i = 0 ; i < n; i++)
	{
		window[i].popTime = window[i].endTime = convertTominute(8,0);
	}
	int index = 0;
	//处理线内顾客 窗口处顾客加上服务截至时间 
	//				线内等待顾客先放入队列中，加上结束时间 
	for(int i = 0; i < min(n*m,k); i++)
	{
		window[index%n].q.push(index);
		window[index%n].endTime += needTime[index];
		if(index < n)
				 window[index%n].popTime += needTime[index];
		ans[index] = window[index%n].endTime; 
		index++;
	}
	for(;index < k; index++)
	{
	    int idx = -1,minPop = 1 << 30;
		for(int i = 0; i < n; i++)
		{
		 	if(window[i].popTime < minPop)
			 {
			     idx = i;
				 minPop = window[i].popTime;	
			 }	
		}	
		Window& w = window[idx];
		w.q.pop();
		w.q.push(index);
		w.endTime += needTime[index];
		w.popTime += needTime[w.q.front()];
		ans[index] = w.endTime;
	}	
	int query;
	for(int i = 0; i < q; i++)
	{
		scanf("%d",&query);
		if(ans[query-1]-needTime[query-1] >= convertTominute(17,0))
		    printf("Sorry\n");
		else
		{
			printf("%02d:%02d\n",ans[query-1]/60,ans[query-1]%60);
		}
	}
	return 0;	
}
