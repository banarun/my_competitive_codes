#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <cctype>
#include <vector> 
#include <deque> 
#include <set> 
#include <list> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility>
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iomanip> 
using namespace std; 
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;

#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
typedef pair<int,int> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X) 
#define ln length()
#define inp(X) scanf("%d",&X)
#define sl(n) 	scanf("%I64",&n)
#define mod 1000000007 
#define N 100002 

int main() 
{
	char str[52];
	while(scanf("%s",str)>0){
		int lr[51],lg[51],rr[51],rg[51];
		int n=strlen(str);
		lr[0]=0;
		lg[0]=0;
		for(int i=0;i<n;i++){
			lr[i+1]=lr[i];
			lg[i+1]=lg[i];
			if(str[i]=='R')
				lr[i+1]++;
			else
				lg[i+1]++;
		}
		rr[n]=0;
		rg[n]=0;
		for(int i=n-1;i>=0;i--){
			rr[i]=rr[i+1];
			rg[i]=rg[i+1];
			if(str[i]=='R')
				rr[i]++;
			else
				rg[i]++;
		}
		int ans=100;
		for(int i=0;i<=n;i++){
			ans=min(ans,lg[i]+rr[i]);
		}
		printf("%d\n",ans);
	}
	return 0; 
}
