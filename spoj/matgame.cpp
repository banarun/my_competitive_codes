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
#define N 52
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int a[N];
int main()
{
    int t;
    t=inp();
    while (t--){
        int n, m;
        n=inp();
		m=inp();
        int nim = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++)
                a[j]=inp();
            int ans = 0;
            for (int j = m; j--; )
                
                ans = a[j] -(a[j] <= ans);
 
            nim ^= ans;
        }
        puts(nim? "FIRST" : "SECOND");
    }
    return 0;
}
