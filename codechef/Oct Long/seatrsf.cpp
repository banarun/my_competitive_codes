#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <cctype>
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
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iomanip> 
using namespace std; 
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;

#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
#define mp(A,B) make_pair(A,B)
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define mod 1000000007
#define N 100002
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

ull int power(ull int x, ull int y)
{
    ull int temp;
    if (x == 0)
		return 0;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return ((x*((temp*temp)%mod))%mod);
}


int main()
{
	int t;
	t=inp();
	while(t--){
		ll n,m,q,k;
		scanf("%lld%lld%lld%lld",&n,&m,&q,&k);
		ll ans=0;
		if(m-q>0 && n>1){
			ll temp2=power(q-1,n);
			ans=power(q+1,n);
			ll temp=power(q,n);
			//dbg(temp,ans,temp2);
			ans=(((2LL*mod+ans-2*temp+temp2)%mod)*(m-q))%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
