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
#include <stdint.h>
#include <unistd.h>
#include <stdlib.h>
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

struct fastIO
{
	fastIO()
	{
		fread(IN,1,SSS,stdin);
		iptr=IN;
		optr=OUT;
	}
	void check()
	{
		int size=IN+SSS-iptr;
		if(size<200)
		{
			memcpy(IN,iptr,size);
			fread(IN+size,1,SSS-size,stdin);
			iptr=IN;
		}
	}
	void check2()
	{
		int size=OUT+SSS-optr;
		if(size<200)
		{
			fwrite(OUT,optr-OUT,1,stdout);
			optr=OUT;
		}
	}
	
	int sc()
	{
		check();
		while(*iptr<=32) iptr++;
		int x=0;
		while(*iptr>32) x= x*10 + *iptr++ -'0';
		return x;
	}
	
	void pr(int x)
	{
		check2();
		if(x==0)
			*optr++='0';
		else
		{
			int y;
			int top=-1;
			while(x>0)
			{
				y=x/10;
				stk[++top]=x-y*10+'0';
				x=y;
			}
			while(top>=0) *optr++=stk[top--];
		}
		*optr++='\n';
	}
};

int inp(){int r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int main()
{
	int t;
	ll val;
	scanf("%d",&t);
	while(t--){
		multiset<int> s;
		multiset<int>::iterator it,temp;
		int b,n;
		b=inp();
		for(int i=0;i<b;i++){
			n=inp();
			s.insert(n);
			if(s.size()==1){
				it=s.begin();
			}
			else if(*it > n && s.size()%2==0){
				it--;
			}
			else if(*it <= n && s.size()%2==1){
				it++;
			}
			if(i%2==0){
				printf("%d",*it);
				val=0;
			}
			else{
				temp=it;
				temp++;
				val=0LL+(*it)+(*temp);
				printf("%d",val/2);
				
			}
			val%2?puts(".5"):putchar_unlocked('\n');
		}
	}
	return 0;
}

