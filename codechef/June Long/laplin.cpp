#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <vector> 
#include <deque> 
#include <set> 
#include <list> 
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
#define N 100002 

int main() 
{ 
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int p=n/2;
		int f=0;
		int a[26];
		for(int i=0;i<26;i++)
			a[i]=0;
		for(int i=0;i<n;i++){
			if(n%2 && i==n/2)
				continue;
			if(i<n/2)
			a[s[i]-'a']++;
			if(i>=n/2+n%2)
			a[s[i]-'a']--;
		}
		for(int i=0;i<26;i++)
			if(a[i]!=0)
				f=1;
		if(f==1)		
		cout<<"NO\n";
		else
		cout<<"YES\n";
	}
	return 0; 
}
