#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int a[5][5],b[5][5];
	int j,i,n;
	for(i=0;i<5;i++)
	for(j=0;j<5;j++)
		a[i][j]=0;
		
	for(i=1;i<4;i++)
	for(j=1;j<4;j++)
		cin>>a[i][j];
	
	for(i=1;i<=3;i++)
	for(j=1;j<=3;j++){
		if((a[i][j]+a[i+1][j]+a[i-1][j]+a[i][j-1]+a[i][j+1])%2==0)
			b[i][j]=1;
		else
			b[i][j]=0;
		
	}
	
	for(i=1;i<=3;i++){
		for(j=1;j<=3;j++){
			cout<<b[i][j];
		}
	cout<<endl;
	}
	
	return 0;
}
