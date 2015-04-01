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

int a[6144][6144];
bool b[6144][6144];

ll in()
{
    ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

int main() 
{
	int t,g=0;
	
	t=in();
	while(t--){
		g++;
		int n,m,k;
		n=in();
		m=in();
		k=in();
		for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			a[i][j]=0;
			b[i][j]=false;
		}
		
		for(int i=0;i<k;i++){
			int p,q;
			p=in();
			q=in();
			for(int p1=0;p1<3;p1++){
				for(int p2=0;p2<3;p2++){
					if(p-1+p1>=0 && p-1+p1<n && q-1+p2>=0 && q-1+p2<m)
						a[p-1+p1][q-1+p2]++;
				}
			}
			b[p][q]=true;
		}
		printf("Scenario #%d:\n",g);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(b[i][j]){
					putchar_unlocked('*');
				}
				else if(!a[i][j]){
					putchar_unlocked('-');
				}
				else{
					putchar_unlocked('0'+a[i][j]);
				}
			}
			putchar_unlocked('\n');
		}
	}
	return 0; 
}
