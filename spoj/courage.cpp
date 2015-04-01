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

ll getMid(ll s, ll e) {  return s + (e -s)/2;  }
 
ll getSumUtil1(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return 0;
 
    ll mid = getMid(ss, se);
    return getSumUtil1(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil1(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil1(ll *st ,	ll ss, ll se, ll i, ll diff, ll index)
{
    if (i < ss || i > se)
        return;
    st[index] = st[index] + diff;
    if (se != ss)
    {
        ll mid = getMid(ss, se);
        updateValueUtil1(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil1(st, mid+1, se, i, diff, 2*index + 2);
    }
}
ll updateValueUtil(ll *st ,	ll ss, ll se, ll i, ll diff, ll index)
{
    if (i < ss || i > se){
        return st[index];
	}
     st[index] = st[index] + diff;
    if (se != ss)
    {
        ll mid = getMid(ss, se);
        st[index]=min(updateValueUtil(st, ss, mid, i, diff, 2*index + 1),updateValueUtil(st, mid+1, se, i, diff, 2*index + 2));
    }
   // dbg(index,st[index]);
    return st[index];
}

void updateValue(ll arr[], ll *st, ll n, ll i, ll diff)
{
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
void updateValue1(ll arr[], ll *st, ll n, ll i, ll diff)
{
    updateValueUtil1(st, 0, n-1, i, diff, 0);
}
 
ll getSum(ll *st, ll n, ll qs, ll qe)
{
    return getSumUtil1(st, 0, n-1, qs, qe, 0);
}

ll constructSTUtil1(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
 
    ll mid = getMid(ss, se);
    st[si] =  constructSTUtil1(arr, ss, mid, st, si*2+1) +
              constructSTUtil1(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
ll *constructST1(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n))); 
    ll max_size = 2*(ll)pow(2, x) - 1; 
    ll *st = new ll[max_size];
 
    constructSTUtil1(arr, 0, n-1, st, 0);
    return st;
}
 
 
 ll minVal(ll x, ll y) { return (x < y)? x: y; }
 
ll RMQUtil(ll *st, ll ss, ll se, ll qs, ll qe, ll index)
{
    if (qs <= ss && qe >= se)
        return st[index];
 
    if (se < qs || ss > qe)
        return LLONG_MAX;

    ll mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}
 ll RMQ(ll *st, ll n, ll qs, ll qe)
{
    return RMQUtil(st, 0, n-1, qs, qe, 0);
}
ll constructSTUtil(ll arr[], ll ss, ll se, ll *st, ll si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }

    ll mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

ll *constructST(ll arr[], ll n)
{
    ll x = (ll)(ceil(log2(n))); 
    ll max_size = 2*(ll)pow(2, x) - 1; 
    ll *st = new ll[max_size];
    constructSTUtil(arr, 0, n-1, st, 0);
    return st;
}

 ll inp(){ll r=0;ll c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}

int main()
{
    ll arr[100001] ;
    ll n ;
	n=inp();
	for(ll i=0;i<n;i++){
		arr[i]=inp();
	}
	
    ll *st = constructST(arr, n);
	ll *st1 = constructST1(arr, n);
    ll q;
    q=inp();
    while(q--){
		char s[10];
		scanf("%s",s);
			ll x,y;
			x=inp();
			y=inp();
		if(s[0]=='C'){
			ll qs=x;
			ll qe=y;
			ll s=getSum(st1,n,qs,qe);
			ll a=RMQ(st, n, qs, qe);
			//dbg(s,a);
			long long ans=s-a;
			printf("%lld\n",ans);
		}
		else{
			if(s[0]=='E')
				x*=-1;
			arr[y]+=x;
			
			updateValue1(arr, st1, n, y, x);
			updateValue(arr,st,n,y,x);
		}

	}
    return 0;
}
