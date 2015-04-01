#include <iostream>
#include <algorithm>
using namespace std;

long long int a[2000000];
int main(){

	long long int n,p;
	unsigned long long int ans=0;
	cin>>n;
	p=n/4;
	for(int i=0;i<n;i++)
		cin>>a[i];
		
	sort(a,a+n);
	int b=n,k=0;
	while(b){
		b=b/4;
		k++;
	}
	k--;
	int d=4;
	ans=a[n-1];
	for(int j=0;j<n;j++){
		ans=ans+a[n-1-j]*k;
		if((j+1)==d){
			k=k-1;
			d=d*4;
		}
	}
	cout<<ans<<endl;
}
