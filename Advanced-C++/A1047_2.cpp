/*
用vector<string> 存储报名该课程的学生姓名
输出时需要把string转化成char型用printf输出，不然会超时 
*/ 
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
const int course_num = 3000;
vector<string> course[course_num];
int main()
{
	int n,k;

	cin >> n >> k;
	
	string name;
	int num, course_id;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> num;
		for (int j = 0; j < num; j++)
		{
			cin >> course_id;
			course[course_id].push_back(name);
		}
	}
	
	for (int i = 1; i <= k; i++)
	{
		sort(course[i].begin(), course[i].end());
		int stu_num = course[i].size();
		cout << i << " " << stu_num << endl;
		for (int j = 0; j < stu_num; j++)
		{
			//cout << course[i][j] << endl;
			printf("%s\n", course[i][j].c_str());
		}
	}
	return 0;
}
