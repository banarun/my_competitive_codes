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

map < pair<ll,ll>, map< pair<ll,ll>, set<int> > > si;
map < pair<ll,ll>, map< pair<ll,ll>, set<int> > >::iterator it;
map < pair<ll,ll>,int> mp; 
map < pair<ll,ll>,set<int> > slope;
map < pair<ll,ll>,set<int> >::iterator itr;
map < pair<ll,ll>,int > :: iterator it1;
set <int> s;
pair<ll,ll> pnt,pnt2;
pair <int,int> pr[1005];
ll gcd(ll x,ll y)
{
	while(x){
		ll temp=x;
		x=y%x;
		y=temp;
	}
	return y;
}
int main()
{
	int n;
	int x,y;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&x,&y);
		pr[i].first=x;
		pr[i].second=y;
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ll x1=pr[i].first,x2=pr[j].first,y1=pr[i].second, y2=pr[j].second;
			if(pr[j].second!=pr[i].second){
				 int f1=0;
				 if((y2-y1 < 0 && x2-x1>0) || (y2-y1 > 0 && x2-x1<0))
					f1=1;
				 ll p1=abs(y2-y1);
				 ll p2=abs(x2-x1);
				 ll gc=gcd(abs(y2-y1),abs(x2-x1));
				 p1=p1/gc;p2=p2/gc;
				 if(f1)
					pnt=mp(-p1,p2);
				else
					pnt=mp(p1,p2);
				 p1=x1*(y2-y1)-y1*(x2-x1);
				 p2=y2-y1;
				f1=0;
				if((p1>0 && p2<0 )|| (p2>0 && p1<0))
				f1=1;
				
				p1=abs(p1);
				p2=abs(p2);
				gc=gcd(p1,p2);
				p1=p1/gc;p2=p2/gc;
				pnt2=mp(p1,p2);
				if(f1)
				pnt2=mp(-p1,p2);
				(si[pnt2])[pnt].insert(i);
				(si[pnt2])[pnt].insert(j);
			}
		}
	}
	s.insert(0);
	for(it=si.begin();it!=si.end();it++){
		int cnt=0;
		for(itr=(it->second).begin();itr!=(it->second).end();itr++){
			int len=(itr->second).size();
			cnt+=len-1;
		}
		s.insert(cnt);
	}
	ll ans=s.size();
	printf("%lld\n",ans);
	return 0;
}

