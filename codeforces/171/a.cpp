#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <cstdlib>
using namespace std;

int main()
{
	int x,y;
	cin>>x>>y;
	if(x==0 && y==0){
		cout<<"0";
		return 0;
	}
	else if(x==0 && y==1){
		cout<<"2";	
	}
	else if(x==1 && y==0){
		cout<<"0";
	}
	else if(x>y && x<=y*-1+1 && y<0){
		cout<<4*(y)*-1;
	}
	
	else if(x>=y && x>0){
		cout<<4*(x-1)+1;
	}
	
	else if( (abs(x)<y||x==-1*y) && y>0){
		cout<<4*(y-1)+2;
	}
	
	else if( x<=y && x<0){
		cout<<4*(x+1)*-1+3;
	}
	return 0;
}
