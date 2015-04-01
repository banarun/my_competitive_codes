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
#define N 100002
int ht[26];
int main()
{
	vector<string> mp[11];
	vector<string>::iterator it,it2;
	map<string, string> smap;
	map<string, string>::iterator itr; 
	string s;
	char ch[20],chr;
	int nt=0;
	string ans[20000];
	while((chr=getchar_unlocked())>0){
		if(chr=='\n'){
			ch[nt]='\0';
			s=ch;
			int n=s.length();
			mp[n].push_back(s);
			nt=0;
			continue;
		}
		//cout<<chr<<endl;
		ch[nt]=chr;
		nt++;
	}
	int ptr=0;
	for(int i=1;i<=10;i++){
		for(it=mp[i].begin();it!=mp[i].end();it++){
			//if(it->second==1)
			{
				int f1=0;
				for(int j=i+1;j<=10;j++){
					for(it2=mp[j].begin();it2!=mp[j].end();it2++){
						string s1,s2;
						s1=*it;
						s2=*it2;
						
						for(int p1=0;p1<s1.length();p1++){
							ht[s1[p1]-'a']++;
						}
						for(int p1=0;p1<s2.length();p1++){
							ht[s2[p1]-'a']--;
						}
						int f=0;
						for(int i=0;i<26;i++){
							if(ht[i]>0){
								f=1;
							}
							ht[i]=0;
						}
						if(f==0)
							f1=1;
					}
				}
				if(f1==0){
					ans[ptr]=*it;
					ptr++;
				}
			}
		}
	}
	
	sort(ans,ans+ptr);
	for(int i=0;i<ptr;i++){
		const char *ch1=(ans[i]).c_str();
		printf("%s",ch1);
		putchar_unlocked('\n');
	}
	return 0;
}
