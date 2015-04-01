#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<unsigned long long int> v;
	unsigned long long int temp,sum=0,s1=0,s2=0;
	cin>>n;
	int p1,p2;
	for(int j=0;j<n;j++){	
		cin>>temp;
		v.push_back(temp);
		sum=sum+temp;
	}
	
	sum=sum/2;
	int i;
	for(i=0;i<n;i++){
		if(s1<=sum){
			s1=s1+v[i];
			p1=i+1;
		}
		if(s2<=sum){
			s2+=v[n-1-i];
			p2=n-i;
		}
	}
	if(s1<s2){
		for(int i=1;i<=p1;i++)
			cout<<i<<endl;
	}
	else{
		for(int i=p2;i<=n;i++)
			cout<<i<<endl;
	}
	return 0;
}


