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
int main()
{
	string s1[2<<10],s2[2<<10];
	s1[0]=" /\\ ";
	s1[1]= "/__\\";
	int spc=2;
	int hgt=2;
	int n=0;
	while(cin>>n && n){
		if(n==1){
			printf(" /\\\n/__\\\n");
			continue;
		} 
		n=n-2;
		spc=2;
		hgt=2;
		s1[0]=" /\\ ";
		s1[1]= "/__\\";
		for(int k=0;k<n;k++){
			for(int j=0;j<hgt;j++){
				s2[j]="";
				for(int i=0;i<spc;i++){
					s2[j].pb(' ');
					//putchar_unlocked(' ');
				}
				//cout<<s1[j];
				s2[j]+=s1[j];
				for(int i=0;i<spc;i++){
					s2[j].pb(' ');
					//putchar_unlocked(' ');
				}
				//putchar_unlocked('\n');
			}
			for(int j=0;j<hgt;j++){
				s2[hgt+j]=s1[j]+s1[j];
				//cout<<s1[j]<<s1[j];
				//putchar_unlocked('\n');
			}
			spc=(spc<<1);
			hgt=spc;
			for(int i=0;i<hgt;i++)
				s1[i]=s2[i];
		}
		for(int j=0;j<hgt;j++){
			for(int i=0;i<spc;i++){
				putchar_unlocked(' ');
			}
			cout<<s1[j];
			for(int i=0;i<spc;i++){
				putchar_unlocked(' ');
			}
			putchar_unlocked('\n');
		}
		for(int j=0;j<hgt;j++){
			const char *str=s1[j].c_str();
			printf("%s%s",str,str);
			putchar_unlocked('\n');
		}	
	}
	return 0;
}
