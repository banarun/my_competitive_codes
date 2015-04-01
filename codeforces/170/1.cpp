#include <iostream>
#include <string>
using namespace std;
int a[26];
int main()
{
	int n,m,t,p;
	string s[100];
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i];
		for(int j=0;j<s[i].length();j++){
			a[s[i][j]-'a']++;
		}
	}
	string str="aa";
	int flag=0;
	for(int i=0;i<26;i++){
		if(a[i]==0){
			cout<<char('a'+i)<<endl;
			return 0;
		}
	}
	
	for(int i=1;i<=26;i++){
		flag=0;
		for(int b=0;b<26;b++){
			flag=0;
			for(int j=0;j<n;j++){
				p=s[j].find(str);
				if(p>=0){
					
					flag=1;
					break;
				}
			}
			if(flag==1){
				str[1]=char('a'+b);
			}
			if(flag==0){
				cout<<str<<endl;
				return 0;
			}
		}
		
		str[0]='a'+i;
		str[1]='a';
	}
	return 0;
}
