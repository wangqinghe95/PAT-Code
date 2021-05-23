#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 2020;

map<string, int> stringToint;
map<string, int> gang;
map<int, string> intTostring;

int G[maxn][maxn] = {0}, weight[maxn] ={0};
int numPerson = 0;
int vis[maxn] = {0};
int n,k;

int change(string str);
void DFSTrave();
void DFS(int nowVisit, int &head, int &numMember, int &totalValue);

int main()
{
	cin >> n >> k;
	int w;
	string str1, str2;
	
	for (int i = 0; i < n; i++)
	{
		cin >> str1 >> str2 >> w;
		int id1 = change(str1);
		int id2 = change(str2);
		G[id1][id2] += w;
		G[id2][id1] += w;
		weight[id1] += w;
		weight[id2] += w;
	}
	
	DFSTrave();
	cout << gang.size() << endl;
	map<string, int>::iterator it;
	for (it = gang.begin(); it != gang.end(); it++)
	{
		cout << it->first <<" " << it->second << endl; 
	}
	return 0;
}

int change(string str)
{
	if (stringToint.find(str) != stringToint.end())
	{
		return stringToint[str];
	}
	else
	{
		stringToint[str] = numPerson;
		intTostring[numPerson] = str;
		return numPerson++;
	}
}

void DFSTrave()
{
	for (int i = 0; i < numPerson; i++)
	{
		if (vis[i] == false)
		{
			int head = i, numMember = 0, totalValue = 0;
			DFS(i, head, numMember, totalValue);
			if (numMember > 2 && totalValue > k)
			{
				gang[intTostring[head]] = numMember;
			}
		}
	}
}

void DFS(int nowVisit, int &head, int &numMember, int &totalValue)
{
	numMember++;
	vis[nowVisit] = true;
	
	if(weight[nowVisit] > weight[head])
	{
		head = nowVisit;
	}
	for (int i = 0; i < numPerson; i++)
	{
		if (G[nowVisit][i] > 0)
		{
			totalValue += G[nowVisit][i];
			G[i][nowVisit] = G[nowVisit][i] = 0;
			if (vis[i] == false)
			{
				DFS(i, head, numMember, totalValue);
			}
		}
	}
}
