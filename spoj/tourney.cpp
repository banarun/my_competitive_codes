#include <cstdio>
#include <cmath>
#include <climits>
#include <iostream>
using namespace std;

#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;

int arr[1100000];
int st[2200000];
#define ll long long
inline int inp()
{
	ll r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

int construct(int ss, int se, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = (ss+se)/2;
    st[si] =  max(construct(ss, mid, si*2),
                     construct(mid+1, se, si*2+1));
    return st[si];
}
 
 
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int p=(1<<n);
	int mval=INT_MIN;
	int indx=0;
	for(int i=1;i<=p;i++){
		arr[i]=inp();	
	}

	construct(1,p,1);
	for(int i=0;i<m;i++){
		char c;
		for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
		if(c=='R'){
			int a,b;
			a=inp();
			b=inp();
			arr[a]=b;
			int ptr=(p-1)+a;
			st[ptr]=b;
			ptr=ptr/2;
			while(ptr>0){
				if(st[ptr]==max(st[ptr*2+1],st[ptr*2]))
					break;
				else
					st[ptr]=max(st[ptr*2+1],st[ptr*2]);
				ptr/=2;
			}
			
		}
		else if(c=='S'){
			int a,b,count=0;
			//scanf("%d",&a);
			a=inp();
			b=p+a-1;
			while(arr[a]==st[b]){
				b=b/2;
				count++;
			}
			printf("%d\n",count-1);
		}
		else{
			int a=1;
			while(a<p){
				if(st[2*a+1]==st[a]){
					a=2*a+1;
				}
				else
					a=2*a;
			}
			printf("%d\n",a-(p-1));
		}
	}   
	return 0;
}
