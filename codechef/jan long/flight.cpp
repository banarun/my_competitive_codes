#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<string> buf;
	vector<string>::iterator it;
	string s;
	int i,j,count=0,n,t,k,flg=0;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>n;
		for(j=0;j<n;j++)
		{
			cin>>s;
			buf.push_back(s);
		}
		sort(buf.begin(),buf.end());
		
		for(it=buf.begin();it!=buf.end();it++)
		cout<<endl<<*it<<" ";
		
		for(it=buf.begin();it!=buf.end();it++)
		{
			count=1;
			cout<<j<<"b";
			while((*it==*(++it))&&it!=buf.end())
			{
				j++;
				count++;
			}
			cout<<*it<<(count*100)/n<<endl;
			
			cout<<j;
		}
	}
	return 0;
	}
