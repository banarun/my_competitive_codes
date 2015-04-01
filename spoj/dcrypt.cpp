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
int main()
{
	int t;
	cin>>t;
	while(t--){
		string str,s;
		int key;
		cin>>key;
		cin>>str;
		int n=str.ln;
		s=str;
		dbg(key);
		if(key<26){
			for(int i=0;i<n;i++){
				if(str[i]=='.')
					s[i]=' ';
				if(str[i]>='a' && str[i]<='z'){
					int k=(str[i]-'a'+key)%26;
					s[i]='a'+k;
				}
				if(str[i]>='A' && str[i]<='Z'){
					int k=(str[i]-'A'+key)%26;
					s[i]='A'+k;
				}
			}
		}
		else{
			for(int i=0;i<n;i++){
				if(str[i]=='.')
					s[i]=' ';
				if(str[i]>='a' && str[i]<='z'){
					int k=(str[i]-'a'+key)%26;
					s[i]='A'+k;
				}
				if(str[i]>='A' && str[i]<='Z'){
					int k=(str[i]-'A'+key)%26;
					s[i]='a'+k;
				}
			}	
		}
		cout<<s<<"\n";
	}
	return 0;
}
