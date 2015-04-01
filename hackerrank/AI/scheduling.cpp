#include <iostream>
using namespace std;

int main()
{
	
	int n;
	long long int a,b,count=0;
	long long int d,m,dp=0,mp=0,dmax=0;
	cin>>n;
	int f=0;
	long long int z=0,total=0,curr=0,ans=0,prev=0,pans=0;
	for(int i=0;i<n;i++){
		cin>>d>>m;
		if(d>dmax)
			dmax=d;
		total+=m;
		count=total-dmax;
		
		if(count>=0)
		curr=max(count+m-d,ans);
		else{
			count=m-d;
			total=0;
			curr=max(m-d,ans);
		}
		z=max(m-d,m+ans);
		ans=min(curr,z);
		cout<<ans<<endl;
		prev+=m;
		
	}
	return 0;
}
