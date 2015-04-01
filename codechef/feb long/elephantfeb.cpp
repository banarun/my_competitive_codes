#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	unsigned long long int p,g;
	int pt,n,j,t,i;
	scanf("%ull",&t);
	
	for(j=0;j<t;j++){
		scanf("%ull",&n);
		for(i=0;i<n;i++){
		//	scanf("%d",&pt);
		}
		g=1;
		for(i=0;i<n;i++){
			g=g*2;
			if(g>1000000007)
				g=g%1000000007;
		}
		
		if(n%2==1){
			cout<<g/2<<endl;
		}
		else{
			unsigned long long int k=n,p=1;
			for(i=0;i<n/2;i++){
				p=(p*(k--))/(i+1);
				if(p>1000000007)
				p=p%1000000007;
			}
			if(g>p)
				g=(g-p)/2;
			else
				g=(p-g)/2;
			cout<<g<<endl;
		}
	}
	
	return 0;
}

