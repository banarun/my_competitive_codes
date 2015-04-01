#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int main()
{
	int p=1,n,r,i;
	scanf("%d%d",&n,&r);
	for(i=0;i<r;i++)
	p=p*(n--);
	for(i=0;i<r;i++)
	p=p/(i+1);
	cout<<p;
	return 0;
}
