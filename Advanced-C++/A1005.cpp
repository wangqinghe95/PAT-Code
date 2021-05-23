#include<cstdio>
#include<cstring>
const int maxn = 110;

char word[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
int getSum(char *str)
{
	int sum = 0;
	int iLen = strlen(str);
	for(int i = 0 ; i < iLen; i++)
	{
		sum += str[i] - '0';
	}
	return sum;
}

int main()
{
	char str[maxn];
	scanf("%s",str);
	
	int arr[maxn];
	int num = 0;
	int sum = getSum(str);
	do
	{
		arr[num++] = sum %10;
		sum /= 10;
	}while(sum);
	
	for(int i = num - 1; i >= 0; i--)
	{
		printf("%s",word[arr[i]]);
		if(i > 0) printf(" ");
	}
	return 0;
}
