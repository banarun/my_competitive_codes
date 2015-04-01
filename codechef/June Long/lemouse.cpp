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

int ans[101][101];
int main() 
{ 
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		char a[101][101]={0};
		int dp[101][101];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin>>a[i][j];
				ans[i][j]=0;
			}
		}
		
		int f;
		int pnum=1;
		for(int i=0;i<=m;i++){
			ans[0][i]=100000;
		}
		for(int i=0;i<=n;i++){
			ans[i][0]=100000;
		}
		
		if(a[0][0]=='1')
			ans[1][1]=1;
		else
			ans[1][1]=0;
		if(a[0][1]=='1')
			ans[1][1]++;
		if(a[1][0]=='1')
			ans[1][1]++;

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				f=0;
				if(i==0 && j==0){
					continue;
				}
				
				if(a[i+1][j]=='1')
					f++;
				if(a[i][j+1]=='1')
					f++;
				int p1=0,p2=0;
				if(j!=0 && i!=0 && a[i][j-1]=='1'){
					if(dp[i][j+1]==1)
						p1++;
				}
				if(i!=0 && j!=0 && a[i-1][j]=='1'){
					if(dp[i+1][j]==0){
						p2++;
					}
				}
				
				ans[i+1][j+1]=min(ans[i][j+1]+p1,ans[i+1][j]+p2)+f;
				if(ans[i][j+1]+p1==ans[i+1][j]+p2){
					dp[i+1][j+1]=3;
				}
				else
				ans[i][j+1]+p1<ans[i+1][j]+p2?(dp[i+1][j+1]=1):(dp[i+1][j+1]=0);	
			}
		}
		printf("%d\n",ans[n][m]);
	}
	return 0; 
}
