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
int sev[501];
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

	for(int i=2;i<=50;i++){
		for(int j=i*i;j<=250;j+=i){
			if(j%i==0)
				sev[j]=1;
		}
	}
	int k1=2;
	sev[2]=1;
	sev[3]=2;
	sev[4]=2;
	for(int i=5;i<=250;i++){
		if(!sev[i]){
			k1++;
		}
		sev[i]=k1;
	}
	
	//for(int i=1;i<=250;i++)
		//cout<<i<<" "<<sev[i]<<endl;
	
	t1=in();
	while(t1--){
		int r,n;
		r=in();
		n=in();
		char c;
		for(int i=1;i<=r;i++){
			for(int j=1;j<=n;j++){
				l[i][j]=0;
				k[i][j]=0;
				b[i][j]=0;
				t[i][j]=0;
				c=getchar_unlocked();
				a[i][j]=c;
			}
			c=getchar_unlocked();
		}
		//end=clock();
		//st+=esnd-start;
		
		for(int i=1;i<=r;i++){
			for(int j=1;j<=n;j++){
				if(a[i][j]=='^'){
					l[i][j+1]=l[i][j]+1;
				}
				if(a[i][j]=='^'){
					t[i+1][j]=t[i][j]+1;
				}
				if(a[i][n+1-j]=='^'){
					b[i][n-j]=b[i][n+1-j]+1;
				}
				if(a[r-i+1][j]=='^'){
					k[r-i][j]=k[r-i+1][j]+1;
				}
			}
		}
		int ans=0;
		for(int i=2;i<r-1;i++){
			for(int j=2;j<n-1;j++){
				if(a[i][j]!='#'){
					int t5=min(b[i][j], k[i][j]);
					int t6=min(l[i][j],t[i][j]);
					int t7=min(t5,t6);
					if(sev[t7]){
						ans+=sev[t7];
					}
				}
			}
		}
		
		printf("%d\n",ans);
		//et+=clock()-end;
	}
	//cout<<st<<" "<<et<<endl;
	return 0; 
}
