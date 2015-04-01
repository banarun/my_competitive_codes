#include <iostream>
#include <climits>
#include <vector>
using namespace std;
int main()
{
	int n,d,a[100001],i,sum=0,min=INT_MIN,left=0;
	cin>>n>>d;
	for(i=0;i<n;i++)
	cin>>a[i];

	for(i=0;i<n;i++){
		sum+=a[i];
		if(sum>d){
			while(sum>d){
				sum-=a[left];
				left++;
			}
		}
		if(i-left+1>min)
		min=i-left+1;
	}

	cout<<min<<endl;
	return 0;
}
