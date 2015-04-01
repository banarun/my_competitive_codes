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
#define N 1000001
bool isprime[N];
ll psqr[N];
int prims[N];
bool check[N];
int main()
{
	int t;
	int sqrtN=sqrt(N);
	
	for(ll i=2;i<N;i++){
		isprime[i]=true;
		psqr[i]=i*i;
	}
	for(int i=2;i<=sqrtN;i++){
		for(int j=i*i;j<=N;j+=i){
			isprime[j]=false;
		}
	}
	int ptr=0;
	for(int i=2;i<N;i++){
		if(isprime[i]){
			prims[ptr++]=i;
		}
	}
	//dbg(ptr);
	scanf("%d",&t);
	while(t--){
		ll int s,e;
		scanf("%lld%lld",&s,&e);
		if(s==1)
			s++;
		ll *sptr=lower_bound(psqr,psqr+N,s);
		ll *eptr=upper_bound(psqr,psqr+N,e);
		int spos=sptr-psqr;
		int epos=eptr-psqr;
		int ans=0;
		
		for(int i=spos;i<epos;i++){
			ll num=psqr[i];
			ll srt=i;
			int cnt=0;
			for(int i=2;i<srt;i++){
				if(num%i==0){
					cnt++;
				}
			}
			if(isprime[2*cnt+3]){
				//dbg(num,2*cnt+3);
				ans++;
			}
		}
		//dbg(ans);
		if( e<=1000000){
			for(int i=s;i<=e;i++)
				if(isprime[i]){
					//dbg(i);
					ans++;
				}
			printf("%d\n",ans);
			continue;
		}
		if(s<=1000000){
			for(int i=s;i<1000000;i++)
				if(isprime[i])
					ans++;
			s=N;
		}
		for(int i=0;i<ptr;i++){
			ll val=prims[i];
			ll num=(s/val)*val;
			if(num<s)
				num+=val;
			for(ll j=num;j<=e;j+=val){
				check[j-s]=true;
			}
		}
		for(ll i=s;i<=e;i++){
			if(!check[i-s]){
				//dbg(i);
				ans++;
			}
			check[i-s]=false;
		}
		printf("%d\n",ans);
	}
	return 0;
}
