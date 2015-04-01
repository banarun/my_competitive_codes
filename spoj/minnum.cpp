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
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define inp(X) scanf("%d",&X)
#define mod 1000000007 
#define N 100002
int main()
{
	string s;
	while(1)
	{
		cin>>s;
		
		if(s[0]=='-')
			break;
		int n=s.ln;
		if(n==1 && s[0]=='0'){
			printf("0\n");
			continue;
		}
		
		int num=0;
		string ans="";
		int f=0;
		for(int i=0;i<n;i++){
			num=num*10+s[i]-'0';
			if(num/9==0 && f==0){}
			else{
				ans.pb(num/9+'0');
				f=1;
			}
			num=num%9;
		}
		int i=ans.ln -1;
		if(num>0){
			while(i>=0  && ans[i]=='9'){
				ans[i]='0';
				i--;
			}
			if(i<0){
				ans.pb('0');
				ans[0]='1';
			}
			
			else{
				ans[i]++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
