#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int tot[100000];

int main() {
    int n;
    int a[100000];
    cin>>n;
    
    for(int i=0;i<n;i++){
		cin>>a[i];
    }
    if(a[0]<=a[1]){
		tot[0]=1;
	}
	if(a[n-1]<=a[n-2]){
		tot[n-1]=1;
	}
	
    for(int i=1;i<n-1;i++){
		if(a[i-1]>=a[i] && a[i]<=a[i+1]){
			tot[i]=1;
		}
	}
	
	for(int i=1;i<n-1;i++){
		if(tot[i]==0 && a[i-1]<a[i] && a[i]<=a[i+1] && tot[i-1]>0){
			tot[i]=tot[i-1]+1;
		}
	}
	
	for(int i=n-2;i>0;i--){
		if(tot[i]==0 && a[i+1]<a[i] && a[i]<=a[i-1] && tot[i+1]>0){
			tot[i]=tot[i+1]+1;
		}
	}
	for(int i=1;i<n-1;i++){
		if(tot[i]==0 && a[i-1]<a[i] && a[i]>a[i+1]){
			tot[i]=max(tot[i-1],tot[i+1])+1;
		}
	}
	if(tot[0]==0 ){
		tot[0]=tot[1]+1;
	}
	if(tot[n-1]==0){
		tot[n-1]=tot[n-2]+1;
	}
	long long int sum=0;
	for(int i=0;i<n;i++){
	//cout<<tot[i]<<" ";
	sum+=tot[i];
	}
	 cout<<sum<<endl;
    return 0;
}
