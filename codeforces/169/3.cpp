#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,q,b;
	int l,r;
	int c[500002];
	cin>>n>>q;
	vector<long long int> a,v;
	long long int sum;
	a.push_back(0);
	v.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>b;
		a.push_back(b);
		v.push_back(0);
	}
	sort(a.begin(),a.end());
	
	for(int j=1;j<=q;j++){
		cin>>l>>r;
		v[l]++;
		v[r+1]--;
	}
	c[0]=0;
	for(int i=1;i<=n;i++)
		c[i]=c[i-1]+v[i];
		
	sort(c+1,c+n+1);
	sum=0;
	cout<<endl;
	for(int i=1;i<=n;i++){
		cout<<c[i]<<" ";
		sum=sum+c[i]*a[i];
	}
	cout<<sum;
	return 0;
}
