//https://www.cnblogs.com/wanghao-boke/p/11960779.html

map实现
/*
6
13005711862 13588625832
13505711862 13088625832
13588625832 18087925832
15005713862 13588625832
13005711862 15005713862
13005711862 15005713862
*/
#include<iostream>
#include<string>
#include<map>
using namespace std;
const int maxn = 100010;

map<string, int> mp;

void Input(string str)
{
	if (mp.find(str) == mp.end())
	{
		mp[str] = 1;
	}
	else
	{
		mp[str]++;
	}
}

int main()
{
	int n;
	cin >> n;
	
	string s1,s2;
	for (int i = 0; i < n; i++)
	{
		cin >> s1 >> s2;
		Input(s1);
		Input(s2);
	}
	
	map<string, int>::iterator it = mp.begin();
	int most_time = -1;
	int most_num = 0;
	string most_ID;
	for (it = mp.begin(); it != mp.end(); it++)
	{
		//cout << "it->second = " << it->second << endl;
		if (it->second > most_time)
		{
			most_time = it->second;
			most_ID = it->first;
			most_num = 1;
		}
		else if(it->second == most_time )
		{
			most_num++;
			if (most_ID > it->first)
			{
				most_ID = it->first;
			}
		}
	}
	
	if (1 == most_num)
	{
		cout << most_ID << most_time;
	}
	else
	{
		cout << most_ID << " "<< most_time << " "<< most_num;
	}

	return 0;
}


链表散列方式实现：
#include<cstdio>
#include<cstring>
#include<cstdlib>

const int maxn = 12;

typedef struct ListNode *Position;
typedef struct HTable *HashTable;

struct ListNode
{    
    char data[maxn];
    int count;
    Position next;
} ;

struct HTable
{
    Position List;
    int size;
};

HashTable createHash(int n);
int nextPrime(int n);
void Insert(HashTable H, char *key);
void solve(HashTable H);
void freeHashTable(HashTable H);

int main()
{
    int n;
    char key[maxn];
    scanf("%d", &n);

    HashTable H = createHash(2*n);
    for  (int i = 0; i < 2 *n; i++)
    {
        scanf("%s", key);
        Insert(H,key);
    }
    solve(H);
    freeHashTable(H);
    return 0;
}

HashTable createHash(int n)
{
    HashTable H = (HashTable)malloc(sizeof(struct HTable));
    H->size = nextPrime(n);
    H->List = (Position)malloc(H->size * sizeof(struct ListNode));
    for (int i = 0; i < H->size; i++)
    {
        H->List[i].next = NULL;
    }
    return H;
}

//查找比n大的最小质数
int nextPrime(int n)
{
    int i, j;
    int temp = (n % 2) ? n + 2 : n + 1;
    for ( i = temp; ; i += 2)
    {
        for (j = 3; j * j <= i && i % j; j++);
        if ( j * j > i) 
        {
            break;
        }
    }
    return i;
}

void Insert(HashTable H, char *key)
{
    //Position P, temp;
    int h = (atoi(key+6)) % H->size;    //号码的后五位作为散列数
    Position p = H->List[h].next;
    while (p && strcmp(p->data, key) )        //数字号码不相等时p就后移
    {
        p = p->next;
    }
    
    if (p)
    {
        p->count++;    //该值在第一次构造时赋值0
    }
    else
    {
        Position  temp = (Position)malloc(sizeof(struct ListNode));
        strcpy(temp->data, key);
        temp->count = 1;
        temp->next = H->List[h].next;
        H->List[h].next = temp;
    }
}

void solve(HashTable H)
{
    int max = 0, num;
    char min[maxn];
    Position p;
    for (int i = 0; i < H->size; i++)
    {
        p = H->List[i].next;
        while(p)
        {
            if (p->count > max)
            {
                max = p->count;
                strcpy(min, p->data);
                num = 1;
            }
            else if(p->count == max)
            {
                num++;
                if (strcmp(min, p->data) > 0)
                {
                    strcpy(min, p->data);
                }
            }
            p = p->next;
        }
    }

    if (1 == num)
    {
        printf("%s %d", min, max);
    }
    else
    {
        printf("%s %d %d",min, max, num);
    }
}

void freeHashTable(HashTable H)
{
    Position p, temp;
    for (int i = 0 ; i < H->size; i++)
    {
        p = H->List[i].next;
        while(p)
        {
            temp = p->next;
            free(p->data);
            p = temp;
        }
    }
    free(H->List);
}
