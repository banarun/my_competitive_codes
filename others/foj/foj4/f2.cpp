#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int i,j,n,m,l,t,p;
	cin>>t;
	int a,b;
	for(j=0;j<t;j++){
		cin>>a>>b;
		
		vector<int> v;
		for(i=0;i<b;i++){
			cin>>p;
			v.push_back(p);
		}
		int count=0;
		sort(v.begin(),v.end());
		for(i=0;i<b;i++)
			if(a-v[i]>=0){
				count++;
				a=a-v[i];
			}
		cout<<count<<endl;
		
	}
	return 0;
}
