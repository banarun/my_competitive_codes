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
	ll int r,g,b;
	cin>>r>>g>>b;
	
	ll ans=r/3+g/3+b/3;
	if(r==0 || g==0 || b==0){
		cout<<ans<<endl;
		return 0;
	}
	
	r=r%3;
	g=g%3;
	b=b%3;
	
	if(r+g+b==4 && (r==0 || g==0 || b==0)){
		ans+=1;
		cout<<ans<<endl;
		return 0;
	}
	
	ans+=min(r,min(g,b));
	cout<<ans<<endl;
	return 0; 
}
