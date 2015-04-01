	#include <iostream>
	#include <cstdio>
	using namespace std;

	char a[100][100];
	int v[100][100];
	char stak[10000];
	char mstak[10000];
	int xar[10000];
	int yar[10000];
	int len=0,mlen=0,mxlen=1000000;
	int fx,fy;
	int x,y,pax,pay;
	int flag=0;
		
	void pman(int m,int n)
	{
		if(m<0 || m>=x || n<0 || n>=y || a[m][n]=='%' || v[m][n]==1){
			return;
		}
		v[m][n]=1;
		mlen++;
		xar[mlen-1]=m;
		yar[mlen-1]=n;
		
		if(a[m][n]=='.'){
			if(mxlen>len){
				mxlen=len;
				for(int i=0;i<len;i++)
				mstak[i]=stak[i];
			}
			v[m][n]=0;
			return;
		}
		len++;
		
		stak[len-1]='u';
		mstak[mlen-1]='u';
		pman(m-1,n);
		
		
		stak[len-1]='l';
		mstak[mlen-1]='l';
		pman(m,n-1);
		
		//mlen++;
		
		stak[len-1]='r';
		mstak[mlen-1]='r';
		pman(m,n+1);
		
		
		stak[len-1]='d';
		mstak[mlen-1]='d';
		pman(m+1,n);
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
		
		pman(px,py);
		
		int tx=pax,ty=pay;
		cout<<mlen<<endl;
		//cout<<pax<<" "<<pay<<endl;
		for(int i=0;i<mlen;i++){
			cout<<xar[i]<<" "<<yar[i]<<endl;
		}	
		cout<<mxlen<<endl;
		pax=tx;pay=ty;
		cout<<pax<<" "<<pay<<endl;
		for(int i=0;i<mxlen;i++){
			if(mstak[i]=='u')
				cout<<--pax<<" "<<pay<<endl;
			if(mstak[i]=='l')
				cout<<pax<<" "<<--pay<<endl;
			if(mstak[i]=='r')
				cout<<pax<<" "<<++pay<<endl;
			if(mstak[i]=='d')
				cout<<++pax<<" "<<pay<<endl;
		}
		
		return 0;
	}

