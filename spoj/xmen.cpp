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
ll inp(){ll r=0;int c;for(c=getchar_unlocked();c<=32;c=getchar_unlocked());for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());return r;}
int hash[N];
int a[N],b[N];


int CeilIndex(int A[], int l, int r, int key) {
    int m;
 
    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m; // ternary expression returns an l-value
    }
 
    return r;
}
 
int lis(int A[], int size) {
 
    int *tailTable   = new int[size];
    int len; 
 
    memset(tailTable, 0, sizeof(tailTable[0])*size);
 
    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )
            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )
            tailTable[len++] = A[i];
        else{
			int *p=upper_bound(tailTable,tailTable+len,A[i]);
            *p=A[i];
            //tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
		}
    }
 
    delete[] tailTable;
 
    return len;
}

int main()
{
	int t;
	t=inp();
	while(t--){
		int n=inp();
		for(int i=1;i<=n;i++){
			a[i]=inp();
			hash[a[i]]=i;
		}
		for(int i=1;i<=n;i++)
			b[i]=inp();
		for(int i=0;i<n;i++){
			a[i]=hash[b[i+1]];
		}
		printf("%d\n",lis(a,n));
	}
	return 0;
}
