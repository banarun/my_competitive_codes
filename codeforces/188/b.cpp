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

vector<int> a,b;

int main() 
{ 
	string s;
	cin>>s;
	int n=s.length();
	int k=0,p=0,q=0;	
	
	while(1){
		k=s.find("heavy",k);
		
		if(k<0)
			break;
		a.push_back(k);
		k++;
	}
	k=0;
	while(1){
		k=s.find("metal",k);
		if(k<0)
			break;
		b.push_back(k);
		k++;
	}
	p=a.size();
	q=b.size();
	int r=min(p,q);
	ll int ans=0;
	int i=0,j=0;
	while(i<p && j<q){
		if(a[i]<b[j]){
			ans+=q-j;
			i++;
		}
		else
			j++;
	}
	cout<<ans<<endl;
	return 0; 
}
