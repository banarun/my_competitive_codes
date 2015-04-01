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
	int t;
	cin>>t;
	while(t--){
		double p;
		scanf("%lf",&p);
		if(p<0.5){
			p=1-p;
		}
		double ans=2*p*(1-p)*10000+10000-10000*p+10000*(2*p-1);
		printf("%lf\n",ans);
	}
	return 0; 
}
