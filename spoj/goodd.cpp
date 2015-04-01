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
	#define inp(X) scanf("%d",&X)
	#define mod 1000000007 
	#define N 1000002
	string s[N];
	int htable[N];
	bool visited[N];
	ll val1[N];
	int pathstart[N];
	int path[N];
	int cval=0;
	int pptr=0;
	int main()
	{
		int n;
		ll M;
		scanf("%d%lld",&n,&M);
		getline(cin, s[0]);
		for(int i=1;i<=n;i++){
			val1[i]=LLONG_MAX; 
			char cha[100];
			getline(cin,s[i]);
			int j=0;
			int idx=0;
			while(s[i][j]>='0' && s[i][j]<='9'){
				idx=idx*10+s[i][j]-'0';
				j++;
			}
			htable[idx]=i;
		}
		int ptr=0;
		ll c=0;
		int f=0;
		for(ptr=1;ptr<=n;ptr++){
			//cout<<ptr<<" "<<s[ptr]<<endl;
			if(s[ptr][0]=='c'){
				c++;
				if(c==M){
					printf("%d\n",ptr);
					return 0;
				}
				if(!visited[ptr]){
					val1[ptr]=c;
					visited[ptr]=true;
					pathstart[ptr]=pptr;
					path[pptr]=ptr;
					pptr++;
				}
				else{
					cval=c;
					f=1;
					break;
				}
			}
			
			else if(s[ptr][0]=='g'){
				if(!visited[ptr]){
					val1[ptr]=c;
					visited[ptr]=true;
				}
				else{
					cval=c;
					f=1;
					break;
				}

				int idx=0,j=5;
				while(s[ptr][j]>='0' && s[ptr][j]<='9'){
					idx=idx*10+s[ptr][j]-'0';
					j++;
				}
				ptr=htable[idx];
			}
		}
		if(f==1){
			if(cval==val1[ptr]){
				printf("TLE\n");
			}
			else{
				ll dif=cval-val1[ptr];
				for(int i=pathstart[ptr];i<pptr;i++){
					if((M-val1[path[i]])%dif==0){
						printf("%d\n",path[i]);
						return 0;
					}
				}
				printf("TLE\n");
			}
		}
		else{
			printf("WA\n");
		}
		return 0;
	}
