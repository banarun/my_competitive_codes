#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;


int main()
{
	int a[51][51];
	int i,j,n,m;
	string asd;
	string s[50];
	cin>>n>>m;
	getline(cin,asd);
	for(i=0;i<n;i++)
	getline(cin,s[i]);
	int flg=0;

	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	if(s[i][j]=='B')
	a[i][j]=1;
	else
	a[i][j]=0;
	
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			
			if(a[i][j]==1){
				
				for(int i1=0;i1<n;i1++){
					for(int j1=0;j1<m;j1++){
												
						if(a[i1][j1]==1){
							int i2=i;
							int j2=j;
							//cout<<i1<<j1<<i2<<j2<<endl;						
							flg=0;
							int p=i2;
							int k=j2;
							
							while(1){
								if(i2>i1){
									i2--;
								}
								else if(i2<i1){
									i2++;
								}
								else
									break;
								
								if(a[i2][j2]!=1){
									flg=1;
									break;
								}
								
							}
							
							while(1){
								if(j2>j1)
									j2--;
								else if(j2<j1)
									j2++;
								else
									break;
									
								if(a[i2][j2]!=1){
									flg=1;
									break;
								}
							}
							
							if(flg==1){
								i2=p;
								j2=k;
								flg=0;
								while(1){
									if(j2>j1)
										j2--;
									else if(j2<j1)
										j2++;
									else
										break;
										
									if(a[i2][j2]!=1){
										flg=1;
										break;
									}
								}
								while(1){
									if(i2>i1)
										i2--;
									else if(i2<i1)
										i2++;
									else
										break;
									if(a[i2][j2]!=1){
										flg=1;
										break;
									}
									
								}
							}
							
							if(flg==1){
								cout<<"NO\n";
								return 0;
							}
						}
					}
				}
			}
			
		}
	}
	if(flg==0)
		cout<<"YES\n";
	
	
	return 0;
}
