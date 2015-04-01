#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	int p=n-k;
	unsigned long long int ans=1;
	for(int i=1;i<=p;i++){
		ans=(ans*p)%1000000007;
	}
	
	for(int i=1;i<k;i++){
		ans=(ans*k)%1000000007;
	}
	
	cout<<ans;
	return 0;
}

