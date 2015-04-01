#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()	
{
	int n,m,d,p,f=0,r;
	long long int sum,s2;
	cin>>n>>m>>d;
	int a[100000],b[100000];
	r=m*n;
	m=1000000;
	int flag=0;
	for(int i=0;i<r;i++){
		cin>>a[i];
		
		if(f==0){
		f=1;
		p=a[i]%d;
		}
		if(p!=a[i]%d){
			flag=1;
		}
		
		if(a[i]<m)
			m=a[i];
	}
	
	
	if(flag==1){
		cout<<-1;
		return 0;
	}
	
	for(int i=0;i<r;i++)
		b[i]=(a[i]-m)/d;
	
	sort(b,b+r);
	sum=0;
	for(int i=0;i<r/2;i++){
		sum=sum+b[r/2]-b[i];
	}
	for(int i=r/2;i<r;i++)
		sum=sum+b[i]-b[r/2];
	cout<<sum<<endl;
	return 0;
}
