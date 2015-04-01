#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	string s;
	cin>>n>>s;
	int j=0,a=0,f=0;
	for(int i=0;i<n;i++){
		if(s[i]=='A')
		a++;
		if(s[i]=='F')
		f++;
		if(s[i]=='I')
		j++;
		
	}
	if(j==0)
		cout<<a;
	else if(j==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
