#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i=0;
	int n,q;
	
	vector<long long int> row,col;
	cin>>n>>q;
	string t;
	long long int rm=0,cm=0;
	int a,b;
	for(i=0;i<n;i++){
		row.push_back(0);
		col.push_back(0);
	}
	for(i=0;i<q;i++){
		cin>>t>>a>>b;
		if(t[0]=='R')
			row[a-1]+=b;
		if(t[0]=='C')
			col[a-1]+=b;
	}
	for(i=0;i<n;i++){
		if(row[i]>rm)
			rm=row[i];
		if(col[i]>cm)
			cm=col[i];
	}
	cout<<rm+cm<<endl;
	
	
	
	return 0;
}
