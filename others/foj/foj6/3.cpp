#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	long long int t,n,m;
	
	scanf("%lld",&t);
	for(int z=0;z<t;z++){
		cin>>n;
		set<long long int> s;
		set<long long int>::iterator it;
		long long int xo=0,ind=-1;
		long long int p,a;
		for(int i=0;i<n;i++){
			cin>>a;
			s.insert(a);
		}
		for(it=s.begin();it!=s.end();it++){
			xo=xo^(*it);
		}
		long long int max=xo;
		
		for(it=s.begin();it!=s.end();it++){
			p=xo^(*it);
			if(p>=max){
				max=p;
				ind=*it;
			}
		}
		
		if(ind==-1)
			cout<<"STAY"<<endl;
		else
			cout<<ind<<endl;
	}
	return 0;
}
