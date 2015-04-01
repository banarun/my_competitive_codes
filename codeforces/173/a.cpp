#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <map>
#include <cstdio>
#include <stack>
using namespace std;

int main()
{
	int n;
	cin>>n;
	string s;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>s;
		if(s[1]=='+')
		c++;
		if(s[1]=='-')
		c--;
	}
	cout<<c<<endl;	
	return 0;
}
