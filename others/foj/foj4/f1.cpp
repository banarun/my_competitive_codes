#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main()
{
	int i,p,j,n,m,l;
	
	int t;
	scanf("%d",&t);
	string te;
	getline(cin,te);
	
	for(j=0;j<t;j++){
		
		string s;
		int a[10];
		getline(cin,s);
		for(i=0;i<10;i++)
			a[i]=0;
		for(i=0;i<s.length();i++)
			a[s[i]-'0']++;
		
		p=9;
		int sum=0;
		while(1){
			while(a[p]==0&&p!=0)
				p--;	
			
			if(p==0 && a[p]==0)
				break;
				a[p]--;
			printf("%d",p);
		}
		printf("\n");
	}
	return 0;
}
