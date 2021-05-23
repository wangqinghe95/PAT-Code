//https://www.cnblogs.com/wanghao-boke/p/11964366.html

/*知道散列数组大小，和散列数组值反求输入数组*/
#include<cstdio>
#include<cstdlib>
#include<set>
using namespace std;
const int maxn = 1010;
int G[maxn][maxn];

void BuildGraph(int hash[], int n);
void TopSort(int hash[], int hashMap[], int n, int num);

int main()
{
	int n;
	int num = 0;	//纪录hash表中元素个数 
	int hash[maxn], hashMap[100010];
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &hash[i]);
		hashMap[hash[i]] = i;
		if (hash[i] >= 0)
		{
			num++;
		}
	}
	
	BuildGraph(hash, n);
	TopSort(hash, hashMap, n, num);
	return 0;
}

void BuildGraph(int hash[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (hash[i] >= 0)
		{
			int tmp = hash[i] % n;	//对应采用线性检查法解决碰撞的元素 
			if (hash[tmp] != hash[i])
			{
				for (int j = tmp; j != i; j = (j+1) % n)	//建立有向拓扑图来 
				{
					G[j][i] = 1;	//凡是在这个元素之前的位置，都要依赖他们先输入 
				}
			}
		}
	}
}

void TopSort(int hash[], int hashMap[], int n, int num)
{
	int cnt = 0;
	int Indegree[maxn] = {0};
	set<int> s;
	
	for (int v = 0; v < n; v++)
	{
		for(int w = 0; w < n; w++)
		{
			if (G[v][w] != 0)
			{
				Indegree[w]++;
			}
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		if (Indegree[i] == 0 && hash[i] > 0)
		{
			s.insert(hash[i]);
		}
	}
	
	while (!s.empty())
	{
		int now = hashMap[*s.begin()];
		s.erase(s.begin());
		cnt++;
		printf("%d", hash[now]);
		if (cnt != num)
		{
			printf(" ");
		}
		
		for (int v = 0; v < n; v++)
		{
			if (G[now][v] != 0)
			{
				if (--Indegree[v] == 0)
				{
					s.insert(hash[v]);
				}
			}
		}
	}
}
