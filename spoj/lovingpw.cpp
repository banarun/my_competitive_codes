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
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;
#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
typedef pair<ll,ll> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X)
#define ln length()
#define inp(X) scanf("%d",&X)
#define sl(n) 	scanf("%I64",&n)
#define mod 1000000007 
#define N 100002

ll a[65];

inline unsigned ll getLeftmostBit (ll n)
{
   ll m = 0;
   while (n  > 1)
   {
      n = n >> 1;
      m++;
   }
   return m;
}

unsigned ll countSetBits(unsigned ll n)
{
	if(n==0)
		return 0;
	ll ans=0;
   ll m = getLeftmostBit (n);
   ans+=(m*a[m-1])%mod;
   ans+=(n-a[m]+1);
   
    return (ans+ countSetBits(n-a[m]))%mod;
}
 
int main()
{
   a[0]=1;
   for(int i=1;i<=64;i++)
	a[i]=a[i-1]*2;
	int t;
	scanf("%d",&t);
	while(t--){
		ll n;
		scanf("%lld",&n);
		ll ans=countSetBits(n);
		printf ("%lld\n",ans );
	}
   return 0;
}
