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
typedef pair<int,int> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X) 
#define ln length()
#define inp(X) scanf("%d",&X)
#define sl(n) 	scanf("%I64",&n)
#define mod 1000000007 
#define N 100002 

int main() 
{ 
	int t;
	scanf("%d",&t);
	while(t--){
		ull int n;
		ull ans=0;
		scanf("%llu",&n);
		ull int p=sqrt(n);
		ull int prev=n;
		ans=prev;
		int term=0;
		for(ll int i=2;i<=p;i++){
			ull int k=n/i;
			ans+=k;
			ans+=(i-1)*(prev-k);
			term+=prev-k;
			prev=k;
		}
		for(ll int i=p+1;i<=n-term;i++){
			ans+=n/i;
		}
		//ans+=n-p*p;
		ull int den=1LL*n*n;
		//printf("%llu\n",ans);
		
		ull a=min(ans,den);
		ull b=max(ans,den);
		while(a>0){
			ull temp=a;
			a=b%a;
			b=temp;
		}
		printf("%llu/%llu\n",ans/b,den/b);
	}
	return 0; 
}
