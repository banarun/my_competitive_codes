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
#define inp(X) scanf("%d",&X)
#define sl(n) 	scanf("%I64",&n)
#define mod 1000000007 
#define N 100002
char c[N];
int main() 
{ 
	int n;
	scanf("%d",&n);
	multiset<int> se;
	multiset<int>::iterator it;
	scanf("%s",c);
	int len=strlen(c);
	int cnt=0;
	if(n==2){
		int l=0,h=0;
		for(int i=0;i<len;i++){
			if(c[i]=='1'){
				if(l<h)
					l++;
				else
					h++;
			}
			else{
				if(l<h)
					h++;
				else
					l++;
			}
		}
		printf("%d %d",min(l,h),max(l,h));
		return 0;
	}
	for(int i=0;i<len;i++){
		if(cnt<n-1){
			se.insert(1);
			cnt++;
			continue;
		}
		if(cnt<n){
			if(c[i]=='1'){
				se.insert(1);
				cnt++;
			}
			else{
				it=se.begin();
				int temp=*it;
				se.erase(it);
				se.insert(temp+1);
			}
		}
		else{
			it=se.begin();
			if(c[i]=='2'){
				it++;
			}
			int temp=*it;
			se.erase(it);
			se.insert(temp+1);
		}
	}
	it=se.begin();
	if(cnt>=n){
	printf("%d ",(*it));
	it++;
	printf("%d",*it);
	}
	else if(cnt<n-1){
		printf("0 0");
	}
	else{
		printf("0 %d",*it);
	}
	return 0; 
}
