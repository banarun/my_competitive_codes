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

ll sum[11][1001];
int vis[1001];
int n,k,g,rightpos;
ll sright;
ll a[1001],arr[1001];
int flg=0;
int ans1[1001];
int ans2[1001];
int ans[30];
int vist[1001];
void fun(ll start,ll sgiv,ll sleft,int p)
{
	if(flg==1)
		return;
	for(int i=1;i<p;i++){
		if(start-i>=0){
			sgiv=sgiv-a[start]+a[start-i];
			ans1[start]=0;
			ans1[start-i]=1;
			if(sgiv>a[start]){
				sleft=sleft-a[start-i]+a[start];
				ans2[start-i]=0;
				ans2[start]=1;
				if(sleft+sright>a[rightpos]){
					cout<<"Yes\n";
					int b=0;
					for(int i=0;i<n;i++){
						if(ans1[i]==1)
							ans[b++]=i;
					}
					
					for(int i=0;i<n;i++){
						if(ans2[i]==1)
							ans[b++]=i;
					}
					
					for(int i=0;i<b;i++){
						for(int j=0;j<n;j++){
							if(vist[j]==0 && arr[j]==a[ans[i]]){
								vist[j]=1;
								cout<<j+1<<" ";
								break;
							}
						}
					}
					flg=1;
					return;
				}
				fun(start-i,sgiv,sleft,i);
				sgiv=sgiv+a[start]-a[start-i];
				sleft=sleft-a[start]+a[start-i];
				ans1[start]=1;
				ans1[start-i]=0;
				ans2[start-i]=1;
				ans2[start]=1;
			}
			else{
				break;
			}
		}
		else{
			break;
		}
	}
	return;
	
}
int main() 
{ 
		
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		arr[i]=a[i];
	}
	
	sort(a,a+n);
	ll s=0;
	for(int j=1;j<=k;j++){
		for(int i=0;i<n-j+1;i++){
			s=0;
			for(int p=i;p<i+j;p++){
				s=s+a[p];
			}
			sum[j][j+i-1]=s;
		}
	}
	
	int pos[1001];
	int c=0;
	for(int i=k-1;i<n-1;i++){
		if(sum[k-1][i]>a[i+1]){
			pos[c]=i+1;
			c++;
		}
	}
	
	if(c<=1){
		cout<<"No\n";
		return 0;
	}
	else{
		int d=0;
		int pos2[3];
		for(int i=k-2;i<n-1;){
			if(sum[k-1][i]>a[i+1]){
				pos2[d]=i+2-k;
				d++;
				i=i+k;
				if(d==2){
					break;
				}
			}
			else
				i++;
		}
		if(d==2){
			cout<<"Yes\n";
			for(int i=0;i<k;i++){
				for(int j=0;j<n;j++){
					if(vis[j]==0 && arr[j]==a[pos2[0]+i]){
						cout<<j+1<<" ";
						vis[j]=1;
						break;
					}
				}
			}
			for(int i=0;i<k;i++){
				for(int j=0;j<n;j++){
					if(vis[j]==0 && arr[j]==a[pos2[1]+i]){
						cout<<j+1<<" ";
						vis[j]=1;
						break;
					}
				}
			}
			return 0;
		}
		for(int i=0;i<c;i++){
			for(int j=i+1;j<c;j++){
				if(flg==1)
					return 0;
					
				g=pos[j]-pos[i];
				rightpos=pos[j];
				int leftpos=pos[i]-k+1;
				if(g<=1)
					continue;

				sright=sum[g-1][pos[j]-1];
				
				if(leftpos>=k-g){
					for(int q=leftpos;q<=pos[i];q++)
						ans1[q]=1;
					for(int q=pos[i]+1;q<=pos[j];q++)
						ans2[q]=1;
					for(int q=leftpos-k+g;q<leftpos;q++)
						ans2[q]=1;
						
					ll sleft=sum[k-g][leftpos-1];
					if(sleft+sright<=a[pos[j]])
						fun(leftpos,sum[k-1][pos[i]-1],sum[k-g][leftpos-1],k);
					else{
						cout<<"Yes\n";
						int b=0;
						for(int i=0;i<n;i++){
							if(ans1[i]==1){
								ans[b++]=i;
							}
						}
						
						for(int i=0;i<n;i++){
							if(ans2[i]==1){
								ans[b++]=i;
							}
						}
						
						for(int i=0;i<b;i++){
							for(int j=0;j<n;j++){
								if(vist[j]==0 && arr[j]==a[ans[i]]){
									vist[j]=1;
									cout<<j+1<<" ";
									break;
								}
							}
						}
						return 0;
					}
					for(int m=0;m<n;m++){
						ans1[m]=0;
						ans2[m]=0;
					}
					
				}
			}
		}	
	}
	cout<<"No\n";
	return 0; 
}
