#include <iostream>
#include <string>
#include <climits>
#include <set>
using namespace std;

int a[100000][4];
unsigned long long int arr[100000];
int main()
{
	int n,k;
	cin>>n;
	cin>>k;
	int g;
	string s[100000];
	
	for(int i=0;i<n;i++){
		cin>>s[i];
		int len=s[i].length();
		int p=0,j=0;
		while(p<len){
			while( p < len && s[i][p] >= '0' && s[i][p] <= '9'){	
				a[i][j]=a[i][j]*10 + s[i][p]-'0';
				p++;
			}
			if(p>=len)
				break;
			else
				p++;
			j++;
		}
	}
	
	for(int i=0;i<n;i++){
		arr[i]=a[i][0]*16777216+a[i][1]*65536+a[i][2]*256+a[i][3];
		//cout<<arr[i]<<endl;
	}
	unsigned long int sub=2147483648,pr=2147483648/2;
	int flag=0;
	int count=0;
	while(pr>1){
		count++;	
		set<unsigned long long int> s; 
		set<unsigned long long int>::iterator it;
		for(int i=0;i<n;i++){
			s.insert(arr[i] & sub);
		}
		if(s.size()==k){
			flag=1;
			break;
		}
		else{
			sub=sub+pr;
			pr=pr/2;
		}
	}
	if(flag==0)
		cout<<-1<<endl;
	else{
		cout<<sub/16777216<<".";
		sub=sub%16777216;
		cout<<sub/65536<<".";
		sub=sub%65536;
		cout<<sub/256<<".";
		sub=sub%256;
		cout<<sub<<endl;
		
	}
	return 0;
}
