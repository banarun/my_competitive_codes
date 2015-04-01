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
	ll int fact[1000];
	fact[0]=1;
	for(int i=1;i<1000;i++){
		fact[i]=fact[i-1]*i%mod;
	}
	while(1){
		int n;
		scanf("%d",&n);
		int a[100],b[100];
		if(n==0)
			break;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		int sum=0;
		ll fac=1;
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
			sum+=abs(b[i]-a[i]);
			fac=fac*fact[abs(b[i]-a[i])]%mod;
		}
		ll ans=fact[sum]*power(fac,mod-2)%mod;
		printf("%lld\n",ans);
	}
	return 0; 
}
