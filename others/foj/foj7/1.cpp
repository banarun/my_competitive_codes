#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	char s[10];
	int t;
	cin>>t;
	while(t--){
	scanf("%s",s);
	int a,b,pa,pb;
	
	a=(s[0]-'0')*10+(s[1]-'0');
	pa=a;
	pb=pa/10+(pa%10)*10;
	
	b=(s[3]-'0')*10+(s[4]-'0');
	
	if(pb>b && pb<60){
			printf("%02d:%02d\n",pa,pb);
	}
	else{
		int flag=0;
		while(1){
			pa++;
			if(pa>23)
				break;
			pb=pa/10+(pa%10)*10;
			if(pb<60){
				printf("%02d:%02d\n",pa,pb);
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"00:00\n";
	}
	}
	return 0;
}
