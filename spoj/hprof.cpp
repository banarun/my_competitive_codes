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
typedef pair<int,int> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X)
#define ln length()
#define inp(X) scanf("%d",&X)
#define sl(n) 	scanf("%I64",&n)
#define mod 1000000007 
#define N 100002

int ans=0,n;
string s;
void foo(int p)
{
	if(p>n)
		return;
	if(p==n){
		ans++;
		return;
	}
	foo(p+1);
	if(p+1<n && s[p]>'0' && s[p]<'2')
		foo(p+2);
	else if(p+1<n && s[p]=='2' && s[p+1]=='0')
		foo(p+2);
}

int main() 
{ 
	cin>>s;
	n=s.ln;
	foo(0);
	cout<<ans<<endl;
	return 0; 
}
