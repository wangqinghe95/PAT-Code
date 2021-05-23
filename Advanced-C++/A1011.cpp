#include<cstdio>
#define diff  0.001

double pro[4] = {0};
int w[4] = {0};
char c[4] = {'0','W','T','L'};

int main()
{

	for(int i = 1; i <= 3; i++)
	{
		double dMax = 0.0;
		double temp;
		int iMax = 0;
		for(int j = 1; j <= 3; j++)
		{
			scanf("%lf",&temp);//如果%f 则pro[i]的值无法输入 
			if(temp > dMax)
			{
				dMax = temp;
				iMax = j;
			}
		}
		pro[i] = dMax;
		w[i] = iMax;
	}
	for(int i = 1; i <= 3; i++)
	{
		printf("%c ",c[w[i]]);
	}
	printf("%.2f",(pro[3] * pro[1] * pro[2] * 0.65 -1) * 2);
	return 0;
}
