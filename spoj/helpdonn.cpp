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
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
vector<int> v;
set<int> s;
set<int>::iterator it;
vector<int>::iterator itr;

int main()
{
	int t;
	t=inp();
	while(t--){
		int n,k;
		n=inp();
		k=inp();
		int a[1001];
		for(int i=0;i<n;i++){
			a[i]=inp();
		}
		int q=0,valu=0;
		v.clear();
		s.clear();
		for(int i=0;i<n;i++){
			valu+=a[i];
			int temp=valu;
			s.insert(temp);
			for(int j=i+1;j<n;j++){
				temp+=a[j]-a[j-i-1];
				s.insert(temp);
			}
		}
		for(it=s.begin();it!=s.end();it++){
			v.pb(*it);
		}
		int ans;
		int l=0,h=v.size()-1;
		if(v.size()==1){
			printf("%d\n",v[0]);
			continue;
		}
		while(l<h){
			int mid=(l+h)/2;
			int f=0,b=0,p=0;
			q=v[mid];
			for(int j=1;j<=k;j++){
				while(p<=q){
					if(b==n){
						f=1;
						break;
					}
					p+=a[b];
					b++;
				}
				b--;
				p=0;
			}
			//dbg(v[mid],l,h,f);
			if(f==1){
				ans=mid;
				h=mid;
			}
			else{
				if(l==mid){
					f==1?ans=l:ans=h;
					break;
				}
				else
					l=mid;
			}
		}
		printf("%d\n",v[ans]);
	}
	return 0;
}
