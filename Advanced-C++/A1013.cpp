#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
const int maxn = 1010;


vector<int> G[maxn];
bool vis[maxn] = {false};
int current;

void dfs(int v){
	if(v == current) return;
	vis[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(vis[G[v][i]] == false){
			dfs(G[v][i]);
		}
	}
}

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);

	for(int i = 0; i < m; i++ ){
		int u,v;
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
		G[v].push_back(u);
	}

	for(int i = 0; i < k; i++){
		scanf("%d",&current);
		memset(vis,false,sizeof(vis));
		int block = 0;
		for(int j = 1; j <= n; j++){
			if(j != current && vis[j] == false){
				dfs(j);
				block++;
			} 
		}
		printf("%d\n",block - 1);
	}
	return 0;
}
