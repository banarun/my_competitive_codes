#include <iostream>
#include <string>
using namespace std;

int main(){
	
	int n;
	cin>>n;
	string p;
	getline(cin,p);
	for(int i=0;i<n;i++){
		string s;
		getline(cin,s);
		string a[1000];
		
		int j=0,b=0;
		while(1){
			
			int k=s.find(" ",j);
			
			if(k<0){
				a[b++]=s.substr(j,s.length()-j);
				break;
			}
			else{
				a[b++]=s.substr(j,k-j);
				j=k+1;
			}
		}
		
		cout<<"Case #"<<i+1<<": ";
		for(int t=b-1;t>=0;t--)
			cout<<a[t]<<" ";
		cout<<endl;
		
	}
	
	return 0;
}
