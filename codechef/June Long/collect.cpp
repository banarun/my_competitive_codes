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
#define mod 3046201
#define N 100001 
 

int getMid(int s, int e) {  return s + (e -s)/2;  }

ull int power(ull int x, ull int y)
{
    ull int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return ((x*((temp*temp)%mod))%mod);
}

int inp()
{
    int r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}
 
int getSumUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    
    
    if (qs <= ss && qe >= se)
        return st[index];
 
    
    if (se < qs || ss > qe)
        return 0;
 
    
    int mid = getMid(ss, se);
    return getSumUtil(st, ss, mid, qs, qe, 2*index+1) +
           getSumUtil(st, mid+1, se, qs, qe, 2*index+2);
}
 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int index)
{
    
    if (i < ss || i > se)
        return;
 
    
    
    st[index] = st[index] + diff;
    if (se != ss)
    {
        int mid = getMid(ss, se);
        updateValueUtil(st, ss, mid, i, diff, 2*index + 1);
        updateValueUtil(st, mid+1, se, i, diff, 2*index + 2);
    }
}
 
void updateValue(int arr[], int *st, int n, int i, int new_val)
{
    
    if (i < 0 || i > n-1)
    {
        printf("Invalid Input");
        return;
    }
 
    
    int diff = new_val - arr[i];
 
    
    arr[i] = new_val;
 
    
    updateValueUtil(st, 0, n-1, i, diff, 0);
}
 
int getSum(int *st, int n, int qs, int qe)
{
    return getSumUtil(st, 0, n-1, qs, qe, 0);
    
}
 
int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{    
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }   
    int mid = getMid(ss, se);
    st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) +
              constructSTUtil(arr, mid+1, se, st, si*2+2);
    return st[si];
}
 
int *constructST(int arr[], int n)
{
    
    int x = (int)(ceil(log2(n))); 
    int max_size = 2*(int)power(2, x) - 1; 
    int *st = new int[max_size];
 
    
    constructSTUtil(arr, 0, n-1, st, 0);
 
    
    return st;
}
int arr[N];
ull int fact[N*32];
int main()
{
    int n;
    n=inp();
    for(int i=0;i<n;i++)
		arr[i]=inp();
	fact[0]=1;
	for(int i=1;i<=31*n;i++){
		fact[i]=(fact[i-1]*i)%mod;
	}
    int *st = constructST(arr, n);
	char str[10];
	int q=inp();
	while(q--){
		scanf("%s",str);
		int p,q;
		if(str[0]=='q'){
			p=inp();
			q=inp();
			ll sum=getSum(st, n, p-1,q-1);
			int num=q-p+1;
			if(num==1){
				printf("1\n");
				continue;
			}
			int div=sum/num;
			int fac=sum%num;
			int dif=num-fac;
			ll ans=(((fact[sum]*power(power(fact[div],mod-2),dif))%mod)*((power(power(fact[div+1],mod-2),fac))%mod))%mod;
			ll temp=2;
			temp=(((fact[num]*power(fact[fac],mod-2))%mod)*power(fact[num-fac],mod-2))%mod;
			temp=temp%mod;
			ans=(ans*temp)%mod;
			printf("%lld\n",ans);
		}
		
		else if(str[0]=='c'){
			p=inp();
			q=inp();
			updateValue(arr, st, n, p-1,q);
		}
	}
    return 0;
}
