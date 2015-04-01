#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,k,a,b;
	cin>>n>>k;
	vector<int> f,t;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		f.push_back(a);
		t.push_back(b);
	}
	
	int max=f[0]-t[0]+k;
	if(t[0]-k<0)
		max=f[0];
	int p=0;
	for(int i=0;i<n;i++){
		if(t[i]>k){
			p=f[i]-t[i]+k;
		}
		else{
			p=f[i];
		}
		if(p>max)
			max=p;
	}
	cout<<max;
	
	return 0;
}
