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
#define N 550
double dp[700][2000];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int n=N;
	for(int i=1;i<=6;i++)
		dp[1][i]=1.0/6;
	for(int i=2;i<n;i++){
		for(int j=i;j<=6*i;j++){
			for(int p=1;p<=6;p++){
				if(j-p>0)
					dp[i][j]+=dp[i-1][j-p]/6;
			}
		}
	}
	int t=inp();
	while(t--){
		n=inp();
		int m=inp();
		int ans=0;
		if(n<550 && m<2000){
			ans=dp[n][m]*100;
		}
		printf("%d\n",ans);
	}
	return 0;
}
