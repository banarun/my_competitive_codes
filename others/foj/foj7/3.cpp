#include <iostream>
using namespace std;

int main(){
	
	int t;
	cin>>t;
	while(t--){
	
	int a[301];
	for(int i=0;i<301;i++)
		a[i]=0;
	int dp[301][301];
	for(int i=0;i<301;i++)
	for(int j=0;j<301;j++)
		dp[i][j]=0;
	
	int n;	
	cin >> n;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n == 1){
		if(a[1] != 0)
			cout << "Nash" << endl;
		else
			cout << "Me" << endl;
	}
	else if(n == 3){
		int result = a[1] ^ a[2] ^ a[3];
		if(result)
			cout << "Nash" << endl;
		else
			cout << "Me" << endl;
	}
	else{
		for(int i = 0;i <= 300;i++)
			for(int j = 0;j <= 300;j++)
				for(int k = 1;k <= 300;k++){
					if(i >= k && dp[i - k][j] == 0)
						dp[i][j] = 1;
					if(j >= k && dp[i][j - k] == 0)
						dp[i][j] = 1;
					if(i >= k && j >= k && dp[i - k][j - k] == 0)
						dp[i][j] = 1;
				}
		if(dp[a[1]][a[2]])
			cout << "Nash" << endl;
		else
			cout << "Me" << endl; 
	}
	}
	return 0;
}
