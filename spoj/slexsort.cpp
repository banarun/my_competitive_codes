#include<iostream>
#include<algorithm>
using namespace std;int i,t,n,h[900],f,r;int q(string a,string b){f=b.length(),r=a.length();for(i=0;i<min(f,r);i++)if(a[i]!=b[i])return h[a[i]]<h[b[i]];return r<f;}int main(){string c,s[100000];cin>>t;while(t--){cin>>c>>n;for(i=0;i<n;i++)cin>>s[i];for(i=0;i<c.length();i++)h[c[i]]=i;sort(s,s+n,q);for(i=0;i<n;i++)cout<<s[i]<<"\n";cout<<"\n";}return 0;}
