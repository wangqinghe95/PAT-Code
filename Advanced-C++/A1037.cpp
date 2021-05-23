#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;

int main()
{
	int n, m;
	int coupon[maxn], product[maxn];
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &coupon[i]);
	}
	scanf("%d",&m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &product[i]);
	}
	
	sort(coupon, coupon + n);
	sort(product, product + m);
	
	int i = 0, j = 0;
	int ans = 0;
	while (i <= m && j <= n && coupon[i] < 0 && product[j] < 0)
	{
		ans += coupon[i++] * product[j++];
	}
	
	i = n - 1;
	j = m - 1;
	while (i >= 0 && j >= 0 && coupon[i] > 0 && product[j] > 0)
	{
		ans += coupon[i--] * product[j--];
	}
	
	printf("%d",ans);
	return 0;	
}
