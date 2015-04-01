#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	cin>>t;
	unsigned long long int prod,ans,a[11][1001];
	
	for(int i=1;i<=10;i++){
		a[i][2]=i;
	}
	for(int i=1;i<=10;i++){
		prod=i;
		for(int j=3;j<=1000;j++){
			prod=(prod*i)%1000000007;
			a[i][j]=(prod+1000000007-a[i][j-1])%1000000007;
		}
	}
	while(t--){
		int n,k;
		scanf("%d%d",&n,&k);
		printf("%llu\n",a[k][n]);
	}
	return 0;
}
