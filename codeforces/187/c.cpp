#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
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
#define N 200002 

ll int a[N];
ll int t[N];
int main() 
{ 
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	ll int p=0;
	int m=n;
	int j=2;
	for(int i=2;i<=n;i++){
		if(p-(m-j)*(j-1)*a[i]<k){
			m--;
			j--;
			cout<<i<<endl;
		}
		else{
			p=p+(j-1)*a[i];
		}
		j++;
	}
	return 0; 
}
