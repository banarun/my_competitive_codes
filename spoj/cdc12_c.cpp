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
int main()
{
	int t;
	cin>>t;
	for(int t1=0;t1<t;t1++){
		long double x[3],y[3];
		for(int i=0;i<3;i++)
			cin>>x[i]>>y[i];
		long double l[3];
		for(int i=0;i<3;i++){
			l[i]=(x[(i+1)%3]-x[(i+2)%3])*(x[(i+1)%3]-x[(i+2)%3]) + (y[(i+1)%3]-y[(i+2)%3])*(y[(i+1)%3]-y[(i+2)%3]);
			//dbg(l[i]);
		}
		int r=0,o=0,s=0;
		for(int i=0;i<3;i++){
			if(abs(l[i]+l[(i+1)%3]-l[(i+2)%3])<0.01)
				r=1;
			else if(l[i]+l[(i+1)%3]<l[(i+2)%3])
				o=1;
			if(abs(l[i]-l[(i+1)%3])<0.01)
				s++;
		}
		string st="";
		if(s==0)
		st="Scalene ";
		else if(s==1)
		st="Isosceles ";
		else
		st="Equilateral Equiangular";
		if(r==1)
		st+="Right Triangle";
		else if(o==1)
		st+="Obtuse";
		else if(s<3)
		st+="Acute";
		printf("Scenario #%d: ",t1+1);
		cout<<st<<"\n";
	}
	return 0;
}
