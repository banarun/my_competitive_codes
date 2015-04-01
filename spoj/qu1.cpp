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
#include <list>
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
int main()
{
	int t;
	t=inp();
	while(t--){
		int n;
		list <int> l;
		list <int>::iterator it;
		pair < int, int> pr[10001];
		n=inp();
		int a,b;
		for(int i=0;i<n;i++){
			a=inp();
			pr[i].first=a;
		}
		for(int i=0;i<n;i++){
			b=inp();
			pr[i].second=b;
		}
		
		sort(pr,pr+n);
		for(int i=n-1;i>=0;i--){
			it=l.begin();
			for(int j=0;j<pr[i].second;j++)
				it++;
				l.insert(it,pr[i].first);
		}
		
		for(it=l.begin();it!=l.end();it++)
			printf("%d ",(*it));
		putchar_unlocked('\n');
	}
	return 0;
}
