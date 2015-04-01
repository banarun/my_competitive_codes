#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
using namespace std;

int a[1001];
int arr[1001][1001];
int an[1001];

int main()
{
	int n,s,k,t,c;
	cin>>n>>s;
	for(int i=0;i<s;i++){
		scanf("%d",&c);;
		for(int j=0;j<c;j++){
			scanf("%d",&t);
			a[t]++;
			arr[i][t]++;
		}
	}
	int m=s+1,index=0;
	for(int i=0;i<n;i++){
		if(m>a[i]){
			m=a[i];
			index=i;
		}
	}
	int ans=0;
	for(int i=0;i<s;i++){
		if(arr[i][index]>0){
			an[ans]=i;
			ans++;
		}
			
	}
	if(ans<s-n+1){
		cout<<ans<<endl;
		for(int i=0;i<ans;i++)
			cout<<an[i]<<endl;
	}
	else{
		cout<<s-n+1<<endl;
	
		for(int i=0;i<s-n+1;i++)
			cout<<i<<endl;
	}
	return 0;
}
