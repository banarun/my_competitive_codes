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

int G[13][13];
int x[13];
int n,m,f,b;

void getNodeColor(int k)
{
	do{
		x[k]=(x[k]+1)%(m+1);
		if(x[k]==0)
			return;
		int j;
		for(j=1;j<=n;j++){
			if(G[k][j]!=0 && x[k]==x[j])
				break;
		}
		if(j==n+1)
			return;
	}while(true);
}
int f1=0;
void mcoloring(int k)
{
	do{
		if(f1==1)
			return;
		getNodeColor(k);
		if(x[k]==0)
			return;
		if(k==n)
		{
			f1=1;
			printf("The towers in case %d can be covered in %d frequencies.\n",b,m);
			return;
		}
		else
			mcoloring(k+1);
	}while(true);
}


int main() 
{
	
	while(1){
		scanf("%d",&n);
		b++;
		if(n==0)
			break;
		pair < double, double> pnt[15];
		for(int i=1;i<=n;i++){
			double x1,x2;
			scanf("%lf%lf",&x1,&x2);
			pnt[i].first=x1;
			pnt[i].second=x2;
		}
		int f=0;
		for(int i=0;i<=n;i++)
		for(int j=1;j<=n;j++)
			G[i][j]=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double x1,x2,y1,y2;
				x1=pnt[i].first-pnt[j].first;
				y1=pnt[i].second-pnt[j].second;
				G[i][j]=0;
				if(sqrt(x1*x1+y1*y1)<=20.0){
					G[i][j]=1;
					G[j][i]=1;
					f=1;
				}
			}
		}
		if(f==0){
			printf("The towers in case %d can be covered in 1 frequencies.\n",b);
			continue;
		}
			
		for(m=2;m<=n;m++){
			for(int i=1;i<=n;i++)
				x[i]=0;
			f1=0;
			mcoloring(1);
			if(f1==1)
				break;
		}
	}
	return 0; 
}
