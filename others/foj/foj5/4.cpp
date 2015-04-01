#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t,r,c;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>r>>c;
		int a=0;
		int max1=0;
		int m=0,m1=0,ab=0,count=0;
		int in[100],ind[100];
		string s[100],str[100];
		for(int j=0;j<r;j++)
			cin>>s[j];
		count=0;
		a=0;
		for(int k=0;k<r;k++){
			count=0;
			for(int j=0;j<c;j++){
				if(s[k][j]=='0')
					count++;
			}
			
			if(count==m||count==m-1){
				ind[a++]=k;
			}
			if(count>m){
				m=count;
				a=0;
				ind[a++]=k;
			}
		}
		
		for(int k=0;k<r;k++)
			str[k]=s[k];
		
		int b=a;
		
		for(a=0;a<b;a++){
			
			for(int k=0;k<r;k++)
				{s[k]=str[k];}
				
			for(int k=0;k<c;k++){
				int cd=ind[a];
				if(s[cd][k]=='0')
					s[cd][k]='1';
				else
					s[cd][k]='0';
			}
			
			count=0,m1=0;
			for(int k=0;k<c;k++){
				count=0;
				for(int j=0;j<r;j++){
					if(s[j][k]=='0')
						count++;
				}
				if(count==m1){
					in[ab]=k;
				}
				if(count>m1){
					m1=count;
					ab=0;
					in[ab]=k;
				}
			}
			
			ab=0;
			    
			for(int k=0;k<r;k++){
				if(s[k][in[ab]]=='0')
					s[k][in[ab]]='1';
				else
					s[k][in[ab]]='0';
			}
			count=0;
			
			//cout<<endl;
			//for(int k=0;k<r;k++)
				//cout<<s[k]<<endl;
				
			for(int k=0;k<r;k++)
			for(int j=0;j<c;j++)
			if(s[k][j]=='1')
				count++;
			if(count>max1)
				max1=count;
			//cout<<count<<endl;
		}
		cout<<max1<<endl;
		//cout<<endl;
	}
	
	return 0;
}
