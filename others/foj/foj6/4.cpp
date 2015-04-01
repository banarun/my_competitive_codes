#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main(){
	int t,n,m;
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		scanf("%d",&n);
		int p=n;
		int count=0;
		while(n){
			int k=n%10;
			n=n/10;
			if(k!=0 && p%k==0){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
