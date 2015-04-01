#include <cstdio>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
#define PB push_back
#define MP make_pair
#define clr(x) x.clear()
#define sz(x) ((int)(x).size())
#define F first
#define S second
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,b) for(i=0;i<b;i++)
#define rep1(i,b) for(i=1;i<=b;i++)
#define mod 1000000007
#define pi(n) printf("%d",n)
#define pin(n) printf("%d\n",n)
#define piw(n) printf("%d ",n)
#define pll(n) printf("%lld",n)
#define plln(n) printf("%lld\n",n)
#define pllw(n) printf("%lld ",n)
#define sll(n) scanf("%lld",&n)
#define ss(s) scanf("%s",s)
#define ps(s) printf("%s",s)
#define psn(s) printf("%s\n",s)
#define psw(s) printf("%s ",s)
#define si(n) scanf("%d",&n)
#define pn printf("\n")
#define pw printf(" ")
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
map<int,int> mymap;
map<int,int>::iterator it;
int dp[100010];
int A[100010];
int val[100010][100];
int req[100];
int main()
{
    int y,T,n,m,i,t,j,k,x;
    
    si(n);
    
    rep(i,n)si(A[i]);
    
    if(n==1){psn("0 0");return 0;}
 
    for(i=0;i<n;i++)
        if(A[i]%n==0)
        {
            cout<<i<<" "<<i<<endl;return 0;		
        }
 
 
    rep(i,n+1)dp[i]=0;
    
    
    int N=n;
    for(i=2;i<=n;i++)
        while(n%i == 0)
        {
            mymap[i]++;
            n/=i;
        }
    n=N; 
    int c=0;
    for(it=mymap.begin();it!=mymap.end();it++)
        req[c++]=(it->second);                                                                                                                                                        
    rep(i,n)
    {
        int c=0;
        for(it=mymap.begin();it!=mymap.end();it++)
        {
            val[i][c]=0;
            while(A[i]%(it->first)==0)
            {
                val[i][c]++;
                A[i]/=(it->first);
            }
            c++;
        }
    }
    while(c--)
		{
        int X=req[c];
        int j=0,k=0;
        int x=0;
        while(1)
        {
 
            if(k<n)
                x+=val[k++][c];
            while(j<N && x>=X)
            {
                dp[j]=max(dp[j],(k-j));
                x-=val[j++][c];
            }
            if(k>=n)break;
        }
        for(;j<n;j++)dp[j]=1000000000;
    }
    int ans=10000000;
    int mini=-1;
    rep(i,n)if(dp[i]<ans){ans=dp[i];mini=i;}
    if(mini==-1){pin(-1);return 0;}
    piw(mini);pin(mini+ans-1);
    return 0;
}
