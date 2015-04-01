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
char a[11][11];
int px[20],py[20];
int b[11][11];
int n,m,num;
int arr1[20],arr2[20];
int ptr1,ptr2;
int c;
int len;
int f;
int k=0;
bool check(int x1,int y1,int x2,int y2)
{
	if((abs(x1-x2)==2 && abs(y1-y2)==1) || (abs(x1-x2)==1 && abs(y1-y2)==2))
		return true;
	return false;
}
void foo(int p,int ply)
{
	if(f)
		return;
	if(ptr1+ptr2==len){
		int flg=0;
		k++;
		for(int i=0;i<ptr1;i++){
			for(int j=0;j<ptr2;j++){
				if(check(px[arr1[i]],py[arr1[i]],px[arr2[j]],py[arr2[j]])){
					flg=1;

					break;
				}
					
			}
			if(flg)
				break;
		}
		if(!flg){
			f=1;
		}
		return;
	}
	int init;
	if(ply && ptr2){
		init=arr2[ptr2-1]+1;
	}
	else if(!ply && ptr1)
		init=arr1[ptr1-1]+1;
	else
		init=0;

	for(int i=init;i<num;i++){
		if(ply && !b[px[i]][py[i]]){
			arr2[ptr2]=i;
			ptr2++;
		}
		else if(!ply && !b[px[i]][py[i]]){
			arr1[ptr1]=i;
			ptr1++;
		}
		else
			continue;
		b[px[i]][py[i]]=1;
		foo(i+1,(ply+1)%2);
		if(ply)
			ptr2--;
		else
			ptr1--;
		b[px[i]][py[i]]=0;
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		num=0;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>a[i][j];
				b[i][j]=0;
				if(a[i][j]=='.'){
					px[num]=i;
					py[num]=j;
					num++;
				}
			}
		}
		//dbg(num);
		int ans=0;
		for(int i=1;i<=num;i++){
			c=0;
			ptr1=0,ptr2=0;
			len=i;
			k=0;
			foo(0,0);
			if(f){
				ans=i;
				f=0;
			}
			
			else
				break;
				
		}
		
		printf("%d\n",ans);
	}
	return 0;
}
