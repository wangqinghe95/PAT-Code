// https://www.cnblogs.com/wanghao-boke/p/11748765.html

#include<cstdio>
#include<algorithm>
using namespace std;

struct Node
{
	int v;
	int height;
	Node *lchild, *rchild;
}*root;

void Insert(Node* &root,int v);
Node* NewNode(int v);
void updateHeight(Node *root);
int getHeight(Node* root);
int getBalanceFactor(Node* root);
Node* R(Node* &root);
Node* L(Node* &root);

int main()
{
	int n;
	int v;
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&v);
		Insert(root,v);
	}
	printf("%d",root->v);
	return 0;
}

void Insert(Node* &root, int v)
{
	if (NULL == root)
	{
		root = NewNode(v);
		return ;
	}
	
	if (root->v > v)
	{
		Insert(root->lchild,v);
		updateHeight(root);
		if (2 == getBalanceFactor(root))
		{
			if (1 == getBalanceFactor(root->lchild))
			{
				R(root);
			}
			else if(-1 == getBalanceFactor(root->lchild))
			{
				L(root->lchild);
				R(root);
			}
		}
	}
	else
	{
		Insert(root->rchild,v);
		updateHeight(root);
		if (-2 == getBalanceFactor(root))
		{
			if (-1 == getBalanceFactor(root->rchild))
			{
				L(root);
			}
			else if(1 == getBalanceFactor(root->rchild))
			{
				R(root->rchild);
				L(root);
			}
		}
	}
}

Node* NewNode(int v)
{
	Node* node = new Node;
	node->lchild = node->rchild = NULL;
	node->v = v;
	node->height = 1;
	return node;
}

void updateHeight(Node *root)
{
	root->height = max(getHeight(root->lchild),getHeight(root->rchild)) + 1;
	
}

int getHeight(Node* root)
{
	if (NULL == root)
	{
		return 0;
	}
	else
	{
		return root->height;
	}
}

int getBalanceFactor(Node* root)
{
	return getHeight(root->lchild) - getHeight(root->rchild);
}

Node* R(Node* &root)
{
	Node *tmp = root->lchild;
	root->lchild = tmp->rchild;
	tmp->rchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;	
}

Node* L(Node* &root)
{
	Node *tmp = root->rchild;
	root->rchild = tmp->lchild;
	tmp->lchild = root;
	updateHeight(root);
	updateHeight(tmp);
	root = tmp;		
}
