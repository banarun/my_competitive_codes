#include <iostream>
using namespace std;

int count=0;
int n;
int b[11][11];
void rec(int a[11][11],int i,int j)
{
	if(i>=0 && j>=0 && i<n && j<n && a[i][j]==0){
		
		if(i==n-1&&j==n-1){
			count++;
			
			return;
		}
		
		a[i][j]=1;
		rec(a,i+1,j);
		rec(a,i,j+1);
		rec(a,i-1,j);
		rec(a,i,j-1);
		a[i][j]=0;
		
		
	}
	return;

}
int main()
{
	cin>>n;
	int a[11][11];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		cin>>a[i][j];
	}
		
	rec(a,0,0);
	
	cout<<count<<endl;
	return 0;
}
