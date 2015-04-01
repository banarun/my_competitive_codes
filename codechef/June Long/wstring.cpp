#include <iostream> 
#include <cstdio> 
using namespace std; 
int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int p=0;
		int pos[10000];
		int temp=0;
		int arr[10000];
		pos[0]=0;
		while(1){
			pos[p+1]=s.find('#',temp);
			temp=pos[p+1];
			p++;
			if(pos[p]<0){
				pos[p]=n;
				break;
			}
			temp++;
		}
		pos[p+1]=n-1;
		if(p<3){
			cout<<0<<endl;
			continue;
		}
		int has[10000][26]={0};
		int tot[10000][26]={0};
		for(int i=0;i<p;i++){
			for(int j=0;i>0 && j<26;j++){
				tot[i][j]=tot[i-1][j];
			}
			for(int j=pos[i];j<n && j<pos[i+1];j++){
				if(s[j]>='a' && s[j]<='z'){
					has[i][s[j]-'a']++;
					tot[i][s[j]-'a']++;
				}
			}
		}
		
		int out=0;
		for(int i=0;i<p-2;i++){
			int s1=0,s2=0,s3=0,s4=0;
			for(int j=0;j<26;j++){
				if(tot[i][j]>s1)
					s1=tot[i][j];
					
				if(has[i+1][j]>s2)
					s2=has[i+1][j];
					
				if(has[i+2][j]>s3)
					s3=has[i+2][j];
					
				if(tot[p-1][j]-tot[i+2][j]>s4)
					s4=tot[p-1][j]-tot[i+2][j];
			}
			if(s1==0 || s2==0 || s3==0 || s4==0)
				continue;
			//cout<<"i="<<i<<s1<<" "<<s2<<" "<<s3<<" "<<s4<<endl;
			out=max(out,s1+s2+s3+s4);
		}
		if(out>0)
		cout<<out+3<<endl;
		else
		cout<<0<<endl;
	}
	return 0; 
}
