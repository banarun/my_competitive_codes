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

inline int isLucky(int p)
{
	while(p){
		if(p%10 == 4 || p%10==7)
			return 1;
		p=p/10;
	}
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int p=sqrt(n);
		int ans=0;

		for(int i=1;i<=p;i++){
			if(n%i==0){
				ans+=isLucky(i);
				ans+=isLucky(n/i);
				if(i==n/i){
					ans-=isLucky(i);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
