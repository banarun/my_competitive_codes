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

ll sum[N*10], a[18];

int main() {
	int n, m, i, j, tot, sz, mx;
	ll am, d, lst, st, nd;
	while(scanf("%d %d", &n, &m)==2) {
		for(i = 0; i < n; i++) 
			scanf("%lld", &a[i]);
		for(i = 0; i < m; i++) 
			scanf("%lld", &a[n+i]);
		tot=m+n;
		for(sz = 0, i = 0; i < (1<<tot); i++) {
			for(am = j = 0; j < tot; j++) {
				if(i & (1<<j)) {
					if(j < n) am += a[j];
					else am -= a[j];
				}
			}
			sum[sz++] = am;
		}
		sort(sum, sum + sz);
		scanf("%lld", &d);
		for(i = mx = 0; i < sz; i++) {
			lst = sum[i] + d - 1;
			j = upper_bound(sum + i, sum + sz, lst) - sum;
			if(j-i > mx) {
				mx = j-i;
				st = sum[i];
				nd = sum[i] + d - 1;
			}
		}
		printf("%lld %lld %d\n", st, nd, mx);
	}
	return 0;
}
