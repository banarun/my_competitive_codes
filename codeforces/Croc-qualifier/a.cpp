#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	int a[1000];
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	
	if(n==2){
		if(a[0]==a[1] && a[0]!=0)
			cout<<1<<endl;
		else
			cout<<0<<endl;
		return 0;
	}
	sort(a,a+n);
	
	int count;
	int p=0;
	for(int i=0;i<n;i++)
		if(a[i]==0)
			p++;
			
	if(p>=n-1){
		cout<<0<<endl;
		return 0;
	}
	
	for(int i=p;i<n-2;i++){
		if(a[i]==a[i+1] && a[i+1]!=a[i+2]){
			count++;
		}
		else if(a[i]==a[i+1] && a[i+1]==a[i+2]){
			cout<<-1<<endl;
			return 0;
		}
	}
	if(a[n-1]==a[n-2] && a[n-2]!=a[n-3])
		count++;
	else if(a[n-1]==a[n-2] && a[n-2]==a[n-3]){
		cout<<-1<<endl;
		return 0;
	}
	cout<<count<<endl;
	return 0;
}
