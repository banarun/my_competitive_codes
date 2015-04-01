#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int t[200000];
	int v[200000];
	cin>>n;
	int ma=0;
	int c=0;
	int va=0;
	int time;
	cin>>t[0]>>v[0];
	c=v[0];
	ma=c;
	for(int i=1;i<n;i++){
		cin>>t[i]>>v[i];
		c=c-t[i]+t[i-1];
		if(c<0)
		c=0;
		c=c+v[i];
		
		ma=max(ma,c);
		
	}
	cout<<c+t[n-1]<<" "<<ma<<endl;
	return 0;
}
