#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
	int n,m;
	cin>>n>>m;
	int a[1001];
	int p=0;
	for(int i=0;i<m;i++){
		cin>>p;
		a[p]++;
	}
	if(n-m<2){
		cout<<n-m<<endl;
		return 0;
	}
	p=0;
	int b[1001],c[1001];
	for(int i=1;i<n;i++){
		int p=0;
		while(a[i]==0){
			p++;	
			b[i]=p;
			i++;
		}
		if(p>0)
			i--;
	}
	for(int i=n;i>0;i--){
		int p=0;
		while(a[i]==0){
			p++;
			c[i]=p;
			i--;
		}
		if(p>0){
			i++;
		}
	}
	for(int i=1;i<=n;i++){
		b[i]=min(c[i],b[i]);
		c[i]=0;
		cout<<b[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		c[b[i]]++;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		if(c[i]==0)
			break;
		for(int j=1;j<=c[i];j++){
			ans=(ans*j)%	1000000007;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}
