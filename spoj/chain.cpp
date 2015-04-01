#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int t,a;
	cin>>t;
	int n,k,i;
	for(int j=0;j<t;j++){
		cin>>n>>k;
		set< set<int> > v;
		set<int> s;
		set<int> g1,g2,g3;
		for(i=0;i<n;i++){
			s.insert(i+1);
			v.insert(s);
		}
		for(i=0;i<k;i++){
			cin>>a;
			if(a==1){
				if(x>n||y>n){
					count++;
				}
			}
		}
		
	}
	return 0;
}
