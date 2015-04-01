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
#define N 300002
int a[N];
set<int> s;
//ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
set<int>::iterator it,it1,it2,it3;
int main()
{
	int n,m;
	
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
		s.insert(i+1);
	//dbg("A");
	for(int i=0;i<m;i++){
		int x,y,p;
		scanf("%d%d%d",&x,&y,&p);
		it=lower_bound(s.begin(),s.end(),x);
		it2=upper_bound(s.begin(),s.end(),y);
		while(it!=s.end() && it!=it2){
			//dbg(*it);
			if(*it !=p){
				a[*it]=p;
				 it3=it;
				it++;
				s.erase(it3);
			}
			else
				it++;
		}
		if(s.find(y)!=s.end() && y!=p){
			s.erase(y);
			a[y]=p;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}
