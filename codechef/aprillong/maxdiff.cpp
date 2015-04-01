#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k,a[102];
		scanf("%d%d",&n,&k);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int sum=0;
		if(k<=n-k){
			for(int i=k;i<n;i++)
				sum=sum+a[i];
			for(int i=0;i<k;i++)
				sum=sum-a[i];
			if(sum<0){
				sum=-sum;
			}
			printf("%d\n",sum);
		}
		else{
			for(int i=n-k;i<n;i++)
				sum=sum+a[i];
			for(int i=0;i<n-k;i++)
				sum=sum-a[i];
			if(sum<0){
				sum=-sum;
			}
			printf("%d\n",sum);
		}
	}
}
