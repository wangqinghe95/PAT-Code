#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct bign
{
	int d[1000];
	int len;
	bign()
	{
		memset(d,0,sizeof(0));
		len = 0;
	}
};

bign change(char *str);
void print(bign a,int k);
bool isPalindromic(bign a);
bign add(bign a,bign b);

int main()
{
	char str[1000] = {0};
	int maxK,k = 0;
	scanf("%s %d",str,&maxK);
	bign a = change(str);
	do
	{
		if(isPalindromic(a))
		{
			break;
		}
		else
		{
			bign b = a;
			reverse(b.d,b.d+b.len);
			a = add(a,b);
		}
        k++;
	}while(k < maxK);
	
	print(a,k);
	return 0;
}

bign change(char *str)
{
	bign a;
	a.len = strlen(str);
	for(int i = 0; i < a.len; i++)
	{
		a.d[i] = str[a.len - i - 1] -'0';
	}
	return a;
}
void print(bign a,int k)
{
	for(int i = a.len - 1; i >= 0; i--)
	{
		printf("%d",a.d[i]);
	}
	printf("\n%d",k);
}
bool isPalindromic(bign a)
{
	for(int i = 0; i < a.len/2; i++)
	{
		if(a.d[i] != a.d[a.len - i - 1])
			return false;
	}
	return true;
}
bign add(bign a,bign b)
{
 	bign c;
 	int carry = 0;
 	for(int i = 0; i < a.len; i++)
 	{
 	 	int temp = a.d[i] + b.d[i] + carry;
 	 	c.d[c.len++] = temp % 10;
 	 	carry = temp / 10;
    }
    if(carry != 0)
    {
    	c.d[c.len++] = carry % 10;
	}
	return c;
}
