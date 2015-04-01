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
int a[8][8],c[8][8]; 
char b[8][8];
int kmovex[10],kmovey[10];
int qmovex[100],qmovey[100];
int nmovex[10],nmovey[10];
int kcntr,qcntr,ncntr;
int flg;
void possible_moves(int tx,int ty,int kx,int ky,int qx,int qy,int nx,int ny);

bool inRange(int x,int y)
{
	if(x<0 || y<0 || x>7 || y>7 || b[x][y])
		return false;
	return true;
}

bool ir(int x,int y)
{
	if(x<0 || y<0 || x>7 || y>7)
		return false;
	if(b[x][y] && b[x][y]!='t'){
		flg=1;
	}
	return true;

}

bool inr(int x,int y)
{
	if(x<0 || y<0 || x>7 || y>7)
		return false;
	return true;
}

bool foo(int tx,int ty,int kx,int ky,int qx,int qy,int nx,int ny)
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(ir(kx-1+i,ky-1+j) && !(i==1 && j==1) ){
				//cout<<kx-1+i<<" "<<ky-1+j<<endl;
				c[kx-1+i][ky-1+j]=1;
			}
		}
	}	
	
	int x,y;
	x=nx;y=ny;
	if(ir(x+2,y+1))
		c[x+2][y+1]=1;
	if(ir(x+2,y-1))
		c[x+2][y-1]=1;
	if(ir(x-2,y+1))
		c[x-2][y+1]=1;
	if(ir(x-2,y-1))
		c[x-2][y-1]=1;
	if(ir(x+1,y+2))
		c[x+1][y+2]=1;
	if(ir(x+1,y-2))
		c[x+1][y-2]=1;
	if(ir(x-1,y+2))
		c[x-1][y+2]=1;
	if(ir(x-1,y-2))
		c[x-1][y-2]=1;	
	
	x=qx;y=qy;
	while(ir(x+1,y+1)){
		
		x++;
		y++;
		c[x][y]=1;
	}
	x=qx;y=qy;
	flg=0;
	while(ir(x+1,y-1)){
		x++;
		y--;
		c[x][y]=1;
		if(flg==1)
			break;
	}
	x=qx;y=qy;
	flg=0;
	while(ir(x-1,y+1)){
		x--;
		y++;
		c[x][y]=1;
		if(flg==1)
			break;
	}
	x=qx;y=qy;
	flg=0;
	while(ir(x-1,y-1)){
		x--;
		y--;
		c[x][y]=1;
		if(flg==1)
			break;

	}

	x=qx;y=qy;
	flg=0;
	while(ir(x+1,y)){
		x++;
		c[x][y]=1;
		if(flg==1)
			break;

	}
	x=qx;y=qy;
	flg=0;
	while(ir(x,y-1)){
		y--;
		c[x][y]=1;
		if(flg==1)
			break;

	}
	x=qx;y=qy;
	flg=0;
	while(ir(x-1,y)){
		x--;
		c[x][y]=1;
		if(flg==1)
			break;

	}
	x=qx;y=qy;
	flg=0;
	while(ir(x,y+1)){
		y++;
		c[x][y]=1;
		if(flg==1)
			break;

	}
	int f=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(inr(tx-1+i,ty-1+j) && !c[tx-1+i][ty-1+j]){
				f=1;
			}
			//c[tx-1+i][ty-1+j]=0;
		}
	}

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(inr(tx-1+i,ty-1+j))
				c[tx-1+i][ty-1+j]=0;
		}
	}
	
	if(f==0)
		return true;
	else
		return false;
}

