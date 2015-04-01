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

int main() 
{ 
	int x,y;
	cin>>x>>y;
	string s;
	cin>>s;
	int xr[200];
	int yr[200];
	int n=s.ln;
	xr[0]=0;
	yr[0]=0;
	int p=1;
	for(int i=0;i<n;i++){
		if(s[i]=='U'){
			yr[p]=yr[p-1]+1;
			xr[p]=xr[p-1];
			p++;
		}
		if(s[i]=='D'){
			yr[p]=yr[p-1]-1;
			xr[p]=xr[p-1];
			p++;
		}
		if(s[i]=='R'){
			yr[p]=yr[p-1];
			xr[p]=xr[p-1]+1;
			p++;
		}
		if(s[i]=='L'){
			yr[p]=yr[p-1];
			xr[p]=xr[p-1]-1;
			p++;
		}
	}
	int fx=abs(xr[p-1]);
	int fy=abs(yr[p-1]);
	//dbg(fx,fy);
	int f=0;
	for(int i=0;i<n;i++){
		int ax=abs(xr[i]-x);
		int ay=abs(yr[i]-y);
		int abx=x-xr[i];
		int aby=y-yr[i];
		
		if(xr[i]==x && yr[i]==y){
			f=1;
			continue;
		}
		if(fx==0 && xr[i]==x){
			if(fy==0 && yr[i]==y)
				{f=1;continue;}
			
			if(fy!=0 && ay%fy==0){
				if(aby>0){
					if(yr[p-1]>0)
						f=1;
				}
				if(aby<0){
					if(yr[p-1]<0)
						f=1;
				}
			}
		}
		if(fy==0 && yr[i]==y){
			if(fx!=0 && ax%fx==0){
				if(abx>0){
					if(xr[p-1]>0)
						f=1;
				}
				if(abx<0){
					if(xr[p-1]<0)
						f=1;
				}
			}
		}
		else if(fx!=0 && fy!=0 && ax%fx==0 && ay%fy==0 && ax/fx==ay/fy){
			if(xr[p-1]>=0 && yr[p-1]>=0){
				if(abx>0 && aby>0){
					f=1;
					//dbg(i,ax,ay);
				}
			}
			else if(xr[p-1]>=0 && yr[p-1]<=0 ){
				if(abx>=0 && aby<=0 ){
					f=1;
					//dbg(2);
				}
			}
			else if(xr[p-1]<=0 && yr[p-1]<=0 ){
				if(abx<=0 && aby<=0){
					f=1;
					//dbg(3);
				}
			}
			else if(xr[p-1]<=0 && yr[p-1]>=0 ){
				if(abx<=0 && aby>=0){
					f=1;
					//dbg(4);
				}
			}			
		}
	}
	if(f==1){
		cout<<"Yes";
	}
	else
		cout<<"No";
	return 0; 
}
