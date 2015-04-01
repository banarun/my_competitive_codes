#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <list> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility>
#include <deque> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iomanip> 
#include <cctype> 
#include <ctime> 
using namespace std; 

#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
typedef pair<int,int> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X) 
#define inp(X) scanf("%d",&X)

#define mod 1000000007 
#define N 100002 

int main() 
{ 
	string s;
	cin>>s;
	int n=s.length();
	
	ll ans=0;
	for(int i=0;i<s.length();i++){
		ans=ans*2+s[i]-'0';
		ans=ans%mod;
	}
	for(int i=1;i<s.length();i++){
		ans=ans*2%mod;
	}
	cout<<ans<<endl;
	return 0; 
}
