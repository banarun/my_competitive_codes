#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	int t,n,m,l;
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		cin>>n>>l>>m;
		
		if(n-m!=1)
		cout<<"NO\n";
		else if(l<1)
		cout<<"NO\n";
		else
		cout<<"YES\n";
	}
	return 0;
}
