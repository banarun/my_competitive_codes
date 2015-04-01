#include <iostream>
#include <set>
#include <vector>
using namespace std;

int index1[100001];
int frontier[100001];
set<int> grap[100001];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,e;
		set<int>::iterator it;
		int a,b;
		scanf("%d",&n);
		for(int i=1;i<=n-1;i++){
			int k;
			index1[i]=0;
			grap[i].clear();
			scanf("%d",&k);
			for(int j=0;j<k;j++){
				scanf("%d",&b);
				grap[i].insert(b);
			}
		}
		index1[n]=0;
		int i=1,k,front=1,end=2;
		frontier[i]=i;
		index1[i]=1;
		do{
			k=frontier[front++];
			for(it=grap[k].begin();it!=grap[k].end();it++){
				if(index1[*it]==0){
					index1[*it]=k;
					frontier[end++]=*it;
				}
			}
		}while(front!=end);
		k=n;
		int ans=0;
		if(index1[n]==0){
			printf("-1\n\n");
			continue;
		}
		do{
			k=index1[k];
			frontier[ans]=k;
			ans++;
		}while(k!=1);
		
		printf("%d\n",ans);
		for(int i=ans-1;i>=0;i--){
			printf("%d ",frontier[i]);
		}
		printf("\n\n");
	}
	return 0;
}
