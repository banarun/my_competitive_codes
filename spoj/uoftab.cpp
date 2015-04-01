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

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[5],s[5],o[5];
		for(int i=0;i<n;i++){
			cin>>a[i]>>s[i]>>o[i];
		}
		int time=0;
		while(1){
			int f=0;
			for(int i=0;i<n;i++){
				if((a[i]+s[i])==o[i]){
					o[i]=0;
				}
				if(a[i]<=o[i] && o[i]<a[i]+s[i]){
					f++;
				}
				o[i]++;
			}
			if(f==n)
				break;
			if(time>1000000)
				break;
			time++;
		}
		if(time>1000000)
			printf("Foxen are too powerful\n");
		else
		printf("%d\n",time);
	}
	
	
	return 0;
}
