#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;
    int a[100];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=(i/k+1)*a[n-1+i];
    }
    cout<<ans<<endl;
    return 0;
}
