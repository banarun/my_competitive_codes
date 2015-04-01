#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n,p,q;
	vector<int> a,g;
	scanf("%d",&n);
	int s1=0,s2=0;
	vector<char> v;
	for(int i=0;i<n;i++){
		scanf("%d%d",&p,&q);
	//	a.push_back(p);
	//	g.push_back(q);
		
		if(p<=q){ 
			if(s1+p-s2<=500){
				s1=s1+p;
				printf("A");
			}
			else{
				s2=s2+q;
				printf("G");
			}
		}
		else{
			if(s2+q-s1<=500){
				s2=s2+q;
				printf("G");
			}
			else{
				s1=s1+p;
				printf("A");
			}
		}
	}
		
	return 0;
}
