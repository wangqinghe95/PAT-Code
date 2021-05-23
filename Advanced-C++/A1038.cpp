#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 10010;

bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	string str[maxn];
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	sort(str, str+n, cmp);
	
	string ans;
	for (int i = 0; i < n; i++)
	{
		ans += str[i];
	}
	
	while (ans.size() > 0 && ans[0] == '0')
	{
		ans.erase(ans.begin());
	}
	
	if (ans.size() > 0) 
	{
		cout << ans;
	}
	else
	{
		cout << 0;
	}
	
	return 0;
}
