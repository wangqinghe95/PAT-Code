#include<cstdio>
#include<queue>
using namespace std;
const int maxn = 50;

struct Node
{
	int data;
	Node* lchild;
	Node* rchild;
}node;
int post[maxn],in[maxn];
int num = 0;

Node* create(int postL,int postR,int inL,int inR);
void BFS(Node *root,int n);

int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&post[i]);
	}
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&in[i]);
	}
	Node* root = create(0,n-1,0,n-1);
	BFS(root,n);
	return 0;
}

Node* create(int postL,int postR,int inL,int inR)
{
	if(postL > postR) return NULL;
	Node *root = new Node;
	root->data = post[postR];
	
	int k;
	for(k = inL; k <= inR; k++)
	{
		if(in[k] == post[postR])
				 break;
	}
	
	int numLeft = k - inL;
	root->lchild = create(postL,postL+numLeft-1,inL,k-1);
	root->rchild = create(postL+numLeft,postR-1,k+1,inR);
	return root;
}

void BFS(Node *root,int n)
{
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		Node *now = q.front();
		q.pop();
		printf("%d",now->data);
		num++;
		if(num < n) printf(" ");
		if(now->lchild != NULL) q.push(now->lchild);
		if(now->rchild != NULL) q.push(now->rchild);
	}
}
