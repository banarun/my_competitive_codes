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

int a[50],b[50];
double p[50];
int ha[17],hb[17];
int n;
long double ans=0,prod=1;
int c=0;
void foo(int k)
{
	if(k==n){
		c++;
		prod=1;
		for(int i=0;i<n;i++){
			//cout<<a[i]<<" "<<b[i]<<endl;
			ha[a[i]]++;
			//hb[b[i]]++;
			prod=prod*p[i];
		}
		int f=0;
		for(int i=1;i<=16;i++){
			if(ha[i]>1){
				f=1;
			}
			ha[i]=0;
			//hb[i]=0;
		}
		if(f==0){
			//cout<<prod<<endl;
			ans+=prod;
		}
		return;
	}
	foo(k+1);
	
	p[k]=1-p[k];
	swap(a[k],b[k]);

	foo(k+1);
	p[k]=1-p[k];
	swap(a[k],b[k]);
}

int main() 
{
	
	int t;
	scanf("%d",&t);
	while(t--){
		ans=0;
		prod=1;
		int pt;
		scanf("%d",&n);
		map<int,int> mp;
		map<int,int>::iterator it;
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&pt,&a[i],&b[i]);
			//mp[a[i]]++;
			//mp[b[i]]++;
			p[i]=(pt/100.0);
		}
		ans=0;
		if(n>16){
			printf("0.0000000000\n");
			continue;
		}
		prod=1;
		foo(0);
		printf("%.9Lf\n",ans);
		//	dbg(c);
	}
	return 0; 
}
