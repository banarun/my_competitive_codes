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
int main()
{
	int t;
	t=inp();
	while(t--){
		int n=inp();
		long double even=0,odd=0;
		for(int j=0;j<n;j++){
			int k=inp();
			set<int> s;
			for(int i=0;i<k;i++){
				int p=inp();
				s.insert(p);
			}
			vector<int> v;
			for(set<int>::iterator it=s.begin();it!=s.end();it++){
				v.pb(*it);
			}
			k=v.sz;
			int i=0;
			if(v[0]%2){
				while(i<k && v[i]%2){
					odd++;
					i++;
				}
			}	
			else{
				while(i<k && v[i]%2==0){
					even++;
					i++;
				}
			}
			ll int onepos=i-1;
			//dbg(onepos);
			
			for(i=onepos+1;i<k;i++){
				ll powr=(1LL<<i-onepos);
				if(v[i]%2){
					odd+=(1.0/powr);
				}
				else{
				//	dbg(1.0/powr);
					even+=(1.0/powr);
				}
			}
		}
		//dbg(even,odd);
		if(even==odd){
			printf("DON'T PLAY\n");
		}
		else if(even>odd){
			printf("EVEN\n");
		}
		else
			printf("ODD\n");
	}
	return 0;
}
