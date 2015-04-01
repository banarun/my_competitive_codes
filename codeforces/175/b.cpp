#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int a[200001];
int main()
{
	int n,s,t;
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int count=0,flag=0,p,k;
	k=s;
	p=k;
	for(int i=0;i<n;i++){
		if(k==t){flag=1;break;}
		k=a[k];
		count++;
	}
	if(flag==1)
		cout<<count;
		else cout<<-1;
	return 0;
}
