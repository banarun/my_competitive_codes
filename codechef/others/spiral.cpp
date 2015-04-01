#include <iostream>
using namespace std;

int main()
{
	int n,p;
	cin>>n;
	int a[15][15];
	p=n*n;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			a[i][j]=0;
		i=0;
	int g=0,h=n;
	int f;
	if(n%2==1){
		f=n/2+1;
		
		while(f){
			for(j=h-1;j>=g;j--){
				a[h-1][j]=p--;
			}
			for(i=h-2;i>=g;i--)
				a[i][g]=p--;
			for(j=g+1;j<h;j++)
				a[g][j]=p--;
			for(i=g+1;i<h-1;i++)
				a[i][j-1]=p--;
			g++;
			h--;
			f--;
		}
	}
	else{
		f=n/2;
	
		while(f){
			i=g;
			for(j=g;j<h;j++)
				a[i][j]=p--;
			for(i=g+1;i<h;i++)
				a[i][j-1]=p--;
			for(j=h-2;j>=g;j--)
				a[i-1][j]=p--;
			for(i=h-2;i>g;i--)
				a[i][g]=p--;
			g++;
			h--;
			f--;	
		}
	}
	if(n<10&&n>3)
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]<10)
				cout<<a[i][j]<<"  ";
			else
				cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	else if (n<=3){
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	else{
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]<10)
				cout<<a[i][j]<<"   ";
			else if(a[i][j]<100)
				cout<<a[i][j]<<"  ";
			else
				cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	}
		
	return 0;
}
