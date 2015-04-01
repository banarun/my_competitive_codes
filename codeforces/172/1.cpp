#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	string s;
	cin>>s;
	if(s[0]>='a' && s[0]<='z')
	s[0]=s[0]-'a'+'A';
	cout<<s<<endl;
	return 0;
}
