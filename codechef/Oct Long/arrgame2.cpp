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
ll x[N],y[N];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	t=inp();
	
	while(t--){
		int n;
		int xc=0,yc=0;
		n=inp();
		for(int i=0;i<n;i++){
			x[i]=inp();
			if(x[i]==1){
				xc++;
			}
			if(x[i]==2)
				x[i]=4;
		}
		sort (x,x+n);
		for(int i=0;i<n;i++){
			y[i]=inp();
			if(y[i]==1)
				yc++;
			if(y[i]==2)
				y[i]=4;
		}
		sort(y,y+n);
		double ans=0;
		for(int i=0;i<n;i++){
			if(y[i]==1){
				ans+=n-xc;
				continue;
			}
			ll *k=lower_bound(x,x+n,y[i]);
			ll val=(k-x)-xc;
			ans+=val;
		}
		printf("%lf\n",ans/n);
	}
	
	return 0;
}
