#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility> 
using namespace std; 
#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000 
int a[1001];
int ans[1001];
int indx[1001],n;
int cntr=1,prd=1;
vector<int> grap[1001];
vector<int>::iterator it;
int instack[1001];
set<int> s1;
multiset<int> s2;	
void dfs_visit(int i)
{
	s1.insert(i);
	
	s2.insert(a[i]);
	
	for(vector<int>::iterator itr=grap[i].begin();itr!=grap[i].end();itr++){
		if(indx[*itr]==0){
			indx[*itr]=i;
			cntr++;
			dfs_visit(*itr);
		}
	}
	
	multiset<int>::iterator it2=s2.begin();
	for(set<int>::iterator it1=s1.begin();it1!=s1.end();it1++){
		ans[*it1]=*it2;
		it2++;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--){
		int e;
		cin>>n>>e;
		for(int i=1;i<=n;i++){
			indx[i]=0;
			scanf("%d",&a[i]);
		}
		for(int j=0;j<e;j++){
			int p,q;
			scanf("%d%d",&p,&q);
			//p--;
			//q--;
			grap[p].push_back(q);
			grap[q].push_back(p);
		}
		
		int num=0;
		for(int i=1;i<=n;i++){
			if(indx[i]==0){
				indx[i]=i;
				cntr=1;
				num++;
				dfs_visit(i);
				s1.clear();
				s2.clear();
				
			}
		}
		for(int i=1;i<=n;i++){
			grap[i].clear();
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
