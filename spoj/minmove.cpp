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
int main()
{
	string s;
	cin>>s;
	int n=s.ln;
	int ptr=1,ans=0,cnt=0;
	
	while(ptr<n){
		if(s[(ans+cnt)]<s[(ptr+cnt)%n]){
			ptr+=cnt+1;
			cnt=0;
		}
		else if(s[(ans+cnt)]>s[(ptr+cnt)%n]){
			ans=max(ptr,ans+cnt+1);
			ptr=ans+1;
			cnt=0;
		}
		else
			cnt++;
		if(ans+cnt>=n)
			break;
	}
	cout<<ans<<"\n";
	return 0;
	
}
