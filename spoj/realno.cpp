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
#define N 300002
//float a[N];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		float mione=10.0f;
		float fp;
		float mn=3,mx=-17,mx2=-13;
		int an=0,ptr=0,c=0;
		for(int i=0;i<n;i++){
			scanf("%f",&fp);
			if(fp>=1.0f){
				mione=min(fp,mione);
			}
			else{
				c++;
				mx=max(fp,mx);
				if(c>1 && fp==mx)
					mx2=mx;
				else if(c>1 && fp>mx2)
					mx2=fp;
				mn=min(fp,mn);
			}
		}
		if( mn+mione < 2.0f){
			puts("found");
		}
		else if(c>1 && mx2 + mx >1.0f){
			puts("found");
		}
		else{
			puts("not found");
		}
	}
	
	return 0;
}
