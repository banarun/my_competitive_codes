#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k;
		cin >> k;
		int count=0;
		for(int j=1;j<k;j++){
			
			int a[10];
			for(int i=0;i<10;i++)
				a[i]=0;
			int n=j;
			while(n){
				a[n%10]++;
				n=n/10;
			}
			count++;
			for(int i=0;i<10;i++)
				if(a[i]>1){
					count--;
					break;
				}
		}
		cout << count << endl;
			
	}
}
