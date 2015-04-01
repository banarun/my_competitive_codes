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
	int a;
	cin>>a;
	if(a==0)
	{
		cout<<"NO\n";
		return 0;
	}
	int c=0,f=0,b;
	while(a>0){
		
		if(a%10!=4 && a%10!=1 ){
			f=1;
			break;
		}
			
		b=a%10;
		if(b==1){
			a=a/10;
			continue;
		}
		c=0;
		while(a%10==4){
			c++;
			a=a/10;
		}
		if(c>2 || (c>0 && a==0)){
			f=1;
			break;
		}
	}
	if(f==0)
		cout<<"YES";
	else
		cout<<"NO";
	return 0; 
}
