#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	vector<int> v;
	int a=103993;
    int b=33102;
    int n,c=(a%b)*10;
    int i,j,p=0,t,count=0,max=1000005;
    for(i=0;i<max;i++){
			t=c/b;
            v.push_back(t);
            c=c%b;
            c=c*10;
	}
	
	scanf("%d",&t);
    for(j=0;j<t;j++){
        scanf("%d",&n);
        if(n==0){
            printf("3\n");
        }
        else{
			printf("3.");
            for(i=0;i<n;i++)
				printf("%d",v[i]);
			printf("\n");
		}
	}
	return 0;
}
