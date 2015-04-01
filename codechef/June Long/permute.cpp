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
using namespace std; 

#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 2000002 

inline ll inp( )
{
	ll n=0;
	int ch=getchar_unlocked();
	while( ch >47 )
	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}

ull int factorial[N];

ull int power(ull int x, ull int y)
{
    ull int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return ((x*((temp*temp)%mod))%mod);
}

int main() 
{ 
	int t;
	factorial[0]=1;
	for(int i=1;i<N;i++)
		factorial[i]=(factorial[i-1]*i)%mod;
	
	t=inp();
	while(t--){
		ll n,m;
		n=inp();
		m=inp();
		
		ll ans=(factorial[m-n+1]*(power(m-n+1,(n*2-m-1)/2)*power(m-n,(n*2-m)/2)%mod))%mod;
		//cout<<factorial[m-n+1]<<"*("<<m-n+1<<"**"<<(n*2-m-1)/2<<")*("<<m-n<<"**"<<(n*2-m)/2<<")\n";
		printf("%lld\n",ans);
	}
	
	return 0; 
}
