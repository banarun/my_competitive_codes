#include<iostream>
using namespace std;

int main()
{
	
	int n,i;
	cin>>n;
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int temp;
	for(i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		if(a>c)
		{
			temp=a;
			a=c;
			c=temp;
		}
		if(b>c)
		{
			temp=b;
			b=c;
			c=temp;
		}
		unsigned long long int total=(a*b*c-a*(b-1)-a*(c-1)-(b-a)*a-a*(a-1)-a)%(1000000000+7);
		cout<<total<<endl;
	}
	return 0;

}
