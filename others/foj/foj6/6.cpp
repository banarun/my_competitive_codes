#include <iostream>
using namespace std;

int main()
{
	int flag=0;
	int t,n,m;
	cin>>t;
	for(int z=0;z<t;z++){
		cin>>n;	
		cin>>m;
		flag=1;
		int p=1;
		for(int i=0;i<n;i++){
			
			if(flag==0){
				if(m%2==0){
					p=p*2;
				}
				else{
					p=p*2+1;
				}
				m=m/2;
				flag=1;
			}
			else if(flag==1){
				flag=0;
				if(m%2==0){
					p=p*2+1;
				}
				else{
					p=p*2;
				}
				m=m/2;
			}
			cout<<p<<endl;
		}
		cout<<p<<endl;
	}
	return 0;
}
