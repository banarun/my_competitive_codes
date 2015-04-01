#include <algorithm>
#include <set>
#include <climits>
#include <map>
#include <cstdio>
#include <stack>
#include <iostream>
using namespace std;

int main()
{
	int n,m;
	string s,t;
	cin>>s;
	cin>>t;
	n=s.length();
	m=t.length();
	int o=0;
	int x1=0;
	if(n!=m){
		cout<<"NO";
	}
	else{
		int f1=0,f2=0;
		for(int i=0;i<n;i++)
			if(s[i]=='1'){
				f1=1;
				break;
			}
		for(int i=0;i<n;i++)
			if(t[i]=='1'){
				f2=1;
				break;
			}
		
		if((f1==1 && f2==1) || f1==0 && f2==0)
			cout<<"YES";
		else
			cout<<"NO";
			
	}
	return 0;
}
