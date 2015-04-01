#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int p=3,n,r;
	int k;
	cin>>k;
	
	unsigned long long int i=pow(2,k);
	if(i<=1000000009)
	cout<<i;
	else
	cout<<"More";
	return 0;
}
