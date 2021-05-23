#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
const int k = 100;
const int INF = 100000000;

struct Player
{
	int arriveTime,startTime,serverTime;
	bool isVIP;
}newPlayer;

struct Table
{
	int endTime,numServer;
	bool isVIP;
}table[k];

vector<Player> player;
int convertTime(int h,int m,int s)
{
	return h*60*60 + m*60 + s;
}

bool cmpArriveTime(Player a,Player b)
{
	return a.arriveTime < b.arriveTime;
}

bool cmpServerTime(Player a,Player b)
{
	return a.startTime < b.startTime;
}

int nextVIPPlayer(int VIPi)
{
    VIPi++;
	while(VIPi < player.size() && player[VIPi].isVIP != 1)
	{
	    VIPi++;	
	}	
	return VIPi;
} 

void allotTable(int pID,int tID) //pID player 编号   tID  tableID 
{
	if(player[pID].arriveTime <= table[tID].endTime)
	{
		player[pID].startTime = table[tID].endTime;
	}
	else
	{
		player[pID].startTime = player[pID].arriveTime;
	}
	table[tID].endTime = player[pID].startTime + player[pID].serverTime;
	table[tID].numServer++;
}
int main()
{
	int n,m,k;
	int stTime = convertTime(8,0,0);
	int edTime = convertTime(21,0,0);
	
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		int h,m,s,trainTime,isvip;
		scanf("%d:%d:%d %d %d",&h,&m,&s,&trainTime,&isvip);
		newPlayer.arriveTime = convertTime(h,m,s);
		if(newPlayer.arriveTime >= edTime)
		{
			continue;
		}
		newPlayer.serverTime = trainTime >= 120 ? 7200:trainTime*60;
		newPlayer.startTime = edTime;
		newPlayer.isVIP = isvip;
		player.push_back(newPlayer);
	}
	scanf("%d%d",&k,&m);
	for(int i = 1; i <= k; i++)
	{
		table[i].endTime = stTime;
		table[i].isVIP = table[i].numServer = 0;
	}
	int isTableVIP;
	for(int i = 0; i < m; i++)
	{
		scanf("%d",&isTableVIP);
		table[isTableVIP].isVIP = 1;
	}
	
	sort(player.begin(),player.end(),cmpArriveTime);
	
	int i = 0, VIPi = -1; //顾客序数以及vip顾客数序数 -- 在队列排的位数
	VIPi = nextVIPPlayer(VIPi); //从头开始找第一位vip顾客排在第几位 
	
	//遍历队列中的顾客
	while(i < player.size())
	{
	    int idx = -1, minEndTime = INF; //寻找最小的空闲球桌编号
		for(int j = 1; j <= k; j++)
		{
			if(table[j].endTime < minEndTime)
			{
				idx = j;
				minEndTime = table[j].endTime;
			}
		} 
		
		if(table[idx].endTime >= edTime)  //时间超过了营业时间 
		{
			break;
		} 
		
		if(player[i].isVIP == 1 && i < VIPi) //如果当前顾客是vip客户，且已经处理过，跳过 
		{
			i++;
			continue;
		} 
		
		if(table[idx].isVIP == 1)  //当前球桌是VIP球桌 
		{
			if(player[i].isVIP == 1) 	//当前处理的顾客是vip客户
			{
				allotTable(i,idx);
				if(VIPi == i)
				{
					VIPi = nextVIPPlayer(VIPi);
				}
				i++;
			} 
			else
			{
				if(VIPi < player.size() && player[VIPi].arriveTime <= table[idx].endTime)
				{
					allotTable(VIPi,idx);
					VIPi = nextVIPPlayer(VIPi);
				}
				else
				{
					allotTable(i,idx);
					i++;
				}
			}
		}
		else						//球桌不是vip 
		{
			if(player[i].isVIP == 0)
			{
				allotTable(i,idx);
				i++;
			}
			else
			{
				int VIPidx = -1,minEndTime = INF;
				for(int j = 1; j <= k; j++)
				{
					if(table[j].isVIP == 1 && table[j].endTime < minEndTime)
					{
						VIPidx = j;
						minEndTime = table[j].endTime;
					}
				}
				if(VIPidx != -1 && table[VIPidx].endTime <= player[i].arriveTime)
				{
					allotTable(i,VIPidx);
					if(i == VIPi)
					{
						VIPi = nextVIPPlayer(VIPi);
					}
					i++;
				}
				else
				{
					allotTable(i,idx);
					if(i == VIPi)
					{
						VIPi = nextVIPPlayer(VIPi);
					}
					i++;
				}
			}
		}		 
	} 
	
	sort(player.begin(),player.end(),cmpServerTime);
	for(int i = 0; i < player.size() && player[i].startTime < edTime; i++)
	{
		int t1 = player[i].arriveTime;
		int t2 = player[i].startTime;
		printf("%02d:%02d:%02d ",t1 / 3600, t1 % 3600 / 60, t1 % 60);
		printf("%02d:%02d:%02d ",t2 / 3600, t2 % 3600 / 60, t2 % 60);
		printf("%.0f\n",round((t2-t1) / 60.0));
	}
	
	for(int i = 1; i <= k; i++)
	{
		printf("%d",table[i].numServer);
		if(i < k) printf(" ");
	}
	return 0;
}
