/***
DFS
***/
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;

vector<int> node[maxn];
int leaf[maxn] = {0};
int max_level = -1;

void DFS(int index,int level)
{
	if(0 == node[index].size())
	{
		leaf[level]++;
		if(level > max_level)
		{
			max_level = level;
		}
		return;
	}
	for(int i = 0; i < node[index].size(); i++)
	{
		DFS(node[index][i],level+1);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int father,k,child;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&father,&k);
		for(int j = 0; j < k; j++)
		{
			scanf("%d",&child);
			node[father].push_back(child);
		}
	}
	DFS(1,1);
	for(int i = 1; i <= max_level; i++)
	{
		printf("%d",leaf[i]);
		if(i < max_level) printf(" ");
	}
	return 0;
}
