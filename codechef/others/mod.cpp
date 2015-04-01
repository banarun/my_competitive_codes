#include <iostream>
#include <vector>

using namespace std;

int count=0;
int n;
void rec(vector<int> **a,int i,int j)
{
	if(i>=0 && j>=0 && i<n && j<n){
		
		if(i==n-1&&j==n-1){
			count++;
			return;
		}
		
		cout<<i<<" "<<j<<endl;
		rec(a,i+1,j);
		rec(a,i,j+1);
		rec(a,i-1,j);
		rec(a,i,j-1);
	}
	return;

}
int main()
{
	cin>>n;
	vector<int> a[11];
	int k;
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++){
		cin>>k;
		a[i].push_back(k);
	}
		
	rec(a,0,0);
	
	cout<<count<<endl;
	return 0;
}
