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
#define ll long long 
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
char h[52][52],chr;
int main() 
{ 
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		string s;
		for(int p=0;p<n;p++){
			int h1,w;
			
			scanf("%d%d",&h1,&w);
			for(int i=0;i<h1;i++){
				for(int j=0;j<w;j++){
					while((chr=getchar_unlocked())<32);
					h[i][j]=chr;
				}
			}
			int f=0;
			for(int i=1;i<h1-1;i++){
				for(int j=1;j<w-1;j++){
					if(h[i][j]=='x'){
						if(h[i][j-1]=='x' && h[i+1][j]=='x' && h[i-1][j]=='x' && h[i][j+1]=='x' & !h[i+1][j-1]=='x' && !h[i+1][j+1]=='x' && !h[i-1][j-1]=='x' && !h[i-1][j+1]=='x'){
							f=1;
							break;
						}
						if(h[i+1][j-1]=='x' && h[i+1][j+1]=='x' && h[i-1][j-1]=='x' && h[i-1][j+1]=='x' ){
							f=1;
							break;
						}
					}
				}
			}
			if(f==0)
				s.push_back('0');
			else
				s.push_back('x');
		}
		cout<<s<<"\n";
	}
	return 0; 
}
