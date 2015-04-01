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

int a[6][3],b[6][3]	;
int ans=0;
int n=6;

void foo(int k){
	if(k==6){
		int f=0,val=0;
		for(int i=0;i<6;i++){
			if(a[i][1]!=a[(i+1)%6][0] || a[(i+6-1)%6][1]!=a[i][0]){
				f=1;
				break;
			}
			val+=a[i][2];
		}
		if(f==0){
			ans=max(val,ans);
		}
		return;
	}
		
	foo(k+1);
	int t=a[k][0];
	a[k][0]=a[k][1];
	a[k][1]=a[k][2];
	a[k][2]=t;
	
	foo(k+1);
	t=a[k][0];
	a[k][0]=a[k][1];
	a[k][1]=a[k][2];
	a[k][2]=t;
	
	foo(k+1);
}

void permute(string s, int i) 
{
   int j; 
   if (i == n){
		for(int i=0;i<n;i++){
			a[i][0]=b[s[i]-'0'][0];
			a[i][1]=b[s[i]-'0'][1];
			a[i][2]=b[s[i]-'0'][2];
			//cout<<a[i][0]<<" "<<a[i][1]<<" "<<a[i][2]<<" "<<endl;
		}
		//cout<<s<<endl;
		foo(0);
	}
   else
   {
        for (j = i; j < n; j++)
       {
          swap(s[i],(s[j]));
          permute(s, i+1);
          swap(s[i], s[j]); //backtrack
       }
   }
} 

int main() 
{ 
	
	while(1){
	ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
			b[i][j]=a[i][j];
			//cout<<b[i][j];
		}
	}
	char ch;
	
	string s="012345";
	permute(s,0);
	if(ans)
		printf("%d\n",ans);
	else
		printf("none\n");
	cin>>ch;
	if(ch=='$')
		break;
	}
	return 0; 
}
