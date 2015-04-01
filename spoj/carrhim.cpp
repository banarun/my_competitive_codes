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

void reset()
{
}
int main() 
{ 
	int n;
	string s;
	int first=0,team=0;
	int white=0,black=0,red=0;
	int pos[2];
	while(getline(cin,s)){
		if(s[0]=='#'){
			if((white==9 || black==9) && red>0){
				if(white==9){
					team=first;
				}
				if(black==9){
					team=3-first;
				}
				int points=0;
				
				if(red==team)
					points=5;
				points+=18-white-black;
				printf("Team-%d win and the point is %d.\n",team,points);
			}
			else{
				printf("Incomplete game.\n");	
			}
			white=black=red=first=0;
			continue;
		}
		if(s[0]=='A' || s[0]=='B' || s[0]=='C' || s[0]=='D'){
			if(s[0]=='A' || s[0]=='C'){
				if(first==0)
					first=1;
				if(s[6]=='1')
					red=1;
			}
			if(s[0]=='B' || s[0]=='D'){
				if(first==0)
					first=2;
				if(s[6]=='1')
					red=2;
			}
			
			white+=s[2]-'0';
			black+=s[4]-'0';
		}
	}
	return 0; 
}
