/*
n 学生数	m课程数
学生数是三个大写字母+一个数组
课程数是一个小于20的数字 从1-k

以增序输出一门课的学生姓名列表
先输出课程编号，再输出学生数，再输出学生姓名，按照字母序 


*/

#include<iostream>
#include<map>
#include<string>
#include<set>
using namespace std;

map<int, set<string> > course;

void printCourse(map<int, set<string> > &mp, int course_id);

int main()
{
	int n,k;
	string name;

	//cin >> n >> k;
	scanf("%d%d", &n, &k);
	int num, course_id;
	for (int i = 0; i < n; i++)
	{
		cin >> name >> num;
		for (int j = 0; j < num; j++)
		{
			//cin >> course_id;
			scanf("%d", &course_id);
			course[course_id].insert(name);
		}
	}
	
	for (int i = 1; i <= k; i++)
	{
		int num_student = course[i].size();
		//cout << i << " " << num_student << endl;
		printf("%d %d\n", i, num_student);
		//for (int i = 0; i < course.size(); i++)
		{
			printCourse(course, i);
		}
	}
	return 0;
}

void printCourse(map<int, set<string> > &mp, int course_id)
{
	if (mp[course_id].size() == 0)
	{
		return;
	}
	for(set<string>::iterator it = mp[course_id].begin(); it != mp[course_id].end(); it++)
	{
		cout << *it << endl;
		//printf("%s\n", *it.c_str());
	}
}
