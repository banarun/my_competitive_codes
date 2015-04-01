#include <iostream>
#include <cstdio>

using namespace std;
int main()
{
	
	int i,j,t;
	int a[60];
	string s;
	scanf("%d",&t);
	getline(cin,s);
	for(j=0;j<t;j++){
		getline(cin,s);
		
		int n=s.length();
		for(i=0;i<56;i++)
			a[i]=0;
			
		for(i=0;i<n;i++){
			if(s[i]>='a' && s[i]<='z')
				a[s[i]-'a']++;
			if(s[i]>='A'&& s[i]<='Z')
				a[26+ s[i]-'A']++;
		}
		
		int count=0;
		for(i=0;i<56;i++){
			if(a[i]%2==0)
				count=count+a[i]/2;
			else
				count=count+(a[i]/2)+1;
		}
		cout<<count<<endl;
		
	}
	return 0;
}
