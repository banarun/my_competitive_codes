#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned long long int n,p,c=0;
	unsigned long long int po,flag=0;
	
	cin>>p;
	
	for(int i=1;i<p;i++){
		po=1;
		flag=0;
		for(int j=1;j<p-1;j++){
			po=(po*i)% p;
			if(po % p == 1){
				flag=1;
				break;
			}
		}
		if(flag == 0 && (po*i)%p==1 ){
			c++;
		}
	}
	cout<<c<<endl;
	return 0;
}
	
