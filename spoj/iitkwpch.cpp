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
#define N 100001
int a[3024]; 
int num[3024];
int val[3024];
int tpow[10];
ll p;

ll in()
{
    ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

inline void inp()
{
	int b[10]={0};
    ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;b[c-'0']++,c=getchar_unlocked());
    p=0;
    for(int i=0;i<10;i++){
		if(b[i]>0){
			p+=tpow[i];
		}
	}
		
}

int main() 
{ 
	int t;
	t=in();
	int n;
	
	tpow[0]=1024;
	for(int i=1;i<10;i++)
		tpow[i]=tpow[i-1]/2;
	
	while(t--){
			n=in();
		for(int i=0;i<2048;i++){
			a[i]=0;
		}
		for(int i=0;i<n;i++){
			
			int b[10]={0};
			inp();
			a[p]++;
		}
		int k=0;
		ull ans=0;
		//cout<<"A\n";
		for(int i=0;i<2048;i++){
			if(a[i]>0){
				num[k]=i;
				val[k]=a[i];
				ll int temp=val[k];
				temp=val[k]*(val[k]-1);
				temp=temp/2;
				ans+=temp;
				k++;
			}
		}		
		for(int i=0;i<k;i++){
			//cout<<num[i]<<" ";
			for(int j=i+1;j<k;j++){
				if(num[i] & num[j]){
					ans+=val[i]*val[j];
				}
			}
		}
		printf("%llu\n",ans);
	}
	return 0; 
}
