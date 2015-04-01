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
int flg[1001];
void rmx()
{
	
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,x,y;
		scanf("%d",&n);
		map<int , set<int> > mx,my;
		map<int , set<int> >::iterator itmp,ptr;
		set<int>::iterator itst;
		for(int i=0;i<n;i++){
			scanf("%d%d",&x,&y);
			mx[x].insert(y);
			my[y].insert(x);
		}
		int mc=0,idx,msz=0;
		x=0;
		int ans=0;
		while(1){
			int f=0,mc=0,msz=0,mik=10000;
			for(itmp=mx.begin();itmp!=mx.end();itmp++){
				if(((*itmp).second).size() && mik>((*itmp).second).size())
					mik=((*itmp).second).size();
			}
			for(itmp=my.begin();itmp!=my.end();itmp++){
				if( ((*itmp).second).size() && mik>((*itmp).second).size())
					mik=((*itmp).second).size();
			}
			//dbg(mik);
			for(itmp=mx.begin();itmp!=mx.end();itmp++){
				int c=0;
				for(itst=((*itmp).second).begin();itst!=((*itmp).second).end();itst++){
					f=1;
					if(my[*itst].size()==mik){
						c++;
					}
				}
				
				if(c>mc){
					mc=c;
					ptr=itmp;
					x=1;
					msz=((*itmp).second).size();
				}
				else if(c==mc && ((*itmp).second).size()>msz){
					ptr=itmp;
					x=1;
					msz=((*itmp).second).size();
				}
			}
			
			for(itmp=my.begin();itmp!=my.end();itmp++){
				int c=0;
				for(itst=((*itmp).second).begin();itst!=((*itmp).second).end();itst++){
					if(mx[*itst].size()==mik){
						c++;
					}
				}
				if(c>mc){
					mc=c;
					ptr=itmp;
					x=2;
					msz=((*itmp).second).size();
				}
				else if(c==mc && ((*itmp).second).size()>msz){
					ptr=itmp;
					x=2;
					msz=((*itmp).second).size();
				}
			}
 
			if(x==1){
				for(itst=((*ptr).second).begin();itst!=((*ptr).second).end();itst++){
					my[*itst].erase((*ptr).first);
				}
				mx[(*ptr).first].clear();
			}
 
			if(x==2){
				for(itst=((*ptr).second).begin();itst!=((*ptr).second).end();itst++){
					mx[*itst].erase((*ptr).first);
				}
				my[(*ptr).first].clear();
			}
			
			if(f==0)
				break;
			ans++;
		}	
		printf("%d\n",ans);
	}
	return 0;
}
