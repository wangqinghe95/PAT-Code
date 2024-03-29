// https://www.cnblogs.com/wanghao-boke/p/11748755.html

#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode* Tree;
struct TreeNode
{
	int v;
	Tree left,right;
	int flag;
};

Tree makeTree(int n);
Tree newNode(int v);
Tree Insert(Tree T, int v);
bool Judge(Tree T,int n);
bool check(Tree T,int v);
void Reset(Tree T);
void FreeTree(Tree T);

int main()
{
	int n,l;
	Tree T;
	scanf("%d",&n);
	while(n)
	{
		scanf("%d",&l);
		T = makeTree(n);
		for (int i = 0; i < l; i++)
		{
			if (Judge(T,n))
			{
				printf("Yes\n");
			}
			else
			{
				printf("No\n");
			}
			Reset(T);
		}
		FreeTree(T);
		scanf("%d",&n);
	}
	return 0;
}

Tree makeTree(int n)
{
	int v;
	scanf("%d",&v);
	
	Tree T = newNode(v);
	for (int i = 1; i < n; i++)
	{
		scanf("%d",&v);
		T = Insert(T,v);
	}
	return T;
}

Tree newNode(int v)
{
	Tree T = (Tree)malloc(sizeof(struct TreeNode));
	T->v = v;
	T->left = T->right = NULL;
	T->flag = 0;
	return T;
}

Tree Insert(Tree T, int v)
{
	if (!T)
	{
		T = newNode(v);
	}
	else
	{
		if (v > T->v)
		{
			T->right = Insert(T->right,v);
		}
		else
		{
			T->left = Insert(T->left,v);
		}
	}
	return T;
}

/* 
flag为True表示两颗二叉搜索树相同
T->Flag = 1 表示该点相同并且已经对比过 
*/
bool Judge(Tree T,int n)
{
	bool flag = true;
	int v;
	scanf("%d",&v);
	
	if (v != T->v)
	{
		flag = false;
	}
	else
	{
		T->flag = 1; 
	}
	
	for (int i = 1; i < n; i++)
	{
		scanf("%d",&v);
		if ( (flag) && (!check(T,v)))
		{
			flag = false;
		}
	}
	
	return flag;
}

/*
如果该点已经对比过且结果是相同的，进入子树
否则就该点与v比较，相同返回True，不同返回false 
*/
bool check(Tree T,int v)
{
	if (T->flag)
	{
		if (v > T->v)
		{
			return check(T->right,v);
		}
		else if (v < T->v)
		{
			return check(T->left,v);
		}
		else
		{
			return true;
		}
	}
	else
	{
		if ( v == T->v)
		{
			T->flag = 1;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Reset(Tree T)
{
	if (T->left)
	{
		Reset(T->left);
	}
	if (T->right)
	{
		Reset(T->right);
	}
	T->flag = 0;
}

void FreeTree(Tree T)
{
	if (T->left)
	{
		FreeTree(T->left);
	}
	if (T->right)
	{
		FreeTree(T->right);
	}
	free(T);	
}
