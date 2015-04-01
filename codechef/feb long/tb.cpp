#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;
 
int main()
{
    int n,i;
    scanf("%d",&n);
    
    string t,s[50],str1[50];
    getline(cin,t);
    for(i=0;i<n;i++){
		getline(cin,s[i]);
		str1[i]=s[i];
	}
    int rs1[2500],rs2[2500],cs1[2500],cs2[2500];
    char csl1[2500];
    int count1=50000;
    
    {
    
    int r1[2500],r2[2500],c1[2500],c2[2500];
	char cl[2500];
	int j,k,count=0,cnt=0;
	int row[2500],row2[2500],col[2500],col2[2500];
	char car[2500];
    
    int p,q;
    for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			k=j;
			while(s[i][k]=='B'){
				k++;
			}
			if(k>j+1){
				p=j;
				while(s[i][p]=='B'&&p<k)
					s[i][p++]='W';
				r1[count]=i;
				c1[count]=j;
				c2[count]=k-1;
				r2[count]=i;
				cl[count]='B';
				count++;
				j=k-1;
			}
		}
	}
	
	for(j=0;j<n;j++){		
		for(i=0;i<n;i++){
			k=i;
			while(s[k][j]=='B'){
				k++;
			}
			if(k>i+1){
				p=i;
				while(s[p][j]=='B' && p<k)
					s[p++][j]='W';
				r1[count]=i;
				c1[count]=j;
				c2[count]=j;
				r2[count]=k-1;
				cl[count]='B';
				count++;
				i=k-1;
			}
		}
	}
	
	for(i=0;i<count;i++){
		cnt=count;
		row[i]=r1[i];		
		col[i]=c1[i];
		col2[i]=c2[i];
		row2[i]=r2[i];
		car[i]=cl[i];
	}
	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			k=j;
			while(s[i][k]=='B'){
				k++;
			}
			if(k>j){
				r1[count]=i;
				c1[count]=j;
				c2[count]=k-1;
				r2[count]=i;
				cl[count]='B';
				count++;
				j=k-1;
			}
		}
		
		
		for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				k=i;
				while(s[k][j]=='B'){
					k++;
				}
				if(k>i){
					row[cnt]=i;
					col[cnt]=j;
					col2[cnt]=j;
					row2[cnt]=k-1;
					car[cnt]='B';
					cnt++;
					i=k-1;
				}
			}
		}
		
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		count1=count;
		for(int cog=0;cog<count1;cog++){
				rs1[cog]=r1[cog];
				rs2[cog]=r2[cog];
				cs1[cog]=c1[cog];
				cs2[cog]=c2[cog];
				csl1[cog]=cl[cog];
			}
			
			
			
			
			
			
			
			
			
			
	for(i=0;i<n;i++)
		s[i]=str1[i];
		
	row[0]=0;row2[0]=n-1;col[0]=0;col2[0]=n-1;car[0]='B';cnt=1;
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			k=j;
			while(s[i][k]=='W'){
				k++;
			}
			if(k>j+2){
				p=j;
				while(s[i][p]=='W'&&p<k)
					s[i][p++]='B';
				row[cnt]=i;
				col[cnt]=j;
				col2[cnt]=k-1;
				row2[cnt]=i;
				car[cnt]='W';
				cnt++;
				j=k-1;
			}
		}
	}
	
	for(j=0;j<n;j++){		
		for(i=0;i<n;i++){
			k=i;
			while(s[k][j]=='W'){
				k++;
			}
			if(k>i+1){
				p=i;
				while(s[p][j]=='W' && p<k)
					s[p++][j]='B';
				row[cnt]=i;
				col[cnt]=j;
				col2[cnt]=j;
				row2[cnt]=k-1;
				car[cnt]='W';
				cnt++;
				i=k-1;
			}
		}
	}
			for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				int k=i;
				while(s[k][j]=='W'){
					k++;
				}
				if(k>i){
					row[cnt]=i;
					col[cnt]=j;
					col2[cnt]=j;
					row2[cnt]=k-1;
					car[cnt]='W';
					cnt++;
					i=k-1;
				}
			}
		}	
		
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		
		for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				int k=i;
				while(s[j][k]=='W'){
					k++;
				}
				if(k>i){
					row[cnt]=j;
					col[cnt]=i;
					col2[cnt]=k-1;
					row2[cnt]=j;
					car[cnt]='W';
					cnt++;
					i=k-1;
				}
			}
		}	
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		
		if(count<count1){
			count1=count;
			for(int cog=0;cog<count1;cog++){
				rs1[cog]=r1[cog];
				rs2[cog]=r2[cog];
				cs1[cog]=c1[cog];
				cs2[cog]=c2[cog];
				csl1[cog]=cl[cog];
			}
			
		}
	
	}
    
    
    {
		for(i=0;i<n;i++)
			s[i]=str1[i];

		int r1[2500],r2[2500],c1[2500],c2[2500];
		char cl[2500];
		int j,count=0,cnt=0;
		int row[2500],row2[2500],col[2500],col2[2500];
		char car[2500];
		for(i=0;i<n;i++)
		for(j=0;j<n;j++){
			int k=j;
			while(s[i][k]=='B'){
				k++;
			}
			if(k>j){
				r1[count]=i;
				c1[count]=j;
				c2[count]=k-1;
				r2[count]=i;
				cl[count]='B';
				count++;
				j=k-1;
			}
		}
		cnt=0;
		for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				int k=i;
				while(s[k][j]=='B'){
					k++;
				}
				if(k>i){
					row[cnt]=i;
					col[cnt]=j;
					col2[cnt]=j;
					row2[cnt]=k-1;
					car[cnt]='B';
					cnt++;
					i=k-1;
				}
			}
		}
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		
		row[0]=0;row2[0]=n-1;col[0]=0;col2[0]=n-1;car[0]='B';cnt=1;
	 
		for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				int k=i;
				while(s[k][j]=='W'){
					k++;
				}
				if(k>i){
					row[cnt]=i;
					col[cnt]=j;
					col2[cnt]=j;
					row2[cnt]=k-1;
					car[cnt]='W';
					cnt++;
					i=k-1;
				}
			}
		}	
		
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		
		row[0]=0;row2[0]=n-1;col[0]=0;col2[0]=n-1;car[0]='B';cnt=1;
	 
		for(j=0;j<n;j++){		
			for(i=0;i<n;i++){
				int k=i;
				while(s[j][k]=='W'){
					k++;
				}
				if(k>i){
					row[cnt]=j;
					col[cnt]=i;
					col2[cnt]=k-1;
					row2[cnt]=j;
					car[cnt]='W';
					cnt++;
					i=k-1;
				}
			}
		}	
		if(count<=cnt){
	 
		}
		else{
			count=cnt;
			for(i=0;i<count;i++){
				r1[i]=row[i];
				r2[i]=row2[i];
				c1[i]=col[i];
				c2[i]=col2[i];
				cl[i]=car[i];
			}
		}
		
		if(count<count1){
			count1=count;
			for(int cog=0;cog<count1;cog++){
				rs1[cog]=r1[cog];
				rs2[cog]=r2[cog];
				cs1[cog]=c1[cog];
				cs2[cog]=c2[cog];
				csl1[cog]=cl[cog];
			}
			
		}
	}
	printf("%d\n",count1);
	for(int i5=0;i5<count1;i5++)
		cout<<rs1[i5]<<" "<<cs1[i5]<<" "<<rs2[i5]<<" "<<cs2[i5]<<" "<<csl1[i5]<<endl;
	
	return 0;
}
