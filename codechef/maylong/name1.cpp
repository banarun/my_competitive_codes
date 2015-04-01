#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s,s1;
        int l;
        int a[26]={0};
        int b[26]={0};
        for(int i=0;i<26;i++){
            a[i]=0;
            b[i]=0;
        }

        cin>>s;
        l=s.length();
        for(int i=0;i<l;i++){
            a[s[i]-'a']++;
        }
        cin>>s;
        l=s.length();
        for(int i=0;i<l;i++){
            a[s[i]-'a']++;
        }
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>s;
            l=s.length();
            for(int i=0;i<l;i++){
                b[s[i]-'a']++;
            }
        }
        int flag=0;
        for(int i=0;i<26;i++){
            if(a[i]<b[i]){
                flag=1;
                cout<<"NO\n";
                break;
            }
        }
        if(flag==0)
            cout<<"YES\n";
    }
    return 0;
}
