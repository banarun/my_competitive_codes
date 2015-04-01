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
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		string s;
		cin>>s;
		stack<pair<int,int> > st;
		pair<int,int> pr;
		ll ans=0;
		int dpt=0;
		for(int i=0;i<n;i++){
			if(s[i]=='7' && !st.empty()){
				pr=st.top();
				ans+=pr.first;
				st.pop();
				dpt=0;
			}
			if(s[i]=='4'){
				dpt++;
				st.push(mp(i+1,dpt));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
