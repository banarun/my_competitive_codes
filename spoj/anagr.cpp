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
int a[26];
char ans[200];

int main()
{
	int t;
	string s1,s2;
	scanf("%d",&t);
	getline(cin,s1);
	while(t--){
		for(int i=0;i<26;i++)
			a[i]=0;
		getline(cin,s1);
		getline(cin,s2);
		int n1=s1.ln;
		for(int i=0;i<n1;i++){
			if(s1[i]>='a' && s1[i]<='z')
				a[s1[i]-'a']++;
			if(s1[i]>='A' && s1[i]<='Z')
				a[s1[i]-'A']++;
		}
		int n=s2.ln;
		for(int i=0;i<n;i++){
			if(s2[i]>='a' && s2[i]<='z')
				a[s2[i]-'a']--;
			if(s2[i]>='A' && s2[i]<='Z')
				a[s2[i]-'A']--;
		}
		n=26;
		int f=0,f1=0,len=0;
		for(int i=0;i<26;i++){
			if(a[i]<0){
				f++;
			}
			if(a[i]>0){
				f1++;
			}
			a[i]=abs(a[i]);
			len+=a[i];
		}
//		cout<<len<<" "<<f<<" "<<f1<<endl;
		if(f && f1){
			printf("NO LUCK\n");
			continue;
		}
		else if (!f && !f1){
			printf("YES\n");
			continue;
		}
		else{
			int flg=0,mid=0;
			for(int i=0;i<26;i++){
				if(abs(a[i])%2==1){
					flg++;
					mid=i;
				}
			}
			if(flg>1){
				printf("NO LUCK\n");
				continue;				
			}
			int ptr1=0,ptr2=len-1;
			for(int i=0;i<26;i++){
				for(int j=0;j<a[i]/2;j++){
					ans[ptr1]='a'+i;
					ans[ptr2]='a'+i;
					ptr1++;
					ptr2--;
				}
			}
			if(len%2){
				ans[ptr1]=mid+'a';
			}
			for(int i=0;i<len;i++)
				printf("%c",ans[i]);
			putchar_unlocked('\n');
		}
	}
	return 0;
}
