#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(n==k){
		for(int i=n;i>0;i--)
		cout<<i<<" ";
		return 0;
	}
	long long int p=k+1;
	
	for(int i=0;i<k+1;i++)
		cout<<p--<<" ";
	p=k+2;
	for(int i=0;i<n-k-1;i++)
		cout<<p++<<" ";
	return 0;
}
