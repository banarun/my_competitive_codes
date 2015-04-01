#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){
	int i,i2,j,t,p1,p2,flag1,flag;
	ifstream fin;
	ofstream fout;
	fin.open("new.txt");
	fout.open("fout.txt");
	string s;
	fin>>t;
	string as;
	getline(fin,as);
	int count1=0,count2=0,count3,count4;
	for(j=0;j<t;j++){
		i=0;
		i2=0;
		getline(fin,s);
		flag=1;
		
		while(1){
			p2=s.find(")",i);
			i=p2+1;
			
			cout<<p2;
			if(p2==-1)
			break;
			
			if(s[p2-1]!=':'){
				p1=s.find("(",i2);	
				if(p1==-1){
					flag=0;
					break;
				}		
				if(p1<p2){}
				else
					flag=0;
				i2=p1+1;
			}
		}
		flag1=1;
		cout<<endl;
		i=0;
		while(1){
			p2=s.find("(",i);
			i=p2+1;
			cout<<p2<<" ";
			if(p2==-1)
			break;
			
			else if(s[p2-1]!=':'){
			
				p1=s.find(")",i);
				if(p1==-1){
					flag1=0;
					break;
				}
			}
		}
		
		cout<<flag<<" "<<flag1<<endl;
		if(j!=t-1){
			if(flag==1&&flag1==1)
				fout<<"Case #"<<j+1<<": YES"<<endl;
			else
				fout<<"Case #"<<j+1<<": NO"<<endl;
		}
		else{
			if(flag==1&&flag1==1)
				fout<<"Case #"<<j+1<<": YES";
			else
				fout<<"Case #"<<j+1<<": NO";
		}
		}
			
	}
	return 0;
}
