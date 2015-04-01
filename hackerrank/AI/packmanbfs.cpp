#include <iostream>
#include <cstdio>
using namespace std;

char a[100][100];
int v[100][100];
int u[100][100];
char stak[100000];
char mstak[100000];
int len=0,mlen=1000000000;
int fx,fy,ml=1;
int x,y,pax,pay;
int flag=0;
int ptr=0,cur=0;
int xar[40000],yar[40000];
int parx[100][100];
int pary[100][100];
	
void pman(int m,int n)
{
	cur++;
	if(cur>ml)
		return;
	
	
	if(a[m][n]=='.'){
		flag=1;
		cout<<cur<<endl;
		for(int i=0;i<cur;i++)
			cout<<xar[i]<<" "<<yar[i]<<endl;
		return;
	}
	if(m-1>=0 && (a[m-1][n]=='-' ||a[m-1][n]=='.') &&v[m-1][n]==0 ){
		xar[ml]=m-1;
		yar[ml]=n;
		parx[m-1][n]=m;
		pary[m-1][n]=n;
		ml++;
		v[m-1][n]=1;
	}
	if(n-1>=0 && (a[m][n-1]=='-'||a[m][n-1]=='.') &&v[m][n-1]==0){
		xar[ml]=m;
		yar[ml]=n-1;
		ml++;
		parx[m][n-1]=m;
		pary[m][n-1]=n;
		v[m][n-1]=1;
	}
	if(n+1<y && (a[m][n+1]=='-'||a[m][n+1]=='.') && v[m][n+1]==0){
		xar[ml]=m;
		yar[ml]=n+1;
		ml++;
		parx[m][n+1]=m;
		pary[m][n+1]=n;
		v[m][n+1]=1;
	}
	if(m+1<x && (a[m+1][n]=='-'||a[m+1][n]=='.') && v[m+1][n]==0 ){
		xar[ml]=m+1;
		yar[ml]=n;
		ml++;
		parx[m+1][n]=m;
		pary[m+1][n]=n;
		v[m+1][n]=1;
	}
	pman(xar[cur],yar[cur]);
		
	return;
	stak[len-1]='l';
	pman(m,n-1);
	stak[len-1]='r';
	pman(m,n+1);
	stak[len-1]='d';
	pman(m+1,n);
	v[m][n]=0;
	len--;
}
int main()
{
	int px,py;

	
	cin>>px>>py>>fx>>fy>>x>>y;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>a[i][j];
		}
	}
	pax=px;
	pay=py;
	xar[0]=px;
	yar[0]=py;
	pman(px,py);
	int tx=fx,ty=fy,i=1;
	xar[0]=fx;
	yar[0]=fy;
	while(1){
		if(tx==px && ty==py)
			break;
		xar[i]=parx[tx][ty];
		yar[i]=pary[tx][ty];
		tx=xar[i];
		ty=yar[i];
		i++;
	}
	cout<<i-1<<endl;
	for(int j=i-1;j>=0;j--){
		cout<<xar[j]<<" "<<yar[j]<<endl;
	}
/*
		
		cout<<ml<<endl;
		//cout<<pax<<" "<<pay<<endl;
		for(int i=0;i<ml;i++){
			cout<<xar[i]<<" "<<yar[i]<<endl;
		}	
		cout<<mlen<<endl;
		pax=tx;pay=ty;
		cout<<pax<<" "<<pay<<endl;
		for(int i=0;i<mlen;i++){
			if(mstak[i]=='u')
				cout<<--pax<<" "<<pay<<endl;
			if(mstak[i]=='l')
				cout<<pax<<" "<<--pay<<endl;
			if(mstak[i]=='r')
				cout<<pax<<" "<<++pay<<endl;
			if(mstak[i]=='d')
				cout<<++pax<<" "<<pay<<endl;
		}
		*/
		
	return 0;
}
