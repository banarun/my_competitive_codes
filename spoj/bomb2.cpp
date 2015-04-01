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
#define N 100002

map<int,multiset<int> > mpx,mpy;
map<int,multiset<int> >::iterator it;
multiset<int>::iterator setit;

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) && !(n==0 && m==0)){
		mpx.clear();
		mpy.clear();
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			mpx[x].insert(y);
			mpy[y].insert(x);
		}
		int a,b;
		for(int i=0;i<m;i++){
			scanf("%d%d",&a,&b);
			if(!a){
				printf("%d\n",mpx[b].sz);
				for(setit=(mpx[b]).begin();setit!=mpx[b].end();setit++){
					mpy[*setit].erase(b);
				}
				mpx[b].clear();
			}
			else{
				printf("%d\n",mpy[b].sz);
				for(setit=(mpy[b]).begin();setit!=mpy[b].end();setit++){
					//dbg(*setit);
					mpx[*setit].erase(b);
				}
				mpy[b].clear();
			}
		}
	}
	return 0;
}
