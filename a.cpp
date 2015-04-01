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

char a[8][8];
int flg1,flg2;
int visited[8][8];

int main()
{
	int t;
	cin>>t;
	while(t--){
		int k=0;
		int f=0;
		int c=0;
		int x[2]={},y[2]={};

		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				visited[i][j]=0;
				cin>>a[i][j];
				if(a[i][j]=='K')
					c++;
				if(!f && a[i][j]=='K'){
					x[k]=i;
					y[k]=j;
					k++;
					a[i][j]='.';
				}	
			}
		}

		dbg(x[0],x[1],y[0],y[1]);
		if(abs(x[1]-x[0])% 4 == 0 && abs(y[1]-y[0]) % 4 ==0)
			cout<<"YES\n";
		else
			cout<<"NO\n";	
	}
	return 0;
}
