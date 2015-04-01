#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int n,k;
	int a[10001];
	cin>>n>>k;
	int p=1;
	int q=2;
	int u=n-1;
	int l=n-1;
	int c=1;
	for(int t=0;t<k;t++){
		int p=0;
		//cout<<l<<" "<<u<<endl;
		for(int j=1;j<=n;j++){
			if(j<=c){
				a[j]=n;
			}
			else if(j<=c*2){
				a[j]=n-p;
				p++;
			}
			else 
				a[j]=1;				
		}
		c=c*2;
		for(int i=n;i>0;i--){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}	
	return 0;
}
