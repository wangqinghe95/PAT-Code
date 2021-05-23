#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 1010;

vector<int> map[maxn];
int father[maxn];
bool vis[maxn];

int Findfather(int x)
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

void Union(int a,int b)
{
	int faA = Findfather(a);
	int faB = Findfather(b);
	if(faA != faB)
	{
		father[faA] = faB;
	}
}

void init(int n)
{
	for(int i = 1; i <= n; i++)
	{
		father[i] = i;
		vis[i] = false;
	}
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	
	int u,v;
	for(int i = 0; i < m; i++)
	{
		scanf("%d%d",&u,&v);
		map[u].push_back(v);
		map[v].push_back(u);
	}
	
	int current;
	for(int query = 0; query < k; query++)
	{
		scanf("%d",&current);
		init(n);
		for(int i = 1; i <= n; i++ )
		{
			for(int j = 0; j < map[i].size(); j++)
			{
				u = i;
				v = map[i][j];
				if(u == current || v == current)
					 continue;
			    Union(u,v);
			}
		}
		int block = 0;
		for(int i = 1; i <= n; i++)
		{
			if(i == current)
				 continue;
			int fa_i = Findfather(i);
			if(vis[fa_i] == false)
			{
			 	 block++;
				  vis[fa_i] = true;	
		    } 
		}
		printf("%d\n",block-1);
	} 
	return 0;
}

