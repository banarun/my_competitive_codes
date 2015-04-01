#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
	int n,m,t;
	cin>>t;
	for(int p=0;p<t;p++){
		cin>>n>>m;
		vector<string> v,a;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			v.push_back(s);
		}
		for(int i=0;i<m;i++){
			cin>>s;
			a.push_back(s);
		}
		int count=0,flg=0;
		for(int i=0;i<m;i++){
			
			int b=a[i].length()-1;
			
			while(1){
				int k=a[i].rfind("/",b);
				if(k<0)
					break;
					
				s=a[i].substr(0,b+1);
				flg=0;
				for(int j=0;j<n;j++){
					flg=v[j].find(s);
					if(flg==0){
						flg=1;
						break;
					}
				}
				
				if(flg<=0)
					count++;
				else{
					break;
				}
				
				if(k==0)
					break;
				else
					b=k-1;
			}
			v.push_back(a[i]);
			n++;
		}
		cout<<"Case #"<<p+1<<": ";
		cout<<count<<endl;
	}
	return 0;
}
