#include <iostream>
#include <string>

using namespace std;
int a[200001];
int main()
{
	int n;
	string s;
	cin>>s;
	
	n=s.length();
	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			a[i+1]=a[i]+1;
		}
		else
			a[i+1]=a[i];
	}
	cin>>n;
	for(int i=0;i<n;i++){
		int a1,b;
		cin>>a1>>b;
		cout<<a[b-1]-a[a1-1]<<endl;
	}
	return 0;
}
