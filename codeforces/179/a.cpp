#include <iostream>
using namespace std;

int b[1001];
int main()
{
	int n;
	cin>>n;
	int a[1001];
	cin>>a[0];
	int p=a[0];
	int flag=0;
	if(n==1){
		cout<<"YES";
		return 0;
	}
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	if(n%2){
		for(int i=0;i<=1000;i++){
			if(b[i]>n/2+1){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
	else{
		for(int i=0;i<=1000;i++){
			if(b[i]>n/2){
				cout<<"NO";
				return 0;
			}
		}
		cout<<"YES";
	}
	return 0;
}
