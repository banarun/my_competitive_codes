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
#define N 300002
int b[N];
pair <int,int> pr[N];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		pr[i].first=y;
		pr[i].second=x;
	}
	sort(pr,pr+n);
	multiset<int> cs;
	multiset<int>::iterator it;
	for(int i=0; i<k; ++i) {
		int c;
		scanf("%d",&c);
		cs.insert(c);
	}
	ll ans=0;
	for(int i=n-1; i>=0; --i) {
		int m = pr[i].second;
		it = cs.lower_bound(m);
		if (it==cs.end()) continue;
		cs.erase(it);
		ans += pr[i].first;
	}
	printf("%lld\n",ans);
	return 0;
}
