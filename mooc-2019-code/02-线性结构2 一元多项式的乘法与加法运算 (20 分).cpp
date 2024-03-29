// https://www.cnblogs.com/wanghao-boke/p/11706034.html

#include<cstdio>
#include<cstring>
const int maxn = 2050;

void print(int cnt,int *arr);

int main()
{
	int n;
	int exp,coe;	//exponent  coefficient
	int add[maxn] = {0};
	int arr[maxn] = {0}, mul[maxn] = {0};
	//memset(mul,0,sizeof(mul));	
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&coe,&exp);
		add[exp] += coe;
		arr[exp] += coe;
	}
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d %d",&coe,&exp);
		add[exp] += coe;
		for (int j = maxn; j >= 0; j--)
		{
			if (arr[j] != 0)
			{
				
				mul[j + exp] += arr[j] * coe;
			}
		}
	}
	
	int cnt_add = 0;
	int cnt_mul = 0;
	for (int i = 0; i < maxn; i++)
	{
		if (add[i] != 0)
		{
			cnt_add++;
		}
		if (mul[i] != 0)
		{
			cnt_mul++;
		}
	}
	
	print(cnt_mul,mul);
	print(cnt_add,add);
#if 0
	if (0 == cnt_mul)
	{
		printf("0 0\n");
	}
	else
	{
		for (int i = maxn - 1; i >= 0; i--)
		{
			if (mul[i] != 0)
			{
				printf("%d %d",mul[i],i);
				cnt_mul--;
				if (cnt_mul > 0)
				{
					printf(" ");
				}
				else
				{
					printf("\n");
				}
			}
		}
	}
	

#endif
	return 0;
}

void print(int cnt,int *arr)
{
	int temp_cnt = cnt;
	int *arr_temp = arr;
	
	if ( 0 == temp_cnt )
	{
		printf("0 0\n");
	}
	else 
	{
		for (int i = maxn - 1; i >= 0; i--)
		{			
			if (arr_temp[i] != 0)
			{
				printf("%d %d",arr_temp[i],i);
				temp_cnt--;
				if (temp_cnt > 0)
				{
					printf(" ");
				}
				else
				{
					printf("\n");
				}
			}
		}
	}	
}
