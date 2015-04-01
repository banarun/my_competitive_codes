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
#define N 100002 

int main() 
{ 
	ll int x,y,m;
	
	cin>>x>>y>>m;
	ll int abx=abs(x);
	ll int aby=abs(y);
	
	if(max(x,y)>=m){
		cout<<0<<endl;
		return 0;
	}
	if(x<=0 && y<=0 && m>max(x,y)){
		cout<<-1<<endl;
		return 0;
	}
	
	if(x<0 && y<0 && m<0){
		x=abx;
		y=aby;
		m=abs(m);
	}
	ull ans=0;
	
	
	if(x+y<max(x,y)){
		if(m>0){
			ll t=max(x,y);
			ll t1=min(x,y);
			x=t;
			y=t1;
		}
		else{
			x=-1*x;
			y=-1*y;
			ll t=max(x,y);
			ll t1=min(x,y);
			x=t;
			y=t1;
			m=abs(m);
		}
		ans=abs(y)/abs(x);	
			if(abs(y)%abs(x))
				ans++;
			y=y+ans*abs(x);
	}
	//cout<<x<<" "<<y<<" "<<m<<" "<<ans<<endl;
	while(max(x,y)<m){
		ans++;
		ll t=max(x,y);
		x=x+y;
		y=t;
	}
	cout<<ans<<endl;
	return 0; 
}
