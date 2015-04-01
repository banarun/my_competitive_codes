#include <iostream>
#include <cmath>
using namespace std;

int main(){

	long long int a,b,c,d;
	cin>>a>>b;
	int count=0;
	while(b){
	count++;
	b>>=1;
	}
	c=a;
	d=~c;
	d=c+d+1;
	cout<<c<<" "<<d<<endl;
	while(1){
		if(c<=b && c>=a ){}
		break;
	}
}
