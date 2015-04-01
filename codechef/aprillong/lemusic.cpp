#include <iostream>
#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
using namespace std;
 
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		
		int b,l,n;
		vector<pair<unsigned long long int,unsigned long long int> > p;
		pair<unsigned long long,unsigned long long> temp;
		set<unsigned long long> s;
		set<int>::iterator it;
		unsigned long long int a[200000];
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d%d",&b,&l);
			temp.first=l;
			temp.second=b;
			p.push_back(temp);
		}
		sort(p.begin(),p.end());
		
		int count=1;
		int k=0;
		unsigned long long int ans=p[0].first;
		s.insert(p[0].second);
		for(int i=1;i<n;i++){
			if(s.find(p[i].second)==s.end()){
				s.insert(p[i].second);
				count++;
				ans+=p[i].first*count;
				//cout<<"A";
			}
			else{
				a[k]=p[i].first;
				k++;
			}
		}
		for(int i=0;i<k;i++)
			ans+=a[i]*count;
		//cout<<k<<" "<<count<<" ";
		printf("%lld\n",ans);
	}
	return 0;
}
