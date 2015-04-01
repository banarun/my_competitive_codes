#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
	int n;
	pair<int,int> p[200];
	int a[200],b[200];
	int sum=0;
	cin>>n;
	int m=0;
	for(int i=0;i<n;i++){
		cin>>p[i].second>>p[i].first;
		sum+=p[i].first;
		m+=p[i].second;
	}
	sort(p,p+n);
	
	for(int j=0;j<n;j++){
	int t=0,w=0;
	w=sum;
	int k=j;
	for(int i=n-1;i>0;i--){
		if(p[i].second==2 && k>0){
			if(t>=w){
				if(m>t)
					m=t;
				break;
			}
			w=w-p[i].first;
			t=t+2;
			k--;
			
		}
	}
	for(int i=0;i<n;i++){
		if(t>=w){
			if(m>t)
				m=t;
			break;
		}
		if(p[n-i-1].second==1){
			t++;
			w=w-p[n-i-1].first;
		}
	}
	}
	cout<<m<<endl;
	return 0;
}
