#include <iostream>
#include <set>
#include <list>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

int count=0,counter=0;
int grap[3001][3001];
list<int>::iterator it;
int d[3001];
int low[3001];
int parent[3001];
int color[3001];
int p[3001];
set<int> s;
int n;
inline int inp( )
{
	int n=0;
	int ch=getchar_unlocked();
	while( ch >47 )
	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}
inline void artic(int i)
{
	color[i]=1;
	d[i]= ++counter;
	low[i]= d[i];
	for(int g=0;g<p[i];g++){
		int j=grap[i][g];
		if(color[j]==0){
			parent[j]=i;
			artic(j);
			low[i]=min(low[i],low[j]);
			
			if(low[j]>=d[i]){
				s.insert(i);
			}
		}
		else if((j)!=parent[i]){
				low[i]=min(low[i],d[j]);
		}
	}
}


int main()
{
	int t;
	t=inp( );
	while(t--){
		int e,k;
		n=inp( );
		e=inp( );
		k=inp( );
		int a,b;
		
		s.clear();
		count=0;
		counter=0;
		for(int i=0;i<n;i++){
			p[i]=0;
			for(int j=0;j<n;j++)
				grap[i][j]=0;
		}
		for(int i=0;i<e;i++){
			a=inp();
			b=inp();
				grap[a][p[a]]=b;
				grap[b][p[b]]=a;
			p[a]++;
			p[b]++;
		}
		if(n==2){
			printf("0\n");
			continue;
		}
		int m=0;
		int indx=0;
		for(int i=0;i<n;i++){
			d[i]=-1;
			if(m<p[i]){
				m=p[i];
				indx=i;
			}
			color[i]=0;
			parent[i]=-1;
			low[i]=-10;
		}
		counter=0;
		parent[indx]=10000;
		artic(indx);
		count=s.size();
		for(int i=0;i<n;i++){
			d[i]=-1;
			parent[i]=-1;
			color[i]=0;
			low[i]=-10;
		}
		counter=0;
		s.clear();
		if(indx==0)
			artic(1);
		else
			artic(0);
		
		if(s.find(indx)!=s.end())
			printf("%d\n",k*count);
		else
			printf("%d\n",(k)*(count-1));
	}
	return 0;
}
