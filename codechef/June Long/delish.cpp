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
	for(int t1=0;t1<t;t1++){
		ll int a[100001];
		int n;
		ll int a1[100001],b1[100001];
		ll int a2[100001],b2[100001];
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%lld",&a[i]);
			
		}
		a1[0]=a[0];
		b1[0]=a[0];
		a2[n-1]=a[n-1];
		b2[n-1]=a[n-1];
		ll int ma=a[0]-1,mi=a[0]+1,s1=a[0],s2=a[0],cma=0,cmi=0;
		int neg=0,curmax=ma;
		int pos=0,curmin=mi;
		for(int i=0;i<n;i++){
			if(a[i]>=0)
				neg=1;
			if(a[i]>curmax)
				curmax=a[i];
			if(a[i]<=0)
				pos=1;
			if(a[i]<curmin)
				curmin=a[i];
			cma+=a[i];
			cmi+=a[i];
			if(cma<0)
				cma=0;
			if(cmi>0)
				cmi=0;
			if(cma>ma)
				ma=cma;
			if(cmi<mi)
				mi=cmi;
			if(neg)
			a1[i]=ma;
			else
			a1[i]=curmax;
			if(pos)
			b1[i]=mi;
			else
			b1[i]=curmin;
		}
		
		ma=a[n-1]-1;mi=a[n-1]+1;cma=0;cmi=0;
		neg=0;curmax=ma;
		pos=0;curmin=mi;
		for(int i=n-1;i>=0;i--){
			if(a[i]>=0)
				neg=1;
			if(a[i]>curmax)
				curmax=a[i];
			if(a[i]<=0)
				pos=1;
			if(a[i]<curmin)
				curmin=a[i];
			cma+=a[i];
			cmi+=a[i];
			if(cma<0)
				cma=0;
			if(cmi>0)
				cmi=0;
			if(cma>ma)
				ma=cma;
			if(cmi<mi)
				mi=cmi;
			if(neg)
			a2[i]=ma;
			else
			a2[i]=curmax;
			if(pos)
			b2[i]=mi;
			else
			b2[i]=curmin;
		}

		ll ans=0;
		for(int i=1;i<n;i++){
			ll t1=abs(a1[i-1]-b2[i]);
			ll t2=abs(b1[i-1]-a2[i]);
			ans=max(ans,max(t1,t2));
		}
		printf("%lld\n",ans);
	}
	return 0; 
}
