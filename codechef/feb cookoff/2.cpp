#include <iostream>
using namespace std;

int main()
{
	int i=0,j=0;
	int n,q;
	int a[100],b[100];
	cin>>n;
	string s;
	getline(cin,s);
	for(i=0;i<n;i++){
		getline(cin,s);
		for(j=0;j<100;j++)
			a[j]=0;
		for(j=0;j<26;j++)
			b[j]=0;
		
		for(j=0;j<s.length();j++){
			if(s[j]>='a' && s[j]<='z')
				a[s[j]-'a']++;
			if(s[j]>='A' && s[j]<='Z')
				a[s[j]-'A']++;
		}
		
		int flag=0;
		for(j=0;j<26;j++){
			if(a[j]==0){
				flag=1;
				cout<<char('a'+j)<<endl;
				break;
			}
		}
		
			if(flag==0){
				cout<<"~\n";
			}
	}
	
	return 0;
}
