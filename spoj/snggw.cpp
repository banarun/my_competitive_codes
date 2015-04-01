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
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;
#define ll long long 
#define ull unsigned long long
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define mod 1000000007 
#define N 100002
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		int ans;
		cin>>n;
		if(n==2){
			printf("DWON 3\n");
		}
		if(n%2){
			int p=n+n/2+1;
			int k=n/2;
			int val=n*n+1;
			ans=k*(k+1)/2;
			ans+=p;
			if(val>=ans){
				printf("DWON %d\n",val-ans);
			}
			else{
				printf("DDOWN\n");
			}
		}
		else{
			int val=n*n;
			int k=n/2;
			ll ans=k*(k+1)/2;
			ans+=n/2+1;
			if(val>=ans){
				printf("DWON %d\n",val-ans);
			}
			else
				printf("DDOWN\n");
		}
	}
	return 0;
}
