#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <list> 
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
#define N 100001 

int visited[N];
int main() 
{ 
	int n;
	vector<int> v;
	cin>>n;
	v.resize(n);
	int p;
	for(int i=1;i<n;i++){
		scanf("%d",&p);
		v[i]=p;
	}
	int m;
	cin>>m;
	int ans[100001];
	scanf("%d",&p);
	int k=p;
	int j=1;
	visited[0]=100000;
	while(k){
		ans[j]=k;
		visited[k]=j;
		k=v[k];
		j++;
	}
	int ptr=0;
	for(int i=1;i<m;i++){
		scanf("%d",&p);
		k=p;
		while(!visited[k]){
			k=v[k];
		}
		if(k==0){
			cout<<0<<endl;
			return 0;
		}
		for(int r=ptr;r<visited[k];r++){
			visited[ans[r]]=0;
		}
		ptr=visited[k];
	}
	cout<<ans[ptr]<<endl;
	return 0; 
}
