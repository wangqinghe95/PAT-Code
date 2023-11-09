//https://pintia.cn/problem-sets/1169812488801005568/problems/1200049599777501186

//map实现

#include<iostream>
#include<string>
#include<map>
using namespace std;

map<string, string> mp;
void Login(string account, string passwd); 
void Create(string account, string passwd); 

int main()
{
    int n;
    char c;
    string account, passwd;
    
    cin >> n;
    for (int i = 0 ; i < n; i++)
    {
        getchar();
        cin >> c >> account >> passwd;
        switch (c)
        {
            case 'L':
                Login(account, passwd);
                break;
            case 'N':
                Create(account, passwd);
                break;
        }
    }
    
    return 0;
}

void Login(string account, string passwd)
{
    if (mp.find(account) != mp.end())
    {
        if (passwd == mp[account])
        {
            cout << "Login: OK" << endl;
        }
        else
        {
            cout << "ERROR: Wrong PW" << endl;
        }
    }
    else
    {
        cout << "ERROR: Not Exist" << endl;
    }
}

void Create(string account, string passwd)
{
    if (mp.find(account) != mp.end())
    {
        cout << "ERROR: Exist" << endl;
    }
    else
    {
        mp[account] = passwd;
        cout << "New: OK" << endl;
    }
}

//链表实现
#include<cstdio>
#include<cstdlib>
#include<cstring>
const int maxn = 100010;

typedef struct ListNode* Position;
typedef struct Table* HashTable;

struct ListNode
{
	char account[15];
	char password[20];
	Position next;
};

struct Table
{
	Position List;
	int TableSize;
};

HashTable createTable(int size);
int NextPrime(int size);
void Insert(HashTable H, char *account, char *password);
Position Find(HashTable H, char *key);
int Find_account(HashTable H, char *account);
int check_password(Position P, char *password);
void DestoryTable(HashTable H);

int main()
{
	int n;
	scanf("%d", &n);
	HashTable H = createTable(n * 2);
	
	char c;
	char account[15];
	char password[20];
	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%c %s %s", &c, account, password);
		switch(c)
		{
			case 'N':
				if (-1 == Find_account(H, account))
				{
					Insert(H, account, password);
					printf("New: OK\n");
				}
				else
				{
					printf("ERROR: Exist\n");
				}
				break;
			case 'L':
				if (1 == Find_account(H, account))
				{
					if (1 == check_password(Find(H, account), password))
					{
						printf("Login: OK\n");
					}
					else
					{
						printf("ERROR: Wrong PW\n");
					}
				}
				else
				{
					printf("ERROR: Not Exist\n");
				}
				break;
		}
	}
	//DestoryTable(H);
	return 0;
}

HashTable createTable(int size)
{
	//在堆区申请一个Table大小的内存，转化成该结构体指针类型返回 
	HashTable H = (HashTable)malloc(sizeof (struct Table));
	H->TableSize = NextPrime(size);
	H->List = (Position)malloc(sizeof(struct ListNode) * H->TableSize);
	for (int i = 0 ; i < H->TableSize; i++)
	{
		H->List[i].next = NULL;
	}
	return H;
}

int NextPrime(int size)
{
	for (int tmpSize = size; ; tmpSize++)
	{
		int i = 2;
		for ( ; i * i <= tmpSize; i++)
		{
			if (tmpSize % i == 0)
			{
				break;
			}
		}
		
		if (i * i > tmpSize)
		{
			return tmpSize;
		}
	}
}

void Insert(HashTable H, char *account, char *password)
{
	int h = atoi(account+3) % H->TableSize;
	
	/*Position P = H->List[h].next; 
	while(P && strcmp(P->account, account))
	{
		P = P->next;
	}*/
	Position P = Find(H, account);	
	if (P == NULL)	//头插法 
	{
		Position tmp = (Position)malloc(sizeof (struct ListNode));
		strcpy(tmp->account, account);
		strcpy(tmp->password, password);
		tmp->next = H->List[h].next;
		H->List[h].next = tmp;
	}
}

Position Find(HashTable H, char *key)
{
	int h = atoi(key+3) % H->TableSize; 
	Position P = H->List[h].next;
	while( P != NULL && strcmp(P->account, key))
	{
		//节点存在，并且节点的账户不是传进来的key 
		P = P->next;
	}
	return P;
}

int Find_account(HashTable H, char *account)
{
	Position P = Find(H, account);
	if (P)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

int check_password(Position P, char *password)
{
	if (0 == strcmp(P->password, password))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void DestoryTable(HashTable H)
{
for (int i = 0; i < H->TableSize; i++)
	{
		Position P = H->List[i].next;
		while (P)
		{
			Position tmp = P->next;
			free(P);
			P = tmp;
		}
	}
	free(H->List);
	free(H);
}
