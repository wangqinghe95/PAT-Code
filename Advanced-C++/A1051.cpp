#include<iostream>
#include<stack>
using namespace std;

int main()
{
    /*m - the max capacity of the stack 
      n - the length of push sequence
      k - the number of pop sequences to be checked
    */
    int m,n,k;  
    cin >> m >> n >> k;

	int arr[n] = {0};
    stack<int> s;

    for (int i = 1; i <= k; i++)
    {
        while(!s.empty())
        {
        	s.pop();
		}
		
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}
		
		bool flag = true;
		int current = 1;
		for (int i = 1 ; i <= n; i++)
		{	
			s.push(i);
			if (s.size() > m)
			{
				flag = false;
				break;
			}
			
			while (!s.empty() && arr[current] == s.top())
			{
				s.pop();
				current++;
			}
		}
		
		if(s.empty() && flag == true)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
    }
    return 0;
}
