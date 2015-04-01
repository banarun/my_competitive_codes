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
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;
#define ll long long 
#define ull unsigned long long
#define mp(A,B) make_pair(A,B) 
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define mod 1000000007 
#define N 100002
int seive[31024];
set<int> factor[31024];
int seg[33050];
int val[33025];
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int gcd(int x,int y)
{
	while(y){
		int temp=y;
		y=x%y;
		x=temp;
	}
	return x;
}
int main()
{
	
	int n=10001;
	for(int i=2;i<=sqrt(n);i++){
		for(int j=i*i;j<=n;j+=i){
			seive[j]=1;
		}
	}
	seive[1]=1;
	factor[1].insert(1);
	for(int i=2;i<n;i++){
		int p=i;
		for(int j=1;j<=sqrt(p);j++){
			if(p%j==0){
				if(seive[j])
					factor[p].insert(j);
				if(seive[p/j])
					factor[p].insert(p/j);
			}
		}
	}
	int q;
	q=inp();
	while(q--){
		int t;
		n=16383;
		t=inp();
		for(int i=0;i<2*n+4;i++){
			seg[i]=0;
			val[i]=0;
		}
		while(t--){
			int b;
			char a[100];
			scanf("%s",a);
			
			if(a[0]=='U'){
				scanf("%s",a);
				
				if(a[0]=='A'){
					b=inp();
					if(val[b]){
						val[b]++;
					}
					else{
						int ptr=n+b,p2;
						val[b]=1;
						seg[n+b]=b;
						while(ptr){
							if(ptr%2)
								p2=ptr-1;
							else
								p2=ptr+1;
							if(seg[p2]){
								seg[ptr/2]=gcd(seg[p2],seg[ptr]);
							}
							else
								seg[ptr/2]=seg[ptr];
							ptr/=2;
						}
					}
				}
				if(a[0]=='R'){
					b=inp();
					if(val[b]>1)
						val[b]--;
					else{
						val[b]=0;
						seg[n+b]=0;
						int ptr=n+b,p2;
						while(ptr){
							if(ptr%2)
								p2=ptr-1;
							else
								p2=ptr+1;
							if(seg[ptr] && seg[p2]){
								seg[ptr/2]=gcd(seg[p2],seg[ptr]);
							}
							else if(seg[p2])
								seg[ptr/2]=seg[p2];
							else
								seg[ptr/2]=seg[ptr];
							ptr/=2;
						}
					}
				}
			}
			if(a[0]=='C'){
				int p=seg[1];
				if(seg[1]==0)
					puts("-1");
				else{
					for(set<int>::iterator it=factor[p].begin();it!=factor[p].end();it++)
						printf("%d ",*it);
					puts("");
				}
			}
			//dbg(seg[1]);
		}
	}
	return 0;
}
