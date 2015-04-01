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
#define mp(A,B) make_pair(A,B)
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define mod 1000000007
#define N 100002


int toint(int* a,int n)
{
	int val=0,powe=1;
	for(int i=0;i<n;i++){
		val+=a[i]*powe;
		powe*=2;
	}
	return val;
}
int main()
{
	int t;
	cin>>t;
	int zero[100];
	for(int i=0;i<100;i++){
		zero[i]=0;
	}
	while(t--){
		int n;
		int v[100];
		
		int ptr=0;
		cin>>n;
		while(n){
			v[ptr]=n%2;
			ptr++;
			n=n/2;
		}
		int b[100];
		for(int i=0;i<ptr;i++){
			int num1=toint(a,i);
			for(int j=0;j<ptr;j++){
				if(j<i)
					b[i]=0;
				else
					b[i]=a[i];
			}
		}
		dbg(num);
	}
	return 0;
}
