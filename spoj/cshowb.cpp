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
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
stack<int> st[7];
int main()
{
	
	int n,m;
	n=inp();
	m=inp();
	ll ans=0;
	for(int i=0;i<n;i++){
		int s,pos;
		s=inp();
		pos=inp();
		//dbg(pos);
		while(!st[s].empty() && st[s].top()>pos){
			st[s].pop();
			ans++;
		}
		if(!st[s].empty() && st[s].top()==pos){
			continue;
		}
		st[s].push(pos);
		ans++;
		
	}
	printf("%d\n",ans);
	return 0;
}
