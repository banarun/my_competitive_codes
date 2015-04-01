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
#define N 100003 
 
inline int inp( )
{
	int n=0;
	int ch=getchar_unlocked();
	while( ch >47 )
	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}
bool dif[7001][N];
bool dif2[6001][N];
int main() 
{ 
	clock_t start = clock();
	int n;
	int arr[N];
	n=inp();
	for(int i=0;i<n;i++){
		arr[i]=inp();
	}
	sort(arr,arr+n);
	
	if(n<3){
		cout<<n<<endl;
		for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	}
	else{
		int p=n;
		int ans[N];
		int m2=2;
		int m=2;
		int ans2[N];
		m=2;
		ans[0]=arr[0];
		ans[1]=arr[1];
		dif[1][arr[1]-arr[0]]++;
		
		for(int i=2;i<n;i++){
			int f=0;
			for(int j=1;j<m;j++){
				int d=arr[i]-ans[j];
				if(j<7000 && j<m-1){
					if(dif[j][d]){
						f=1;
						break;
					}
					continue;
				}
				for(int k=0;k<j;k++){
					int r=ans[j]-ans[k];
					if(j<7000)
					dif[j][r]=true;
					if(r==d){
						f=1;
						break;
					}
					else if(d>r){
						break;
					}
				}
				if(f==1){
					break;
				}
			}
			if(f==0){
				ans[m]=arr[i];
				m++;
			}
			if(clock()-start >= (1.000-0.016) * CLOCKS_PER_SEC)break;
		}
		ans2[0]=arr[n-1];
		ans2[1]=arr[n-2];
		for(int i=n-3;i>=0;i--){
			if(clock()-start >= (1.000-0.016) * CLOCKS_PER_SEC)break;
			int f=0;
			for(int j=0;j<m2;j++){
				int d=arr[i]-ans2[j];
				
				if(j<6000 && j<m2-1){
					if(dif2[j][d]){
						f=1;
						break;
					}
					continue;
				}
				for(int k=0;k<j;k++){
					int r=ans2[j]-ans2[k];
					if(r==d){
						f=1;
						break;
					}
					if(j<6000)
					dif2[j][r]++;
					else if(d<r){
						break;
					}
				}
				if(f==1){
					break;
				}
			}
			if(f==0){
				ans2[m2]=arr[i];
				m2++;
			}
			if(clock()-start >= (1.000-0.015) * CLOCKS_PER_SEC)break;
		}
		
		
		if(m>m2){
			printf("%d\n",m);
			for(int i=0;i<m;i++){
				printf("%d ",ans[i]);
			}
		}
		else{
			printf("%d\n",m2);
			for(int i=0;i<m2;i++){
				printf("%d ",ans2[i]);
			}
		}
	}
	return 0; 
}
