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
int a[N];
int main()
{
	int n,m;
	cin>>n>>m;
	int f=0;
	for(int i=0;i<m;i++){
		cin>>a[i];
		if(a[i]==1 || a[i]==n)
			f=1;
	}
	sort(a,a+m);
	
	for(int i=0;i<m-2;i++){
		if(a[i+1]-a[i]==1 && a[i+2]-a[i+1]==1)
			f=1;
	}
	if(f){
		cout<<"NO\n";
		
	}
	else
		cout<<"YES\n";
	return 0;
}
