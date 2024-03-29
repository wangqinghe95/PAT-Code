// https://www.cnblogs.com/wanghao-boke/p/11735679.html

#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int maxn = 50;

struct Node
{
	int data;
	Node *lchild, *rchild;
};

int in[maxn] = {0}, pre[maxn] = {0};
int num = 0;

Node*  createTree(int preL, int preR, int inL, int inR);
void postOrder(Node *root,int n);

int main()
{
	int n;
	scanf("%d",&n);
	
	int x;
	int preIndex = 0, inIndex = 0;
	char str[5];
	stack<int> s;
	
	for (int i = 0; i < 2*n; i++)
	{
		getchar();
		scanf("%s",str);
		if ( 0 == strcmp(str,"Push"))
		{
			scanf("%d",&x);
			s.push(x);
			pre[preIndex++] = x;
		}
		else
		{
			x = s.top();
			s.pop();
			in[inIndex++] = x;
		}
	}
	
	Node *root = createTree(0,n-1,0,n-1);
	postOrder(root,n);
	return 0;
}

Node*  createTree(int preL, int preR, int inL, int inR)
{
	if (preL > preR)
	{
		return NULL;
	}
	
	Node *root = new Node;
	root->data = pre[preL];
	
	int k;
	for (k = inL; k <= inR; k++)
	{
		if (in[k] == pre[preL])
		{
			break;
		}
	}
	
	int numLeft = k - inL;
	root->lchild = createTree(preL+1, preL+numLeft, inL, k-1);
	root->rchild = createTree(preL+numLeft+1, preR, k+1, inR);
	return root;
}

void postOrder(Node *root,int n)
{
	if (root == NULL)
	{
		return;
	}
	postOrder(root->lchild,n);
	postOrder(root->rchild,n);
	printf("%d",root->data);
	
	num++;
	if (num < n)
	{
		printf(" ");
	}
}
