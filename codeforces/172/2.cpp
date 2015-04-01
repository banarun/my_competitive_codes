#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
	double n,x,y;
	cin>>x>>y>>n;
	int p;
	int gcd,a,b,t;
	a=int(x);
	b=int (y)	;
	while(b!=0){
		t=b;
		b=a%b;
		a=t;
		gcd=a;
	} 
	y=y/gcd;
	x=x/gcd;
	double d=double(x)/y;
	if((n==1 && x/y>0.5 )|| x==y){
		cout<<"1/1";
		return 0;
	}
	else if(n==1 && x/y<=0.5){
		cout<<"0/1";
		return 0;
	}
	else if(y<=n){
		cout<<x<<"/"<<y<<endl;
		return 0;
	}
	//cout<<x<<" "<<y<<endl;
	if(y>x){
		p=y/x;
		while(y>n){
			
			if(y-p>=n)
				y=y-p;
			else
				y=n;
			if(x-1>0)
				x--;
			else
				y=n;
		}
		
		double diff1,diff2;
		double p=double(x)/y;
		diff1=d-p;
		y--;
		p=double(x)/y;
		diff2=p-d;
		if(diff2<=diff1){
			a=int(x);
			b=int (y)	;
			while(b!=0){
				t=b;
				b=a%b;
				a=t;
				gcd=a;
			} 
			y=y/gcd;
			x=x/gcd;
			cout<<x<<"/"<<y<<endl;
		}
		else{
			y++;
			a=int(x);
			b=int (y);
			while(b!=0){
				t=b;
				b=a%b;
				a=t;
				gcd=a;
			} 
			y=y/gcd;
			x=x/gcd;	
			cout<<x<<"/"<<y<<endl;
		}
	}
	else if(x>y){
		p=x/y;
	}
	
	return 0;
}
