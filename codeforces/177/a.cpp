#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int a[300000],b[300000];
int main()
{
	int n;
	int k;
	int p=0;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		p=p+b[i]-a[i]+1;
	}
	if(p%k)
	cout<<k-p%k;
	else
	cout<<p%k;
	return 0;
}
