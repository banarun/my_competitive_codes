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
int pyr[4];
int flg[4];
int main()
{ 
	string s;
	getline(cin,s);
	int p=0;
	int ptr=0;
	int out=0;
	flg[2]=1;
	for(int i=0;i<s.length();i+=2){
		p=0;
		if(s[i]=='O'){
			flg[ptr]=1;
			if(flg[ptr+1]==1){
				ptr++;
				flg[ptr+1]=0;
			}
			if(flg[ptr+2]==1){
				ptr+=2;
				flg[ptr+2]=0;
			}
			out++;
		}
		if(out==2)
			break;
		if(s[i]>'0' && s[i]<='9'){
			p=s[i]-'0';
		}
		if(p %2 ==1){
			pyr[ptr]+=p;
			if(ptr==1 && flg[0]==0){
				ptr=0;
			}
			else if(ptr==1 && flg[0]==1){
				ptr=2;
			}
			else if(ptr==2 && flg[0]==0){
				ptr=0;
			}
			else if(ptr==2 && flg[0]==1){
				ptr=1;
			}			
			else if(ptr==0 && flg[1]==0){
				ptr=1;
			}
			else if(ptr==0 && flg[1]==1){
				ptr=2;
			}
		}
		else
			pyr[ptr]+=p;
	}
	for(int i=0;i<3;i++)
		cout<<pyr[i]<<"\n";
	return 0; 
}
