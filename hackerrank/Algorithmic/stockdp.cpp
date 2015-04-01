#include <iostream>
using namespace std;

int main()
{	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int m[100000];
		long long int a[100000];
		for(int i=0;i<n;i++){
			cin>>a[i];
			m[i]=0;
		}
		
		int cm=0;
		for(int i=n-1;i>=0;i--){
			if(a[i]>cm){
				cm=a[i];
				m[i]=1;
			}
		}
		long long int ans=0,sum=0,count=0;
		for(int i=0;i<n;i++){
			if(m[i]==0){
				sum+=a[i];
				count++;
			}
			if(m[i]==1){
				ans+=(a[i]*count)-sum;
				sum=0;
				count=0;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
