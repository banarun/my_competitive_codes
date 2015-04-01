#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n,k;
	int p;
	string s;
	cin>>n>>k;
	if(k==1){
	if(n==1){
		cout<<"a";
		return 0;
	}
	else{
		cout<<-1;
		return 0;
	}
	}
	
	if(n<k){
	cout<<-1;
	return 0;
	}
	else if(n==k){
		for(int i=0;i<n;i++)
			s.push_back('a'+i);
	}
	else{
		p=n-k;
		if(k>2){
				for(int i=0;i<p/2;i++){
					s.push_back('a');
					s.push_back('b');
				}
				s.push_back('a');
				s.push_back('b');
	
				if(p%2==1)
					s.push_back('a');
					
				for(int i=2;i<k;i++){
					s.push_back('a'+i);
				}	
		}
		else if(k==2){
			for(int i=0;i<n/2;i++){
				s.push_back('a');
				s.push_back('b');
			}
			if(p%2==1)
				s.push_back('a');
		}
	}
	cout<<s;
	return 0;
}
