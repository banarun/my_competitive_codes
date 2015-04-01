#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
vector<int>::iterator it;
		
int main(){
	
	int sum,i,j,t,n;
	ifstream fin;
	ofstream fout;
	fin.open("in.txt");
	fout.open("out.txt");
	string s;
	fin>>t;
	string as;
	a.resize(26);
	getline(fin,as);
	
	for(j=0;j<t;j++){
		
		getline(fin,s);
		n=s.length();	
		for(i=0;i<26;i++)
			a[i]=0;
		
		for(i=0;i<n;i++){
			if(s[i]>= 'a' && s[i]<='z')
				a[s[i]-'a']++;
			else if(s[i]>='A' && s[i]<='Z')
				a[s[i]-'A']++;
		}
		sort(a.begin(),a.end());
		sum=0;
		for(i=25;i>0;i--)
			sum=sum+(i+1)*a[i];
		if(j==t-1)
			fout<<"Case #"<<j+1<<": "<<sum;
		else
			fout<<"Case #"<<j+1<<": "<<sum<<endl;
	}
	return 0;
}
