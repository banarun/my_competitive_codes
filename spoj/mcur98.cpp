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
#define N 1000001
int a[N+10]; 
int main() 
{
	for(int i=1;i<1000010;i++){
		int p=i,k=0;
		while(p>0){
			k+=p%10;
			p=p/10;
		}
		if(k+i>N)
			continue;
		a[k+i]=1;
	}
	for(int i=1;i<N-1;i++)
	{
		if(a[i]==0){
			printf("%d",i);
			putchar_unlocked('\n');
		}
	}
	return 0; 
}
