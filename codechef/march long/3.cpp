#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
	int n,a,b,m,t;
	scanf("%d",&t);
	for(int j=0;j<t;j++){
		scanf("%d",&n);
		scanf("%d",&m);
		int v[100004]={0};
		long long int setval[100004]={0};
		int cnt=1;
		
		set<int> p[100004];
		set<int>::iterator it,it2;
		
		for(int i=0;i<m;i++){
			scanf("%d",&a);
			scanf("%d",&b);
			if(a>b){
				int tem=a;
				a=b;
				b=tem;
			}
			
			if(v[a]==0&&v[b]==0){
				p[cnt].insert(a);
				p[cnt].insert(b);
				v[a]=cnt;
				v[b]=cnt;
				cnt++;
			}
			else if(v[a]>0&&v[b]==0){
				v[b]=v[a];
				p[v[a]].insert(b);
			}
			else if(v[a]==0&&v[b]>0){
				
				v[a]=v[b];
				p[v[b]].insert(a);
			}
			else if(v[a]!=v[b]&&a!=b){
				int te;
				if(p[b].size()<p[a].size()){	
					te=v[b];
					//cout<<"vs"<<v[a]<<" "<<v[b]<<endl;
					for(it=p[te].begin();it!=p[te].end();it++){
						//cout<<
						p[v[a]].insert(*it);
						v[*it]=v[a];
					}
				}
				else{
					te=v[a];
					//cout<<"vs"<<v[a]<<" "<<v[b]<<endl;
					for(it=p[te].begin();it!=p[te].end();it++){
						//cout<<
						p[v[b]].insert(*it);
						v[*it]=v[b];
					}
				}
			}
		}

		for(int i=1;i<=n;i++){
			setval[v[i]]++;
		}
		int count=0;
		long long int prd=1;
		for(int i=1;i<=n;i++){
			//cout<<"V["<<i<<"]="<<v[i]<<endl;
			if(setval[i]>0){
				count++;
				
				prd=prd%1000000007;
				prd=prd*setval[i];
				//cout<<"prd="<<prd<<endl;
				
			}
			if(v[i]==0){
				count++;
			}
		}
		printf("%d %lld\n",count,prd);
	
	}
	return 0;
}
