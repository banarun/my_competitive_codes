#include <vector>
#include <cstdio>
#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int t=0;t<n;t++){
		string s;
		cin>>s;
		int count=0,f=0,i=0;
		if(s[0]=='0')
			f--;
		while(i<s.length()){
			while(s[i]=='0'){
				count++;
				i++;
			}
			if(count>0)
				f++;
			count=0;
			while(s[i]=='1'){
				count++;
				i++;
			}
			
			if(count>0)
			f++;
			count=0;
		}
		cout<<f<<endl;
	}
	return 0;
}
