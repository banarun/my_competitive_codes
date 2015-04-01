#include <iostream>
#include <set>
#include <string>
#include <climits>
using namespace std;

int main()
{
	int t,j=0;
	cin>>t;
	while(t--){
		j++;
		int ran[10000]={0};
		long long int num;
		cin>>num;
		long long int d[1001],n[1001],w[1001],e[1001],s[1001],deld[1001],delp[1001],dels[1001];
		for(int i=0;i<num;i++){
			cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>deld[i]>>delp[i]>>dels[i];
		}
		
		long long int count=0,min=0,tmin=INT_MAX,tind=-1,maxdel=0,maxday=0;

		for(int i=0;i<num;i++){
			if(maxdel<deld[i])
				maxdel=deld[i];
			if(maxday<n[i])
				maxday=d[i];
			if(d[i]>=min && d[i]<=tmin){
				tind=i;
				tmin=d[i];
			}
		}
		int i;
		cout<<maxdel<<" "<<maxday<<endl;
		for(int day=0;day<=10*maxdel+maxday;day++){
			for(i=0;i<num;i++){
				if(d[i]==day){
					for(int p=w[i];p<=e[i];p++)
					if(ran[5000+p]<s[i]){
						count++;
						ran[5000+p]=s[i];
						break;
					}
					w[i]+=delp[i];
					e[i]+=delp[i];
					s[i]=s[i]-dels[i];
					min=d[i];
					d[i]+=deld[i];
					n[i]--;
				}
			}
		}
			
		cout<<"Case #"<<j<<": "<<count<<endl;	
	}
	return 0;
}
