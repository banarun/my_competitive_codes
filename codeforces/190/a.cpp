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
	int n,m;
	cin>>n>>m;
	if(n>m){
		int a=n;
		int b=m;
	cout<<n+m-1<<endl;
	for(int i=0;i<a;i++){
		cout<<i+1<<" "<<1<<endl;
	}
	for(int i=1;i<b;i++){
		cout<<1<<" "<<i+1<<endl;
	}
	}
	else{
		int a=m;
		int b=n;
	cout<<n+m-1<<endl;
	for(int i=0;i<a;i++){
		cout<<1<<" "<<i+1<<endl;
	}
	for(int i=1;i<b;i++){
		cout<<i+1<<" "<<1<<endl;
	}
	}
	return 0; 
}
