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
		long long int total=(((((a)%(1000000007))*((b)%(1000000007)))%(1000000007)*((c)%(1000000007)))%(1000000007)-(((a)%(1000000007))*((b-1)%(1000000007)))%(1000000007)-(((a)%(1000000007))*((c-1)%(1000000007)))%(1000000007)-(((b-a)%(1000000007))*((a)%(1000000007)))%(1000000007)-(((a)%(1000000007))*((a-1)%(1000000007)))%(1000000007)-a%(1000000007))%(1000000007);
		
		if(total<0)
		cout<<(total*(-1))%(1000000007);
		else
		cout<<total<<endl;
	}
	return 0;

}
