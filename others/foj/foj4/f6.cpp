#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

struct bn{
	int a;
	int b;
};
int main()
{
	
	
	int i,j,n,m,l,p,t;
	cin>>t;
	string s;
	int a[100],b[100];
	for(j=0;j<t;j++){
		cin>>n;
		bn ba[100];
		int a[100],b[100];
		
		for(i=0;i<n;i++){
			cin>>a[i]>>b[i];
		}
		
		for(m=0;m<n;m++)
		{
			int flag=0;
		for(i=0;i<n-1;i++)
		for(p=i+1;p<n;p++)
		{
			
			if(a[i]+a[p]==b[m]&&i!=m&&p!=m)
			{a[i]=-100;a[p]=-100;}
		}
		}
		for(i=0;i<n;i++)
		for(p=0;p<n;p++)
		if(a[i]==b[p]&&i!=p)
			a[i]=(-100);
		
		for(i=0;i<n;i++)
		if(a[i]!=(-100)){
		cout<<a[i]<<endl;
		break;
		}
	}
	return 0;
}
