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
#define sl(n) 	scanf("%lld",&n)
#define mod 1000000007 
#define N 100002 

int a[N];

int main() 
{ 
	int n,c=0;
	ll int k;
	inp(n);
	for(int i=0;i<n;i++){
		sl(k);
		if(k<0){
			a[c]=k;
			c++;
		}
	}
	int x;
	inp(x);
	n=c;
	sort(a,a+n);
	ull ans=0;
	k=0;
	if(x<n)
		k=abs(a[x]);
	ans+=1LL*x*k;
	for(int i=0;i<n && i<x;i++)
		ans+=abs(a[i])-k;
	printf("%llu",ans);
	return 0; 
}
