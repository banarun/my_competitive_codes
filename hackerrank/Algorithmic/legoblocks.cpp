#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


long long int s[1001][1001];

#define mod 1000000007
#define ull long long
ull int power(ull int x, ull int y)
{
    ull int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return ((x*((temp*temp)%mod))%mod);
}


int main() {
	int t;
	long long int dp[1001],a[1001][1001];
	int n=1001,m=1000;
	s[1][1]=1;
	s[1][2]=1;
	s[1][3]=1;
	s[1][4]=1;
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	
	for(int i=4;i<1001;i++)
		dp[i]=(dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4])%mod;
	for(int i=2;i<1001;i++){
		s[i][1]=1;
	}
	for(int i=1;i<n;i++){
		long long prod=dp[i];
		for(int j=1;j<n;j++){
			a[j][i]=prod%mod;
			prod=(prod*dp[i])%mod;
		}
	}
	
    cin>>t;
	while(t--){
		int h;
		long long int sum=0;
		cin>>h>>m;
		for(int j=2;j<=m;j++){
			sum=0;
			for(int l=1;l<j;l++){
				sum=(sum+(s[h][l]*a[h][j-l])%mod)%mod;
			}
			s[h][j]=(mod+a[h][j]-sum)%mod;
		}
		cout<<s[h][m]<<endl;
	}
    return 0;
}
