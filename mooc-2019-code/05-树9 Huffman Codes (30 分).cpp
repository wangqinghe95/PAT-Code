// https://www.cnblogs.com/wanghao-boke/p/11783768.html

#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 1010;

typedef struct TreeNode* Tree;
struct TreeNode
{
	Tree left,right;
	int weight;
};

typedef struct HeapNode* Heap;
struct HeapNode
{
	TreeNode Data[maxn];
	int size;
};

int n,m;
int w[maxn];
char ch[maxn];
int codelen;
int cnt2,cnt0;

Tree creatTree();
Heap creatHeap();
void Insert(Heap H, TreeNode T);
Tree Huffman(Heap H);
Tree Delete(Heap H);
int WPL(Tree T, int depth);
bool Judge();
void JudgeTree(Tree T);

int main()
{
	cin >> n;
	Tree T = creatTree();
	Heap H = creatHeap();
	
	for (int i = 0; i < n; i++)
	{
        getchar();
		cin >> ch[i] >> w[i];
		H->Data[H->size].left = H->Data[H->size].right = NULL;
		T->weight = w[i];
		Insert(H,*T);
	}
	
	T = Huffman(H);
	codelen = WPL(T,0);
	//printf("%d\n",codelen);
	
	cin >> m;
	while (m--)
	{
		if (Judge())
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	
	return 0;
}

Tree creatTree()
{
	Tree T = new TreeNode;
	T->left = T->right = NULL;
	T->weight = 0;
	return T;
}

Heap creatHeap()
{
	Heap H = new HeapNode;
	H->Data[0].weight = -1;
	H->size = 0;
	return H;
}

void Insert(Heap H, TreeNode T)
{
	int i = ++H->size;
	for (; H->Data[i/2].weight > T.weight; i /= 2)
	{
		H->Data[i] = H->Data[i/2];
	}
	H->Data[i] = T;
}

Tree Huffman(Heap H)
{
	Tree T = creatTree();
	while (H->size > 1)
	{
		T->left = Delete(H);
		T->right = Delete(H);
		T->weight = T->left->weight + T->right->weight;
		Insert(H,*T); 
	}
	T = Delete(H);
	return T; 
}

Tree Delete(Heap H)
{
	int parent,child;
	TreeNode Tmp = H->Data[H->size--];
	Tree T = creatTree();
	*T = H->Data[1];
	for (parent = 1; 2*parent <= H->size; parent = child)
	{
		child = 2*parent;
		if (child < H->size && 
			H->Data[child+1].weight < H->Data[child].weight)
		{
			child++;
		}
		
		if (H->Data[child].weight > Tmp.weight)
		{
			break;
		}
		H->Data[parent] = H->Data[child]; 
	}
	H->Data[parent] = Tmp;
	return T;
}

int WPL(Tree T, int depth)
{
	if (!T->left && !T->right)
	{
		return depth * (T->weight);
	}
	else
	{
		return WPL(T->left,depth+1) + WPL(T->right,depth+1);
	}
}

bool Judge()
{
	char s1[maxn],s2[maxn];
	bool flag = true;
	Tree T = creatTree();
	Tree pt = NULL;
	int wgh;
	
	for (int i = 0;  i < n; i++)
	{
		cin >> s1 >> s2;
		
		if (strlen(s2) > n)
		{
			return 0;
		}
		
		int j;
		for (j = 0; ch[j] != s1[0]; j++)
		{
			;
		}
		wgh = w[j];
		pt = T;
		for (j = 0; s2[j]; j++)
		{
			if (s2[j] == '0')
			{
				if (!pt->left)
				{
					pt->left = creatTree();
				}
				pt = pt->left;
			}
			if (s2[j] == '1')
			{
				if (!pt->right)
				{
					pt->right = creatTree();
				}
				pt = pt->right;
			}
			
			if (pt->weight)
			{
				flag = false;
			}
			if (!s2[j+1])
			{
				if (pt->left || pt->right)
				{
					flag = false;
				}
				else
				{
					pt->weight = wgh;
				}				
			}
		}
	}
	
	if (!flag)
	{
		return 0;
	}
	cnt0 = cnt2 = 0;
	JudgeTree(T);
	
	if (cnt2 != cnt0-1)
	{
		return 0;
	}
	if (codelen == WPL(T,0))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void JudgeTree(Tree T)
{
	if (T)
	{
		if (!T->left && !T->right)
		{
			cnt0++;
		}
		else if(T->left && T->right)
		{
			cnt2++;
		}
		else
		{
			cnt0 = 0;
		}
		
		JudgeTree(T->left);
		JudgeTree(T->right);
	}
}
