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
#define N 10002
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
ll ans[N];
ll a[N];
int main()
{
	int t;
	t=inp();
	while(t--){
		int n,u;
		n=inp();
		u=inp();
		for(int i=0;i<=n;i++)
			a[i]=0;
			
		for(int i=0;i<u;i++){
			int l,r,val;
			l=inp();
			r=inp();
			val=inp();
			a[l]+=val;
			a[r+1]-=val;
		}
		ll sum=0;
		for(int i=0;i<n;i++){
			sum+=a[i];
			ans[i]=sum;
		}
		int q=inp();
		for(int i=0;i<q;i++){
			int pos=inp();
			printf("%lld\n",ans[pos]);
		}
	}
	return 0;
}
