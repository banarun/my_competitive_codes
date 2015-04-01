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
char a[50][50];
int visited[50][50];
int n,m,s,c=0;
int done=0,sp=0;

void foo1(int x,int y)
{
	
	if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#' || visited[x][y] || done || c>sp){
		return;
	}
	visited[x][y]=1;
	if(a[x][y]=='@'){
		if(c<=sp)
			done=1;
		return;
	}
	if(a[x][y]=='s')
		c++;
	
	foo1(x,y+1);
	foo1(x,y-1);
	foo1(x-1,y);
	foo1(x+1,y);
	if(a[x][y]=='s')
		c--;
	visited[x][y]=0;
}


void foo(int x,int y)
{
	
	if(x<0 || y<0 || x>=n || y>=m || a[x][y]=='#' || visited[x][y] || done || c>s){
		return;
	}
	visited[x][y]=1;
	if(a[x][y]=='x'){
		if(c<=s)
			done=1;
		else{
			visited[x][y]=0;
			foo1(x,y);
		}
		
		return;
	}
	if(a[x][y]=='s')
		c++;
	
	foo(x,y+1);
	foo(x,y-1);
	foo(x-1,y);
	foo(x+1,y);
	if(a[x][y]=='s')
		c--;
	visited[x][y]=0;
}

int main()
{
	clock_t start=clock();
	int x,y;
	cin>>n>>m>>s;
	sp=s;
	s=s/2;int k=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>a[i][j];
			if(a[i][j]=='@'){
				x=i,y=j;
			}
			if(a[i][j]=='x')
				k++;
		}
	}
	foo(x,y);
	if(done)
		cout<<"SUCCESS\n";
	else
		cout<<"IMPOSSIBLE\n";
	if(k>1)
	while(clock()-start <= (1.000-0.015) * CLOCKS_PER_SEC);
	return 0;
}
