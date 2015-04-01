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
int lisl[1000];
int lisr[1000];
int lis1[1000];
int lis2[1000];
int arr[1000];
int n;
int lis()
{
   int  i, j;
	for ( i = 0; i < n; i++ ){
		lisl[i]=1; 
		lis1[i]=1;
	}
	for ( i = 1; i < n; i++ ){
		for ( j = 0; j < i; j++ ){
			if ( arr[i] < arr[j] && lisl[i] < lisl[j] + 1){
				lisl[i] = lisl[j] + 1;    
			}
		}
		lis1[i]=max(lisl[i],lis1[i-1]);
	}

	for ( i = 0; i < n; i++ ){
		lisr[i]=1; 
		lis2[i]=1;
	}
	for ( i = n-2; i >=0 ; i-- ){
		for ( j = n-1; j > i; j-- ){
			if ( arr[i] > arr[j] && lisr[i] < lisr[j] + 1){
				lisr[i] = lisr[j] + 1;    
			}
		}
		lis2[i]=max(lisr[i],lis2[i+1]);
	}    
	return lis1[n-1];
}

int lds( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );
 
  
   for ( i = 0; i < n; i++ )
      lis[i] = 1;
    
  
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if (arr[i] < arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
    
  
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];
 
   free( lis );
 
   return max;
}
int main() 
{
	int t;
	scanf("%d",&t);
	while(t--){
		int m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		int ans1=lis();
		int ptr=0;
		int b[1000];
		for(int i=0;i<m;i++){
			if(arr[m]<arr[i]){
				b[ptr]=arr[i];
				ptr++;
			}
		}
		int ans2=lds(b,ptr);
		for(int i=m+1;i<n;i++){
			b[i-m-1]=arr[i];
		}
		int ans3=lds(b,n-m-1);
		//dbg(ans1,ans2,ans3);
		int ans=max(ans1,ans2+ans3+1);
		printf("%d\n",ans);
	}
	return 0; 
}
