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
#define N 503
char a[N][N];
ll dp[N][N];
ll dp2[N][N];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	t=inp();
	while(t--){
		int n;
		n=inp();
		char c;
		for(int i=0;i<n;i++){
			scanf("%s",a[i]);
		}
		for(int i=0;i<=n+1;i++){
			dp[i][0]=INT_MIN;
			dp[0][i]=INT_MIN;
			dp2[i][n+1]=INT_MIN;
			dp2[n+1][i]=INT_MIN;
		}
		dp[0][1]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(i==1 && j==1)
					dp[i][j]=0;
				if(a[i-1][j-1]=='*')
					dp[i][j]++;
				
				if(a[i-1][j-1]=='#')
					dp[i][j]=INT_MIN;
			}
		}
		ll ans=-1;
		for(int i=n;i>0;i--){
			for(int j=n;j>0;j--){
				dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1]);
				if(i==n && j==n){
					dp2[i][j]=0;
				}
				if(a[i-1][j-1]=='*')
					dp2[i][j]++;
				if(a[i-1][j-1]=='#')
					dp2[i][j]=INT_MIN;
				if(i+j==n+1){
					int f=0;
					if(a[i-1][j-1]=='*')
						f++;
					ans=max(dp[i][j]+dp2[i][j]-f,ans);
					//dbg(i,j,dp[i][j],dp2[i][j]);
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

