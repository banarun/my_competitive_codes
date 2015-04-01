#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	
	int n,s,p,t,temp;
	cin>>t;
	for(int l=0;l<t;l++){
		cin>>n>>s>>p;
		vector<int> v;
		for(int i=0;i<n;i++){
			cin>>temp;
			v.push_back(temp);
		}
		int count=0;
		for(int i=0;i<n;i++){
			
			if(v[i]==0){
				if(p==0)
					count++;
				continue;
			}
			
			if(v[i]%3==0){
				if(v[i]/3>=p){
					count++;
				}
				else if(v[i]/3+1>=p&&s>0){
					s--;
					count++;
				}
					
			}
			else if(v[i]%3==1){
				if(v[i]/3+1>=p)
					count++;
			}
			else{
				if(v[i]/3+1>=p)
					count++;
				else if(v[i]/3+2>=p&&s>0){
					s--;
					count++;
				}
			}
			
		}
		cout<<"Case #"<<l+1<<": ";
		cout<<count<<endl;
	}
	return 0;
}
