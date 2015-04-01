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
#include <fstream>
using namespace std; 

#define ll long long 
#define ull unsigned long long 
#define mod 1000000007 
#define N 100000 

int main() 
{
	ifstream fin;
	ofstream fout;
	fin.open("circles.in");
	fout.open("circles.out");
	ll int  n,len,dis;
	int d[1002];
	double p[1002];
	fin>>dis
	fin>>n>>len>>dis;
	for(int i=0;i<n;i++){
		fin>>p[i];
	}
	double dp[1001];
	for(int i=0;i<n;i++){
		fin>>d[i];
		dp[i]=0;
	}
	dp[n]=0;
	p[n]=1;
	d[n]=dis;
	
	if(d[0]<=len)
	dp[0]=p[0];
	else{
		fout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(d[i]<=len)
			dp[i]=p[i];
		for(int j=0;j<i;j++){
			if(d[i]-d[j]<=len)
			dp[i]=max(dp[i],dp[j]*p[i]);
		}
	}
	if(dp[n]>0){
		
	}
	else{
		fout<<0;;
	}
	return 0; 
}
