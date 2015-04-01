#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a=n;
	int b=n/10;
	int c=(n/100)*10+n%10;
	cout<<max(a,max(b,c))<<endl;
	return 0;
}
