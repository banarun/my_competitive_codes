#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <list> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility> 
using namespace std; 

#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000

int main() 
{ 
	ll int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		ll int a[N];
		for(ll int i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		ll int j=n-1;
		ll int ans=0,i;
		ll int sum[100000];
		for(i=0;i<n && i<j;i++){
			sum[i]=a[i]+a[j];
			j--;
		}
		sort(sum,sum+i);
		cout<<sum[i-1]-sum[0]<<endl;
	}
	
	return 0; 
}
