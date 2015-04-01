#include <iostream>
#include <set>
#include <list>
using namespace std;

int index[100003],n;
long long int count=1;
	
void dfs_visit( list<int> *grap,int i)
{
	for(list<int>::iterator itr=grap[i].begin();itr!=grap[i].end();itr++){
		if(index[*itr]==0){
			index[*itr]=i;
			count++;
			dfs_visit(grap,*itr);
		}
	}
}

int main()
{
	int e,t;
	cin>>t;
	for(int itr=0;itr<t;itr++){
		cin>>n>>e;
		for(int i=0;i<=n;i++)
			index[i]=0;
		int a,b;
		list<int> grap[100003];
		for(int i=0;i<e;i++){
			scanf("%d%d",&a,&b);
			grap[a].push_back(b);
			grap[b].push_back(a);
		}
		long long int prd=1;
		int num=0;
		for(int i=1;i<=n;i++){
			if(index[i]==0){
				index[i]=i;
				count=1;
				num++;
				dfs_visit(grap,i);
				prd=(prd*count)%(1000000000+7);
			}
		}
		cout<<num<<" "<<prd<<endl;
	}
	return 0;
}
