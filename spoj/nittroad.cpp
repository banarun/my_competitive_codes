#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <cctype>
#include <vector> 
#include <deque> 
#include <vector> 
#include <list> 
#include <map> 
#include <queue> 
#include <stack>  
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
#define N 20001 
vector <int> se[20001];
int h[20001];
int a1[20001],a2[20001],flag[20001];
int qu[20001];
int indx[20001];
vector <ll> ans;
vector <int> grap[20001];
int cnt,par;

void dfs_visit(int i)
{
	for(vector<int>::iterator itr=grap[i].begin();itr!=grap[i].end();itr++){
		if(indx[*itr]==0){
			indx[*itr]=par;
			se[par].pb(*itr);
			dfs_visit(*itr);
		}
	}
}

int main() 
{
	int t;
	scanf("%d",&t);
	while(t--){
		ans.clear();
		for(int i=0;i<=20000;i++){
			h[i]=0;
			indx[i]=0;
			flag[i]=0;
			grap[i].clear();
			se[i].clear();
		}
		int n,q;
		scanf("%d",&n);
		for(int i=1;i<n;i++){
			int a,b;
			scanf("%d%d",&a,&b);
			a1[i]=max(a,b);
			a2[i]=min(a,b);
		}
		scanf("%d",&q);
		for(int i=q;i>0;i--){
			char c[10];
			scanf("%s",c);
			if(c[0]=='Q'){
				qu[i]=0;
			}
			else{
				scanf("%d",&qu[i]);
				flag[qu[i]]=1;
			}
		}
		
		for(int i=1;i<n;i++){
			if(!flag[i]){
				grap[a1[i]].pb(a2[i]);
				grap[a2[i]].pb(a1[i]);
			}
		}
		
		for(int i=1;i<=n;i++){
			if(!indx[i]){
				se[i].pb(i);
				par=i;
				indx[i]=i;
				dfs_visit(i);	
			}
		}
		ll anr=0;
		int tmp=n;
		for(int i=1;i<=n;i++){
			if(se[i].size()){
				
				int p=se[i].size();
				anr+=p*(tmp-p);
				tmp-=p;
			}
		}
		
		for(int i=1;i<=q;i++){
			if(qu[i]==0){
				ans.pb(anr);
			}
			else{
				//dbg(i);
				int t1=indx[a1[qu[i]]];
				int t2=indx[a2[qu[i]]];
				anr-=1LL*se[t1].size()*se[t2].size();
				if(se[t1].size()>se[t2].size()){
					for(vector<int>::iterator it=se[t2].begin();it!=se[t2].end();it++){
						se[t1].pb(*it);
						indx[*it]=t1;
					}
					se[t2].clear();
				}
				else{
					for(vector<int>::iterator it=se[t1].begin();it!=se[t1].end();it++){
						se[t2].pb(*it);
						indx[*it]=t2;
					}
					se[t1].clear();
				}
			}
		}
		for(int i=ans.size()-1;i>=0;i--){
			printf("%lld\n",ans[i]);
		}
		printf("\n");
		//dbg(anr);
	}
	return 0; 
}

