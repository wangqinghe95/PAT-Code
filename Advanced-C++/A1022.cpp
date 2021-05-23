#include<cstdio>
#include<map>
#include<iostream>
#include<string>
#include<set>
using namespace std;

map<string,set<int> > mpTitle,mpAuthor,mpKey,mpPub,mpYear;

void query(map<string,set<int> > &mp,string &temp);

int main()
{
	int n;
	cin >> n;
	string title,author,key,pub,year;
	int id;
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&id);
		getchar();
		getline(cin,title);
		mpTitle[title].insert(id);
		getline(cin,author);
		mpAuthor[author].insert(id);
		while(cin >> key)
		{
			mpKey[key].insert(id);
			char c = getchar();
			if(c == '\n')
			{
				break;
			}
		}
		getline(cin,pub);
		mpPub[pub].insert(id);
		getline(cin,year);
		mpYear[year].insert(id);
	}
	string temp;
	int m;
	int type;
	cin >> m;
	for(int i = 0; i < m; i++)
	{
	    scanf("%d: ",&type);
	    getline(cin,temp);
	    //printf("%05d: ",type);
	    cout << type << ": "<< temp << endl;
#if 1
 		switch(type)
	    {
	    	case 1:
	    		query(mpTitle,temp);break;
	    	case 2:
	    		query(mpAuthor,temp);break;
	    	case 3:
	    		query(mpKey,temp);break;
	    	case 4:
	    		query(mpPub,temp);break;
	    	case 5:
	    		query(mpYear,temp);break;
		}
#else
	 	if(type == 1)
	 	{
 		    query(mpTitle,temp);	
        }
        else if(type == 2)
        {
        	query(mpAuthor,temp);
		}
		else if(type == 3)
		{
            query(mpKey,temp);	
		}
		else if(type == 4)
		{
   		    query(mpPub,temp);
		}
		else
		{
			query(mpYear,temp);
		}
#endif		
	}
	return 0;
}

void query(map<string,set<int> > &mp,string &str)
{
	if(mp.find(str) == mp.end())
	{
		printf("Not Found\n");
	}
	else
	{
		for(set<int>::iterator it = mp[str].begin(); it != mp[str].end(); it++)
		{
			printf("%07d\n",*it);
		}
	}
}
