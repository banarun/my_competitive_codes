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

pair<int, string> pr[N];

bool foo(pair<short, string > pr1,pair<short, string > pr2)
{
	if( pr1.second < pr2.second)
		return true;
	return false;
}

int main() 
{
	int t,p=0;
	scanf("%d",&t);
	for(p=0;p<t;p++){
		int n,e;
		
		scanf("%d%d",&n,&e);
		for(int i=0;i<n;i++){
			char ch[102];
			scanf("%s",ch);
			scanf("%hd",&(pr[i].first));
			pr[i].second=ch;
		}
		sort(pr,pr+n);
		int ans=0,i;
		for(i=0;i<n;i++){
			if(e-pr[i].first>=0){
				e=e-pr[i].first+i+1;
			}
			else{
				break;
			}
		}
		ans=i;
		sort(pr,pr+ans,foo);
		printf("Scenario #%d: %d\n",p+1,ans);
		for(int i=0;i<ans;i++){
			char ch[102];
			strcpy(ch, pr[i].second.c_str());
			printf("%s ",ch);
		}
		putchar_unlocked('\n');
	}
	return 0; 
}
