#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int i=0;
	int n;
	cin>>n;
	for(i=0;i<n;i++){
		string s;
		cin>>s;	
		int k=0;
		while(k<s.length()-1){
			if(s[k]=='0')
				break;
			k++;
		}
		for(int j=0;j<s.length();j++){
			if(j!=k)
			cout<<s[j];
		}
		cout<<endl;
	}
	return 0;
}
