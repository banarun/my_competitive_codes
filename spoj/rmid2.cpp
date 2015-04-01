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
int inp(){int r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		multiset<int> s;
		multiset<int>::iterator it,temp;
		int n;
		while(1){
			n=inp();
			if(n>0){
				s.insert(n);
				
				if(s.size()==1){
					it=s.begin();
				}
				else if(*it > n && s.size()%2==0){
					//dbg(*it);
					it--;
				}
				else if(*it <= n && s.size()%2==1){
					//dbg(*it);
					it++;
				}
			}
			else if(n<0){
				printf("%d\n",*it);
				if(s.size()==1){
					s.erase(it);
				}
				else if(s.size()%2){
					temp=it;
					it--;
					s.erase(temp);
				}
				else{
					temp=it;
					it++;
					//dbg(*it);
					s.erase(temp);
				}
			}
			else{
				break;
			}
		}
	}
	return 0;
}
