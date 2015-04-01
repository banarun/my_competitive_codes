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
ll a[N];
bool f1(ll p,ll b)
{
	if(p+b==0){
		if(p>0)
			return true;
		return false;
	}
	return abs(p)>abs(b);
}

int main()
{
	int n;
	n=inp();
	int k=inp();
	ll ans=0;
	ll v=0;
	int nc=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		if(a[i]<0)
			nc++;
	}
	if(k==n){
		for(int i=0;i<n;i++)
			ans+=a[i];
		cout<<ans<<endl;
		return 0;
	}
	sort(a,a+n,f1);
	if((nc==n && k%2==1)){
		for(int i=0;i<k;i++){
			ans+=a[n-1-i];
		}
		cout<<ans<<endl;
		return 0;
	}
	ll f=0;
	for(int i=0;i<k;i++){
		ans+=abs(a[i]);
		if(a[i]<0){
			if(f)f=0;else f=abs(a[i]);
		}
	}
	//dbg(ans,k,f);
	int i=k;
	a[n]=0;
	ll p=0;
	if(f){
		int miv=0;
		while(i<n && a[i]<0){
			//miv=a[i];
			i++;
		}
		ll p1=LLONG_MIN,p2=LLONG_MIN;
		if(i<n)
			p1=a[i]-f;
		i=k-1;
		while(i>=0 && a[i]<0)
			i--;
		int j=k;
		while(j<n && a[j]>=0)
			j++;
		//dbg(i,j);
		if(i>=0 && j<n)
			p2=abs(a[j])-a[i];
		//dbg(p1,p2);
		p=max(p1,p2);
	}
	cout<<ans+p<<endl;
	return 0;
}
