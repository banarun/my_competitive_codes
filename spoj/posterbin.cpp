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
#define N 250002
int a[N];
int main()
{
	int n,t;
	stack<int> q;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&t,&a[i]);
	}
	int ans=0,f;
	int prev=INT_MAX;
	for(int i=0;i<n;i++){
		f=0;
		while(!q.empty() && q.top() > a[i]){
			q.pop();
			f=1;
		}
		if((!q.empty() && q.top()!=a[i])){
			ans++;
		}
		if(q.empty())
			ans++;
		q.push(a[i]);
	}
	cout<<ans<<endl;
	return 0;
}
