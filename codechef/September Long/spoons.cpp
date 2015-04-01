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

ull in()
{
    ull r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}


ull int arr[]={0,1,2,3,6 ,10 ,20 ,35 ,70 ,
126 ,
252 ,
462 ,
924 ,
1716 ,
3432 ,
6435 ,
12870 ,
24310 ,
48620 ,
92378 ,
184756 ,
352716 ,
705432 ,
1352078 ,
2704156 ,
5200300 ,
10400600 ,
20058300 ,
40116600 ,
77558760 ,
155117520 ,
300540195LL ,
601080390LL ,
1166803110LL ,
2333606220LL ,
4537567650LL ,
9075135300LL ,
17672631900LL ,
35345263800LL ,
68923264410LL ,
137846528820LL ,
269128937220LL ,
538257874440LL ,
1052049481860LL ,
2104098963720LL ,
4116715363800LL ,
8233430727600LL ,
16123801841550LL ,
32247603683100LL ,
63205303218876LL ,
126410606437752LL ,
247959266474052LL ,
495918532948104LL ,
973469712824056LL ,
1946939425648112LL ,
3824345300380220LL ,
7648690600760440LL ,
15033633249770520LL ,
30067266499541040LL ,
59132290782430712LL ,
118264581564861424LL ,
232714176627630544LL ,
465428353255261088LL ,
916312070471295267LL ,
1832624140942590534LL };

int main() 
{
	int t=in();
	int k=4;
	int i=1;
	int sz=sizeof(arr)/sizeof(int);
	vector<ull> v(arr,arr+sz);
	vector<ull>::iterator it;
	while(t--){
		ll ans=in();
		
		it=upper_bound(v.begin(),v.end(),ans);
		printf("%d\n",v[it-v.begin()]);
		for(i=2;i<=66;i++){
			if(arr[i]>=ans){
				break;
			}
		}
		printf("%d\n",i);
	}
	return 0; 
}
