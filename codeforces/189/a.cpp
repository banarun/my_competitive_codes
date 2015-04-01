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
#include <deque> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iomanip> 
#include <cctype> 
#include <ctime> 
using namespace std; 

#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
typedef pair<int,int> ipair; 
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X) 
#define inp(X) scanf("%d",&X)

#define mod 1000000007 
#define N 100002 
int add[101];
int main() 
{ 
	int n;
	cin>>n;
	int a[101],b[101];
	int k=0;
	for(int i=0;i<n;i++){
		int p;
		cin>>p;
		if(p==1){
			cin>>a[k]>>b[k];
			k++;
		}
		if(p==2){
			for(int i1=0;i1<100;i1++)
				add[i1]=0;
			
			int f,m;
			cin>>f>>m;
			
			add[f-1]=1;
			
			int f1=0;
			while(1){
				f1=0;
			for(int g=0;g<k;g++){
				if(add[g]){
			for(int j=0;j<k;j++){
				if(((a[g]>a[j] && a[g]<b[j]) || (b[g]>a[j] && b[g]<b[j])) && add[j]==0){
					add[j]=1;
					f1=1;
				}
			}
			}
			}
			if(f1==0)
				break;
		}
		if(add[m-1])
			cout<<"YES\n";
		else
			cout<<"NO\n";
		}
	}
	
	return 0; 
}
