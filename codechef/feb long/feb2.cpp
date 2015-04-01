#include <vector>
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int i,count=0,n,q,j,a,b;
	vector<int> x1,y1,v;
	scanf("%d%d",&n,&q);
	cout<<n<<q<<endl;
	for(i=0;i<n;i++){
		scanf("%d%d",&a,&b);
		x1.push_back(a);
		y1.push_back(b);
	}
	for(j=0;j<q;j++){
		int x,y,d,X,Y;
		scanf("%d%d%d",&x,&y,&d);
		count=0;
		for(i=0;i<n;i++){
			X=x1[i]-x;
			Y=y1[i]-y;
			if(X<0||Y<0)
				continue;
			else if(X+Y<=d){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