int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		kcntr=0;
		ncntr=0;
		qcntr=0;
		for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){
			a[i][j]=0;
			b[i][j]=0;
			c[i][j]=0;
		}
		int tx,ty,kx,ky,qx,qy,nx,ny;
		cin>>tx>>ty>>kx>>ky>>qx>>qy>>nx>>ny;
		b[kx][ky]='k';
		b[tx][ty]='t';
		b[qx][qy]='q';
		b[nx][ny]='n';
		possible_moves(tx,ty,kx,ky,qx,qy,nx,ny);
		int f=0;
		if(foo(tx,ty,kx,ky,qx,qy,nx,ny))
			f=1;
			
		//for(int i=0;i<8;i++){for(int j=0;j<8;j++){cout<<b[i][j]<<a[i][j]<<" ";}cout<<endl;}
		//cout<<endl;
		
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if((a[i][j])&1){
					b[i][j]='k';
					b[kx][ky]=0;
					if(foo(tx,ty,i,j,qx,qy,nx,ny)){
						f=1;
						//cout<<"k"<<i<<j<<endl;
						break;
					}
					b[i][j]=0;
					b[kx][ky]='k';
				}
				if((a[i][j]>>1) &1){
					b[i][j]='n';
					b[nx][ny]=0;
					if(foo(tx,ty,kx,ky,qx,qy,i,j)){
						f=1;
						//cout<<"N"<<i<<j<<a[i][j]<<endl;
						break;
					}			
					b[i][j]=0;
					b[nx][ny]='n';		
				}
				if((a[i][j]>>2) & 1){
					b[i][j]='q';
					b[qx][qy]=0;
					if(foo(tx,ty,kx,ky,i,j,nx,ny)){
						f=1;
						//cout<<"Q"<<i<<j<<endl;
						break;
					}
					b[qx][qy]='q';
					b[i][j]=0;
				}
			}
			if(f==1)
				break;
		}
		//for(int i=0;i<8;i++){for(int j=0;j<8;j++){cout<<b[i][j]<<a[i][j]<<" ";}cout<<endl;}
		//cout<<endl;
		
		if(f==1){
			cout<<"CHECKMATE\n";
		}
		else
			cout<<"LUCKY\n";
	}
	return 0; 
}

void possible_moves(int tx,int ty,int kx,int ky,int qx,int qy,int nx,int ny)
{
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(inRange(kx-1+i,ky-1+j) && !(i==1 && j==1) ){
				a[kx-1+i][ky-1+j]++;
			}
			
		}
	}	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(inRange(tx-1+i,ty-1+j)){
				a[tx-1+i][ty-1+j]=0;
			}			
		}
	}
	
	int x,y;
	x=nx;y=ny;
	if(inRange(x+2,y+1)){
		a[x+2][y+1]+=2;
	}
	if(inRange(x+2,y-1))
		a[x+2][y-1]+=2;
	if(inRange(x-2,y+1))
		a[x-2][y+1]+=2;
	if(inRange(x-2,y-1))
		a[x-2][y-1]+=2;
	if(inRange(x+1,y+2))
		a[x+1][y+2]+=2;
	if(inRange(x+1,y-2))
		a[x+1][y-2]+=2;
	if(inRange(x-1,y+2))
		a[x-1][y+2]+=2;
	if(inRange(x-1,y-2))
		a[x-1][y-2]+=2;	
	
	x=qx;y=qy;
	while(inRange(x+1,y+1)){
		x++;
		y++;
		a[x][y]+=4;
	}
	x=qx;y=qy;
	while(inRange(x+1,y-1)){
		x++;
		y--;
		a[x][y]+=4;
	}
	x=qx;y=qy;
	while(inRange(x-1,y+1)){
		
		x--;
		y++;
		a[x][y]+=4;
	}
	x=qx;y=qy;
	while(inRange(x-1,y-1)){
		x--;
		y--;
		a[x][y]+=4;
	}

	x=qx;y=qy;
	while(inRange(x+1,y)){
		x++;
		a[x][y]+=4;
		
	}
	x=qx;y=qy;
	while(inRange(x,y-1)){
		y--;
		a[x][y]+=4;
		
	}
	x=qx;y=qy;
	while(inRange(x-1,y)){
		x--;
		a[x][y]+=4;
		
	}
	x=qx;y=qy;
	while(inRange(x,y+1)){
		y++;
		a[x][y]+=4;
	}
}
