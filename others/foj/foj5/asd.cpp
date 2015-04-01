#include <iostream>
#include <set>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	set<long long int> s;
	long long int i,j,n,p;
	scanf("%lld",&n);
	int k;
	for(i=0;i<n;i++){
		scanf("%d",&k);
		if(k==1){
			scanf("%lld",&p);
			s.insert(p);
		}
		else if (k==2){
			if(!s.empty()){
				p=*(s.rbegin());
				printf("%lld\n",p);
				s.erase(p);
			}
			else{
				printf("IGNORE\n");
			}
		}
	}
	
}
