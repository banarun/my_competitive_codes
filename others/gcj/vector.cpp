#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n,t,a,b;
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>n;
		vector<long long int> x;
		vector<long long int> y;
		for(int i=0;i<n;i++){
			cin>>a;
			x.push_back(a);
		}
		for(int i=0;i<n;i++){
			cin>>a;
			y.push_back(a);
		}
		
		sort(x.begin(),x.end());
		sort(y.begin(),y.end());
		
		int p=n-1;
		long long int sum=0;
		for(int i=0;i<n;i++,p--){
			sum+=x[i]*y[p];
		}
		cout<<"Case #"<<j+1<<": ";
		cout<<sum<<endl;
	}
	return 0;
}
