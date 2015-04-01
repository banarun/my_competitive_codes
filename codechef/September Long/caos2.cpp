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
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000 

char a[503][503];
short t[503][503];
short b[503][503];
short l[503][503];
short k[503][503];
char s[505];

ll in()
{
    ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}


int main()
{ 
	int t1;
	clock_t start,end,st,et=0;
	st=0;
	t1=in();
	while(t1--){
		int r,n;
		start=clock();
		r=in();
		n=in();
		char c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=n;j++){
				c=getchar_unlocked();
				a[i][j]=c;
			}
			c=getchar_unlocked();
		}
		//end=clock();
		//st+=esnd-start;
		ll int ans=0;
		for(int i=3;i<r-1;i++){
			for(int j=3;j<n-1;j++){
				if(a[i][j]!='#' && a[i][j-1]=='^' && a[i][j-2]=='^' && a[i][j+1]=='^' && a[i][j+2]=='^' && a[i-1][j]=='^' && a[i-2][j]=='^' && a[i+1][j]=='^' && a[i+2][j]=='^')
					ans++;
			}
		}
		
		printf("%lld\n",ans);
		//et+=clock()-end;
	}
	//cout<<st<<" "<<et<<endl;
	return 0; 
}
