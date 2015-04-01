#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n,m,t,p;
	cin>>n;
	vector<int> v;
	v.push_back(0);
	for(int i=0;i<n;i++){
		cin>>p;
		v.push_back(p);
	}
	int a,b;
	cin>>a>>b;
	int s,s1;
	if(a>b){
		p=a;
		a=b;
		b=p;	
	}
	s=0;
	s1=0;
	
	for(int i=a;i<b;i++)
		s=s+v[i];
	for(int i=b;i<=n;i++)
		s1=s1+v[i];
	for(int i=0;i<a;i++)
		s1=s1+v[i];

	if(s<s1)
		cout<<s<<endl;
	else
		cout<<s1<<endl;
	
	return 0;
}
