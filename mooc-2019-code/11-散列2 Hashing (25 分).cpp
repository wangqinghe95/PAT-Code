//https://www.cnblogs.com/wanghao-boke/p/11962862.html

#include<cstdio>
const int maxn = 10010;

int hashTable[maxn] = {0};

bool isPrime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n,m;
	scanf("%d%d", &m, &n);
	
	while(!isPrime(m))
	{
		m++;
	}
	
	int pos, temp;
	for (int i = 0 ; i < n; i++)
	{
		scanf("%d",&temp);
		pos = temp % m;
		if (!hashTable[pos])
		{
			hashTable[pos] = 1;
			printf("%d", pos);
		}
		else
		{
			int step = 1;
			for (; step <= m; step++)	//平方检测法结束的标志就是step步长大于hash数组的长度为止 
			{
				pos = (temp + step * step) % m; 
				if (!hashTable[pos])
				{
					hashTable[pos] = 1;
					printf("%d", pos);
					break;
				}
			}
			if (step >= m)
			{
				printf("-");
			}
		}
		
		if (i < n - 1)
		{
			printf(" ");
		}
	}
	
	return 0;
}
