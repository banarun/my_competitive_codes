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
#define N 2050

int visited[N][N];
stack<int> stx,sty;
char a[N][N];
int ans=0;
int n,m;
void foo(int x,int y)
{
	stx.push(x);
	sty.push(y);
	while(!stx.empty()){
		x=stx.top();
		y=sty.top();
		sty.pop();stx.pop();
		
		if(x<0 || y<0 || x>=n || y>=m || visited[x][y])
			continue;
		visited[x][y]=1;
		if(a[x][y]=='-'){
			for(int i=-1;i<2;i++){
				for(int j=-1;j<2;j++){
					if(!(i==0 && j==0)){
	
						stx.push(x+i);
						sty.push(y+j);
					}
				}
			}
		}
	}
}

int main()
{
	int t;
	int p=0;
	scanf("%d",&t);
	while(t--){
		p++;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				visited[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
			scanf("%s",a[i]);
		ans=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]=='-' && !visited[i][j]){
					ans++;
					foo(i,j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]>'0' && a[i][j]<'9' && !visited[i][j]){
					ans++;
				}
			}
		}
		printf("Scenario #%d: %d\n",p,ans);
	}
	return 0;
}

