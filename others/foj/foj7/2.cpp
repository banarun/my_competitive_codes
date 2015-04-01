#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		int a[500][500];
		cin>>n>>m;
		long long int dp[500][500];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>a[i][j];
			}
		}
		
		for(int i=0;i<=n;i++){
			for(int j=0;j<=m;j++){
				dp[i][j]=0;
			}
		}
			
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				dp[i][j]=a[i][j]+max(dp[i-1][j],dp[i][j-1]);
			}
		}
		cout<<dp[n][m]<<endl;
	}
	return 0;
}
