#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int main(){

	int t,n,sum=0,a;
	cin>>t;
	for(int j=0;j<t;j++){
		cin>>sum>>n;
		vector<pair<int,int> > v,v1;
		for(int i=0;i<n;i++){
			cin>>a;
			v.push_back(make_pair(a,i+1));
		}
		sort(v.begin(),v.end());
		int p=0;
		int q=n-1;
		while(1){
			if(sum==v[p].first+v[q].first){
				cout<<"Case #"<<j+1<<": ";
				if(v[p].second<v[q].second)
					cout<<v[p].second<<" "<<v[q].second<<endl;
				else
					cout<<v[q].second<<" "<<v[p].second<<endl;
				break;
			}
				
			else if(sum<v[p].first+v[q].first){
				q--;
			}
			else{
				p++;
			}
		}
		
	}
	
	return 0;
}
