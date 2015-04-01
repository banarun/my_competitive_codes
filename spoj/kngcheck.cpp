#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility> 
using namespace std; 
#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000 

bool ir(int x,int y)
{
	if(x<0 || y<0 || x>7 || y>7)
		return false;
	return true;

}

int cb[8][8];

void wknight(int x,int y)
{
	if(ir(x+2,y+1))
		cb[x+2][y+1]=1;
	if(ir(x+2,y-1))
		cb[x+2][y-1]=1;
	if(ir(x-2,y+1))
		cb[x-2][y+1]=1;
	if(ir(x-2,y-1))
		cb[x-2][y-1]=1;
	if(ir(x+1,y+2))
		cb[x+1][y+2]=1;
	if(ir(x+1,y-2))
		cb[x+1][y-2]=1;
	if(ir(x-1,y+2))
		cb[x-1][y+2]=1;
	if(ir(x-1,y-2))
		cb[x-1][y-2]=1;		
}

void wpawn(int x,int y)
{
	if(ir(x-1,y-1))
		cb[x-1][y-1]=1;
	if(ir(x-1,y+1))
		cb[x-1][y+1]=1;
}

void wking(int x,int y)
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(ir(x-1+i,y-1+j) && !(i==1 && j==1) ){
				cb[x-1+i][y-1+j]=1;
			}
		}
	}	

}

int main() 
{
	int t,p=0;
	cin>>t;
	while(t--){
		p++;
		char s[20][20];
		int wx,wy,bx,by;
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){
			cb[i][j]=0;
		}
		char junk;
		for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin>>s[i][j];
			if(s[i][j]!='-'){
				cin>>s[i][j+1];
				if(s[i][j]=='W' && s[i][j+1]=='H'){
					wknight(i,j);
				}
				if(s[i][j]=='B' && s[i][j+1]=='K'){	
					bx=i;
					by=j;
				}
				if(s[i][j]=='W' && s[i][j+1]=='K'){
					wking(i,j);
				}
				if(s[i][j]=='W' && s[i][j+1]=='P'){
					wpawn(i,j);
				}
			}
		}
		}
		cout<<"Case #"<<p<<": ";
		if(cb[bx][by]==1){
			cout<<"Check\n";
		}
		else
			cout<<"Not Check\n";
	}
	return 0; 
}
