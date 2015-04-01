#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int i,j,n,m,l,p;
	int t;
	cin>>t;
	for(j=0;j<t;j++){
		cin>>n;
		vector<int> a;
		for(i=0;i<n;i++){
			cin>>p;
			a.push_back(p);
		}
		sort(a.begin(),a.end());
		
		if(a[0]<0&&a[1]<0&&a[n-1]>=0)
		{
			if(a[0]*a[1]>a[n-2]*a[n-3])
			cout<<(a[0]*a[1]*a[n-1])<<endl;
			else
			cout<<(a[n-1]*a[n-2]*a[n-3])<<endl;
		}
		else
		{
			cout<<(a[n-1]*a[n-2]*a[n-3])<<endl;
		}
	}
	return 0;
}
