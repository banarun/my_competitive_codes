#include <iostream>
#include <cstdio>
#include <string>
#include <cstdlib>
using namespace std;
 
int hon[500];
int ans[500];
int main()
{
    int t;
    scanf("%d",&t);
    int n,h;
    int count=0;
    long long int ge,ma=0;
    scanf("%d%d",&n,&h);
    char s[15];
    char *st[5];
    char str[200][15];
    for(int i=8;i<=12;i++){
		st[i-8]=new char[i+1];
        for(int j=0;j<i;j++){
			st[i-8][j]='a'+rand()%26;
		}
		st[i-8][i]='\0';
    }
    
    for(int j=0;j<n;j++){
		for(int p=0;p<8;p++){
			str[j][p]='a'+rand()%26;
		}
		str[j][8]='\0';
		printf("%s\n",str[j]);
	}
	cout<<endl;
	scanf("%llu",&ge);
	count++;
	long long int val=ge;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i==j){
				for(int p=0;p<8;p++){
					s[p]='a'+rand()%26;
				}
			s[8]='\0';
			printf("%s\n",s);
			}
			else
				printf("%s\n",str[j]);
		}
		cout<<endl;
		scanf("%llu",&ge);
		count++;
		if(count==t){
			return 0;
		}
		if(val==ge){
			hon[i]++;
		}
	}
    int len=8;
    int k,p=0,indx=0;
    for(int p=0;p<n;p++){
		if(hon[p]==0){
			for(k=1;k<=4;k++){
				
				for(int i=0;i<n;i++){
					if(i<p && hon[i]==0){
						for(int q=0;q<7;q++){
							st[ans[p]][q]='a'+rand()%26;
						}
						printf("%s\n",st[ans[p]]);
					}
					else if(i==p && hon[p]==0 ){
						for(int q=0;q<7;q++){
							st[k][q]='a'+rand()%26;
						}
						printf("%s\n",st[k]);
					}
					else{
						for(int q=0;q<7;q++){
							str[i][q]='a'+rand()%26;
						}
						printf("%s\n",str[i]);
					}
				}
				cout<<endl;
				scanf("%llu",&ge);
				count++;
				if(count==t)
					break;
				if(ge>val){
					val=ge;
					ans[p]=k;
				}
			}
        
		}
		if(count==t)
			break;
	}	
	//cout<<"A\n";
	if(count==t)
	return 0;
	else{
		t=t-count;
		for(int i=0;i<t;i++){
			for(int j=0;j<n;j++){
				for(int q=0;q<7;q++){
					str[0][q]='a'+rand()%26;
				}
				printf("%s\n",str[0]);
			}
			cout<<endl;
			scanf("%llu",&ge);
		}
	}
	return 0;
}
 
