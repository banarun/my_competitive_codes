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

int n,m,w;
int ans=0;
int arr[40];
int ptr=0;
int a[25];
int pt=-1;
int indx[25];
vector<int> grap[25];
set<int> s[25];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
void dfs(int i)
{
	for(vector<int>::iterator itr=grap[i].begin();itr!=grap[i].end();itr++){
		if(indx[*itr]==0){
			indx[*itr]=i;
			s[pt].insert(*itr);
			dfs(*itr);
		}
	}
}

void foo(int k,int sum)
{
	if(sum>w)
		return;
	if(sum==w){

		int f=0;
		int loc=-1;
		for(int i=0;i<=pt;i++){
			if(s[i].find(arr[0])!=s[i].end()){
				loc=i;
				break;
			}
		}
		
		if(loc>=0){
			for(int i=0;i<ptr;i++){
				if(s[loc].find(arr[i])==s[loc].end())
					f=1;
			}
			if(f==0)
				ans++;
		}
		return;
	}
	
	for(int i=k;i<=n;i++){
		arr[ptr]=i;
		ptr++;
		foo(i+1,sum+a[i]);
		ptr--;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		pt=-1;
		n=inp();
		w=inp();
		m=inp();
		indx[0]=0;
		for(int i=1;i<=n;i++){
			s[i].clear();
			indx[i]=0;
			grap[i].clear();
			a[i]=inp();
		}
		
		for(int i=0;i<m;i++){
			int a1,b1;
			a1=inp();
			b1=inp();
			grap[a1].pb(b1);
			grap[b1].pb(a1);
		}
		for(int i=1;i<=n;i++){
			if(indx[i]==0){
				pt++;
				s[pt].clear();
				s[pt].insert(i);
				indx[i]=1;
				dfs(i);
			}
		}
		ptr=0;
		ans=0;
		foo(1,0);
		printf("%d\n",ans);
	}
	return 0;
}

