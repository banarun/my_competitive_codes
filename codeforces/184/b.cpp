#include <iostream>
using namespace std;

int main()
{
	int n;
	
	long long int p,q,a[100002];
	cin>>p>>q;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int flag=0;
	for(int i=0;i<n;i++){
		if(q==0){
			cout<<"NO"<<endl;
			return 0;
		}		
		if(i==n-1){
			//cout<<a[i]<<endl;
			if( (p/q)!=a[i] || p%q!=0){
				cout<<"NO"<<endl;
				return 0;
			}
			else
				continue;
		}
		if((p/q)>=a[i]){
			long long int temp=q;
			q=p-a[i]*q;
			p=temp;
		}
		else{
			cout<<"NO"<<endl;
			return 0;
		}

	}
	cout<<"YES"<<endl;
	return 0;
}
