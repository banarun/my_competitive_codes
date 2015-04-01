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
char a[101][101];
vector <int> awx,awy,abx,aby,anx,any;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,c2,c3;
		awx.clear();
		awy.clear();
		abx.clear();
		aby.clear();
		anx.clear();
		any.clear();
		cin>>n>>m>>c2>>c3;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
				if(a[i][j]=='B'){
					abx.pb(i);
					aby.pb(j);
				}
			}
		}
		
		if(n==1 && m==1){
			printf("0\n");
			continue;
		}
		if(n==2 && m==2){
			if(a[1][1]=='B' && a[2][2]=='B' && a[1][2]=='W' && a[2][1]=='W'){
				printf("1\n1 1 1 1 2\n");
			}
			else if(a[1][1]=='W' && a[2][2]=='W' && a[1][2]=='B' && a[2][1]=='B'){
				printf("1\n1 1 1 1 2\n");
			}
			else
				printf("0\n");
			continue;
		}
		if(n<3){
			cout<<abx.size()<<"\n";
			for(int i=0;i<abx.size();i++)
				printf("3 %d %d\n",abx[i],aby[i]);
			continue;
		}
		if(m<3){
			cout<<abx.size()<<"\n";
			for(int i=0;i<abx.size();i++)
				printf("3 %d %d\n",abx[i],aby[i]);
			continue;
		}
		
		int px=-1,py=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;i%2 && j<=m;j++){
				if( a[i][j]=='W'){
					anx.pb(i);
					any.pb(j);
					a[i][j]='B';
				}
			}
		}
		for(int j=1;j<m;j++){
			if(a[1][j]=='W'){
				anx.pb(1);
				any.pb(j);
			}
		}
		if(anx.size()*c2 < abx.size()*c3){
			cout<<anx.size()<<"\n";
				for(int i=0;i<anx.size();i++)
				printf("2 %d %d\n",anx[i],any[i]);
		}
		else{
			cout<<abx.size()<<"\n";
			for(int i=0;i<abx.size();i++)
				printf("3 %d %d\n",abx[i],aby[i]);			
		}
	}
	return 0;
}
