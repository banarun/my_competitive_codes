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
int a[N];
int d[1001];
int main() 
{ 
	int n;
	int b[102];
	cin>>n;
	int c=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		if(a[i]!=b[i]){
			d[a[i]]++;
			d[b[i]]++;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]==b[i] ){
			c++;
		}
	}
	cout<<c<<endl;
	
	return 0; 
}
