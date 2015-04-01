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
vector<ll> ans;
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	ll n=100000;
	n=n;
	for(ll i=1;i<=n;i++){
		ll temp=i*i;
		int f=0;
		while(temp){
			int val=temp%10;
			if(val==0 || val==1 || val==4 || val==9){}
			else
				f=1;
			temp/=10;
		}
		if(!f){
			ans.pb(i*i);
			//cout<<i*i<<" ";
		}
	}
	//dbg(ans.sz);
	int t=inp();
	while(t--){
		ll a,b;
		a=inp();
		b=inp();
		printf("%d\n",upper_bound(ans.begin(),ans.end(),b)-lower_bound(ans.begin(),ans.end(),a	));
	}
	return 0;
}
