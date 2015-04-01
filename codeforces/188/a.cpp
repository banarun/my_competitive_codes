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
#define N 100002 

int main() 
{ 
	ll int n,k;
	cin>>n>>k;
	ll int p=n/2+n%2;
	
	if(k<=p){
		cout<<2*(k)-1<<endl;
	}
	else{
		k=k-p;
		cout<<2*k<<endl;
	}
	return 0; 
}
