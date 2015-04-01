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
int k=0;
int n;
string s;
void foo(int p){
	if(p==n-1)
		return;
	int i=p,j=p+1;
	while(i>=0 && j<n && s[i]==s[j]){
		k--;
		i--;
		j++;
		
	}
	k++;
	if(j<n-1)
			foo(j);
	
}
int main() 
{
	
	cin>>s;
	n=s.ln;
	if(n==1 && s[0]=='-'){
		cout<<"No\n";
		return 0;
	}
		
	foo(0);
	if(k==0){
		cout<<"Yes\n";
		return 0;
	}
	if(k>1){
		cout<<"No\n";
		return 0;
	}
	int p=0,q=0;
	for(int i=0;i<n;i++)
		if(s[i]=='-')
			p++;
		else
			q++;
	if(q%2)
		cout<<"No\n";
	else
		cout<<"Yes\n";
	return 0; 
}
