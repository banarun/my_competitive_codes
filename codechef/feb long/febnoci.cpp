#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

vector<unsigned long long int> v(1000000);
int main()
{
	int p;
	unsigned long long int i;
	unsigned long long int a,b,t,n,gd;
	a=1;
	b=0;
	  
	for(i=0;i<1000000;i++){	
		a=a+b;
		b=a-b;
		b=b%(1000000000+7);
		a=a%(1000000000+7);
		v[i]=a;
	}
	
	scanf("%llu",&t);
	
	for(gd=0;gd<t;gd++){

		scanf("%llu%d",&n,&p);
		
		
		int count=0;
		a=v[n-1];
		while(a){
			count += a & 1;
			a >>= 1;
		}
		if(count==p)
			printf("CORRECT\n");
		else
			printf("INCORRECT\n");
		
	}
	
	return 0;
}
