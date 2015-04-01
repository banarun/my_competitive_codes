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
ll mod;
#define N 100002

ull int power(ull int x, ull int y)
{
    ull int temp;
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
	cin>>t;
	while(t--){
		ll int n,m;
		cin>>n>>m;
		if(n>=m){
			cout<<0<<"\n";
			continue;
		}
		ll int ans=m-1;
		mod=m;
		for(int i=m-1;i>n;i--){
			//dbg(ans);
			//dbg(i,m-1,pow(i,m-1));
			ans=ans*power(i,m-2)%m;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
