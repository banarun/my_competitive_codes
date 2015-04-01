#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int n,p;
	unsigned long long int k,i;
	set<unsigned long long int> v;
	set<unsigned long long int>::iterator it;
	cin>>n>>k;
	p=k;
	for(i=0;i<n;i++){
		cin>>p;
		v.insert(p);
	}
	if(k==1){
		cout<<n<<endl;
		return 0;
	}
	
	for(it=v.begin();it!=v.end();it++){
		if(v.find((*it)*k)!=v.end())
			v.erase((*it)*k);
	}
	
	cout<<v.size()<<endl;
	return 0;
}
