#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 510;
const int INF = 100000000;

struct gas
{
	double dis,price;
}st[maxn];

bool cmp(gas a, gas b)
{
	return a.dis < b.dis;
}

int main()
{
	int n;
	double Cmax, Dis, Davg;
	scanf("%lf%lf%lf%d",&Cmax,&Dis,&Davg,&n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%lf%lf",&st[i].price, &st[i].dis);
	}
	st[n].dis = Dis;
	st[n].price = 0;
	
	sort(st, st+n, cmp);
	
	if (st[0].dis != 0)
	{
		printf("The maximum travel distance = 0.00\n");
		return 0;
	}
	
	int now = 0;
	double maxDis = Cmax * Davg;
	double nowTank = 0; //纪录当前油箱油量
	double ans = 0;	//纪录一共加了多少油 
	while (now  < n)
	{
		int k = -1;
		double minPrice = INF;
		
		for (int i = now+1; i <= n && st[i].dis - st[now].dis <= maxDis; i++)
		{
			if (st[i].price < minPrice)
			{
				k = i;
				minPrice = st[i].price;
			}
			if (minPrice < st[now].price)
			{
				break;
			}
		}
		
		if (-1 == k)
		{
			break;
		}
		
		double need = (st[k].dis - st[now].dis) / Davg;
		if (st[now].price > minPrice) //当前加油站油价格要高于下一个加油站
		{
			//加满油上路
			//油箱的油不够到下一个加油站
			if (nowTank < need)
			{
				ans += (need - nowTank) * st[now].price;
				nowTank = 0; //到达下一个加油站时油量耗尽	
			} 
			else
			{
				nowTank -= need;
			}
		} 
		else  
		{
			//当前加油站油价小于下一个加油站
			//在当前油站加满油箱油量
			ans += (Cmax - nowTank) * st[now].price;
			nowTank = Cmax - need; 
		}
		
		now = k;
	}
	
	if (now == n)
	{
		printf("%.2f\n",ans);
	}
	else
	{
		printf("The maximum travel distance = %.2f\n",st[now].dis + maxDis);
	}
	return 0;
	
}
