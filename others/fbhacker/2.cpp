#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int main(){
	
	long l;
	int m,n,j,p,k;
	
	vector<int> h,z;
	vector<long> v;
	vector<int>::iterator it;
	cin>>n>>k;
	for(int i=0;i<100000;i++)
		h.push_back(0);
	long a,b,c,r;
	cin>>a>>b>>c>>r;
	v.push_back(a);
	n=a;
	for(int i=1;i<k;i++){
		v.push_back((v[i-1]*b+c)%r);
		cout<<v[i]<<" ";
	}
	
	for(int i=0;i<k;i++){
		if(v[i]<100000)
			h[v[i]]=1;
	}
	for(int i=0;i<100000;i++){
		if(h[i]==0){
			
		}
	}
	for(int i=k;i<n;i++){
		p=
	}
	return 0;

}
