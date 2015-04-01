#include<iostream>
using namespace std;

int main()
{
	int t,i,n,j,min,sum=0;
	
	int a[100];
	cin>>t;
	
	for(i=0;i<t;i++)
	{
		cin>>n;
		min=50000;
		sum=0;
		for(j=0;j<n;j++)
		{
			cin>>a[j];
			sum=sum+a[j];
			
			if(a[j]<=min)
			min=a[j];
		}
		cout<<(sum-n*min)<<endl;
	}
	return 0;
}
