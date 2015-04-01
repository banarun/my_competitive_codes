#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <cstring> 
#include <ctime> 
#include <cctype>
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
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iomanip> 
using namespace std; 
#ifdef DEBUG
	#define dbg(args...) { cerr<<#args<<": "; dbgr,args; cerr<<endl;}
#else
	#define dbg(args...)
#endif
struct debugger{template<typename T> debugger& operator , (const T& v){cerr<<v<<" "; return *this; }}dbgr;

#define ll long long 
#define ull unsigned long long 
typedef pair<ll,ll> lpair;
#define mp(A,B) make_pair(A,B)
#define pb(X) push_back(X)
#define ln length()
#define sz size()
#define mod 1000000007
#define N 100002


int main()
{
    int t,n,k,i,n1,j;
    scanf("%d",&t);
    while(t--)
    {
		string s,r;
        scanf("%d%d",&n,&k);
        j=0;
        char c[10];
		int pt=0;
		s="";
        for(i=1;i<=n;i++)
        {
            n1=i;
            pt=0;
            while(n1!=0)
            {
                c[pt]=n1%10+'0';
                n1/=10;
                pt++;
            }
           
            for(j=pt-1;j>=0;j--)
				s.pb(c[j]);
        }
        
		n1=k;
		pt=0;
		while(n1!=0)
		{
			
			c[pt]=n1%10+'0';
			n1/=10;
			pt++;
		}

		for(j=pt-1;j>=0;j--)
			r.pb(c[j]);
		//cout<<s<<" "<<r<<endl;
        int ans=0,ptr=0;
        while(1){	
            int k=s.find(r,ptr);
            if(k<0)
                break;
            ptr=k+1;
            ans++;
        }
        printf("%d\n",ans);
    }

}
