#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    int a[100001];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);

    int j=1;
    int count=0;
    for(int i=0;i<n;i++,j++){
        if(a[j]-a[i]==k){
            count++;
        }
        else if(a[j]-a[i]<k)
            i--;
        else if(a[j]-a[i]>k && j-i>1)
            j--;
    }
    cout<<count<<endl;
}
