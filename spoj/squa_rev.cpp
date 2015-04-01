#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
	long long r,n=1,s,c,i,sq;
	while(cin>>s){
		n=1;
		n=s;
		int c=0;
		sq=sqrt(n/2);
		for(i=0;i<=sq;i++){
			r=sqrt(n-i*i);
			if(n-i*i==r*r){
				c++;
			}
		}
		cout<<c<<"\n";
		}
	return 0;
}
