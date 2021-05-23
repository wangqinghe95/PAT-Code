#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn = 10010;

vector<int> G[maxn];
int father[maxn];
int isRoot[maxn];

int maxH = 0;
vector<int> temp,ans;

void init(int n);
void Union(int a,int b);
int FindFather(int x);
int calBack(int n);
void DFS(int u,int depth,int pre);

int main()
{
	int n;
	scanf("%d",&n);
	init(n);
	int u,v;
	for(int i = 1; i < n; i++)
	{
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
		Union(u,v);
	}
	int block = calBack(n);
	if(block != 1)
	{
		printf("Error: %d components",block);
	}
	else
	{
		DFS(1,1,-1);
		ans = temp;
		DFS(ans[0],1,-1);
		for(int i = 0; i < temp.size(); i++)
		{
			ans.push_back(temp[i]);
		}
		sort(ans.begin(),ans.end());
		printf("%d",ans[0]);
		for(int i = 1; i < ans.size(); i++)
		{
			if(ans[i] != ans[i-1])
			{
				printf("\n%d",ans[i]);
			}
		}
	}
	return 0;
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		father[i] = i;
	}
}

void Union(int a,int b)
{
	int faA = FindFather(a);
	int faB = FindFather(b);
	if(faA != faB)
	{
		father[faA] = faB;
    } 
}

int FindFather(int x)
{
	int a = x;
	while(x != father[x])
	{
		x = father[x];
	}
	while(a != father[a])
	{
		int z = a;
		a = father[a];
		father[z] = x;
	}
	return x;
}

int calBack(int n)
{
	int block = 0;
	for(int i = 1; i <= n; i++)
	{
		isRoot[FindFather(i)]= true;
	}
	for(int i = 1; i <= n; i++)
	{
		block += isRoot[i];
	}
	return block;
}

void DFS(int u,int depth,int pre)
{
	if(depth > maxH)
	{
		temp.clear();
		temp.push_back(u);
		maxH = depth;
	}
	else if(depth == maxH)
	{
		temp.push_back(u);
	}
	
	for(int i = 0; i < G[u].size(); i++)
	{
		if(G[u][i] == pre) continue;
		DFS(G[u][i],depth+1,u);
	}
}
