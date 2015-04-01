#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;
int a[200000],b[200000];
#define ll long long
int c[200000];
int main()
{
	int n,m,p,q,ma;
	int f=0,f1=0,f2=0,ma1=0,g=0;
	cin>>n>>m;
	
	for(int i = 0;i < m;i++){
		cin>>p>>q;
		
		c[p]++;
		
		c[q]++;
			
	}
	int k=0,r=0;
	int bus=0;
	int cnt=0;
	int star=0;
	int ring=0;
	
	for(int i=0;i<=100000;i++){
	
		if(c[i]==m)
			star++;
		if(c[i]!=2 && c[i]!=0)
			ring++;
		if(c[i]==2)
			bus++;
		if(c[i]==1)
			k++;
	}	
	if(k==2 && bus==n-2)
		cout<<"bus topology";
	else if(ring==0)
		cout<<"ring topology";
	else if(star==1)
		cout<<"star topology";
	else 
		cout<<"unknown topology";
	
	return 0;
}
