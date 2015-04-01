#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <string> 
#include <algorithm> 
#include <complex> 
#include <climits> 
#include <utility> 
using namespace std; 
#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000 

bool isSubsetSum(int set[],const int n,const int sum)
{
   bool subset[sum+1][n+1];
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
     return subset[sum][n];
}


int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		int a[1001];
		int val[1001];
		int dp[1001][1001];
		int p,m;
		cin>>p>>m;
		for(int i=0;i<m;i++){
			cin>>a[i];
		}
		map<int,int> mp;
		map<int,int>::iterator it;
		for (int i = 0; i<p ; i++){
			int k;
			cin>>k;
			mp[k]++;
		}
		int n=0;
		for(it=mp.begin();it!=mp.end();it++){
			val[n++]=it->second;
		}
		sort(val,val+n);
		int count=0;
		for(int p=0;p<n;p++){
			if(isSubsetSum(a,m,val[p]))
				count++;
		}
		cout<<count<<endl;
	}
	
	return 0; 
}
