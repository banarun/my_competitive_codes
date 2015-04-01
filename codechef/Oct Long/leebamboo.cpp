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
#define mod 1000000007 
#define N 100002 
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main() 
{ 
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		int a[100],b[100];
		scanf("%d",&n);
		int dif=0;
		int f=0;
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(int i=0;i<n;i++){
			scanf("%d",&b[i]);
			if(b[i]!=a[i])
				f=1;
			dif+=b[i]-a[i];
		}
		
		if(f==0){
			printf("0\n");
			continue;
		}
		
		if(n==1){
			if(dif>0){
				printf("-1\n");
			}
			else
				printf("%d\n",-1*dif);
			continue;
		}
		
		if(n==2){
			if(dif!=0){
				printf("-1\n");
			}
			else{
				printf("%d\n",abs(a[0]-b[0]));
			}
			continue;
		}
		if(dif<=0){
			printf("-1\n");
			continue;
		}
		int ans;
		
		if(dif%(n-2)==0)
			ans=dif/(n-2);
		else{
			printf("-1\n");
			continue;
		}
		f=0;
		int k=0;
		for(int i=0;i<n;i++){
			if( (ans-(b[i]-a[i]))<0){
				f=1;
				break;
			}
			if((abs(ans-(b[i]-a[i])))%2){
				f=1;
				break;
			}

			k+=(ans-(b[i]-a[i]))/2;
		}
		if(f==0 && k==ans){
			printf("%d\n",ans);
		}
		else
			printf("-1\n");
	}
	return 0; 
}
