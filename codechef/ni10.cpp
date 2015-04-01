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
ll dist(int x1,int y1,int x2,int y2)
{
	return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}
int main()
{
	int t;
	ll dp[2505];
	bool visited[2505];
	pair<int,int> point[2505];
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			point[i+1].first=x;
			point[i+1].second=y;
		}
		//dbg("AAA");
		int startX,startY,endX,endY;
		scanf("%d%d%d%d",&point[0].first,&point[0].second,&point[n+1].first,&point[n+1].second);
		sort(point+1,point+n+1);
		for(int i=0;i<n+2;i++)
			dp[i]=INT_MAX,visited[i]=false;
		int at=0;
		dp[0]=0;
		int count=0,currX=point[0].first,currY=point[0].second,index=0;
		while(count<n+2)
		{
			visited[index]=true;
			currX=point[index].first;
			currY=point[index].second;
			for(int i=0;i<n+2;i++)
			{
				if(dp[index]+dist(currX,currY,point[i].first,point[i].second)<dp[i])
					dp[i]=dp[index]+dist(currX,currY,point[i].first,point[i].second);
			}
			int min=INT_MAX;
			for(int i=0;i<n+2;i++)
				if(!visited[i]&&dp[i]<min)
				{
					min=dp[i];
					index=i;
				}
			count++;
		}
			printf("%lld\n",dp[n+1]);
	}

	return 0;
}
