#include <iostream>
#include <set>
#include <cstdio>
#include <algorithm>

using namespace std;
long long int a[300005];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	long long int count=0;
	for(int i=0;i<n;i++){
		if(a[i]-(i+1)>0){
			count=count+a[i]-(i+1);
		}
		else
			count=count+(i+1)-a[i];
	}
	
	cout<<count;
	return 0;
}
