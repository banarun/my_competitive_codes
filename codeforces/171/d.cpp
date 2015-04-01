#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int a=INT_MAX;
	float	 d=a;
	cout<<a<<endl;
	cout<<"\v";
	long long p = static_cast<long long> (a) * a;
	long long b = a*a;
	cout<<p<<endl;
	cout<<b<<endl;
	cout<<d;
	return 0;
}
