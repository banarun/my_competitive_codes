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
int main() 
{ 
	int n;
	vector<int> v;
	string s;
	while(getline(cin,s)>0){
		int n=s.ln;
		for(int j=0;j<n;j++){
			int num=0;
			while(s[j]>='0'){
				num=num*10+s[j]-'0';
				j++;
			}
			if(num>=0){
				v.pb(num);
			}
		}
	}
	int f;
	sort(v.begin(), v.end());
	n=v.size();
	for(int i=0;i<n-1;i++){
		f=-1;
		int j=i;
		while(v[j+1]-v[j]==1){
			j++;
			f=j;
		}
		printf("for (int i = %d; i <= %d; i++) cout << i << \" \";\n",v[i],v[j]);
		if(f==j)
			i=j;
	}
	if(v[n-1]-v[n-2]!=1)
		printf("for (int i = %d; i <= %d; i++) cout << i << \" \";\n",v[n-1],v[n-1]);

	return 0;
}
