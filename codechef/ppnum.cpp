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
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		ll l,r;
		l=inp();
		r=inp();
		ll int p=l;
		ull k=1,pl=0;
		while(p){
			pl++;
			k=k*10;
			p=p/10;
		}
		ll kr=1,rl=0;
		p=r;
		while(p){
			rl++;
			p=p/10;
		}
		if(pl==rl){
			ll ans=((r*(r+1))/2-(l*(l-1))/2)*pl;
			ans=ans%mod;
			printf("%lld\n",ans);
			continue;
		}
		ll ans=((k*(k-1))/2-(l*(l-1))/2)*pl;
		ans=ans%mod;
		dbg(ans);
		for(int i=pl+1;i<rl;i++){
			pl++;
			ans+=((((((k*5)%mod*(k*10-1)%mod))%mod-(k*(k-1)/2))*pl)%mod+mod)%mod;
			k=k*10;
		}
		dbg(ans);
		ans+=(((r*(r+1))/2-(k*(k-1))/2)*rl)%mod;
		ans=ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
