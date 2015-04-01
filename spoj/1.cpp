#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int i;
	int a,b,t;
	cin>>t;
	
	
	for(int j=0;j<t;j++){
		cin>>a;
		cin>>b;
		int tem;
		vector<int> va,vb;
		int maxa=0,maxb=0;
		for(i=0;i<a;i++){
			cin>>tem;
			if(tem>maxa)
				maxa=tem;

			va.push_back(tem);
		}
		for(i=0;i<b;i++){
			cin>>tem;
			if(tem>maxb)
				maxb=tem;
			vb.push_back(tem);
		}
		if(maxa>=maxb)
			cout<<"Godzilla\n";
		else
			cout<<"MechaGodzilla\n";
	}
	return 0;
}
