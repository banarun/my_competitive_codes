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
#define mod 1000000007 
#define N 10002
int spos[N];
int lpos[N];
int pos[N];
int stable[N];
set <int> snl; 
vector <int> grap[10002];
int val;
int indx[N];
int frontier[N];

ll inp()
{
    ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

void foo(int k)
{
	if(pos[k]==0){
		stable[k]=1;
		val=k;
		return;
	}
	if(!stable[k])
		foo(pos[k]);
	else{
		val=pos[k];
	}
	pos[k]=val;
	stable[k]=1;
}
int main() 
{
	int n,m,s,l;
	while(scanf("%d",&n)>0){
		m=inp();
		s=inp();
		l=inp();
		for(int i=0;i<=n*m;i++){
			pos[i]=stable[i]=frontier[i]=0;
			indx[i]=-1;
			grap[i].clear();
		}
		for(int i=0;i<s+l;i++){
			int a,b;
			a=inp();
			pos[a]=inp();
			snl.insert(a);
		}
		for(set<int>::iterator it =snl.begin(); it!=snl.end();it++){
			int p=*it;
			if(!stable[p])
				foo(p);
		}
		
		for(int i=0;i<=n*m;i++){
			if(pos[i]==0){
				for(int j=i+1;j<=i+6 && j<=n*m;j++){
					if(pos[j]==0)
						grap[i].pb(j);
					else
						grap[i].pb(pos[j]);
				}
			}
		}
		int i=1,k,front=1,end=2;
		frontier[i]=0;
		indx[0]=0;
		do{
			k=frontier[front++];
			for(vector<int>::iterator it=grap[k].begin();it!=grap[k].end();it++){
				if(indx[*it]==-1){
					indx[*it]=k;
					frontier[end++]=*it;
				}
			}
		}while(front!=end);
		if(indx[n*m]==-1){
			printf("-1\n");
			continue;
		}
		k=n*m;
		int count=0;
		do{
			count++;
			k=indx[k];
		}while(k!=0);
		printf("%d\n",count);		
	}
	return 0; 
}
