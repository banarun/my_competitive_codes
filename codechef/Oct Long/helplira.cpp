#include <iostream>
#include <cstdlib>
#include <algorithm>	
using namespace std; 
int main()
{
	long long int maxarea=-1,maxindex;
	long long int minarea=10000000000LL,minindex;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long int x1,y1,x2,y2,x3,y3;
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
		long long int a=abs(x1*(y2-y3)+x2*(y3-y1)+x3*(y1-y2));
		if(a<=minarea){
			minarea=a;
			minindex=i;
		}
		if(a>=maxarea){
			maxarea=a;
			maxindex=i;
		}
	}
	cout<<minindex<<" "<<maxindex;
	return 0;
}
