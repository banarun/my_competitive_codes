#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int n1=a.length();
        int n2=b.length();
        int j=0,i;
        if(n1>n2){
            for(i=0;i<n2;i++){
                while(j<n1 && b[i]!=a[j])
                    j++;
                if(j==n1){
                    break;
                }
                j++;
            }
            if(i<n2)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        else{
            for(i=0;i<n1;i++){
                while(j<n2 && b[j]!=a[i])
                    j++;
                if(j==n2){
                    break;
                }
                j++;
            }
            if(i<n1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }
    return 0;
}
