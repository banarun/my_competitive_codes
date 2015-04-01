#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int id;
	int p1[7],p2[7];
	cin>>id;
	int m1,m2;
	cin>>m1;
	for(int i=0;i<6;i++){
		cin>>p1[i];
	}
	cin>>m2;
	for(int i=0;i<6;i++){
		cin>>p2[i];
	}
	
	if(id==1){
		for(int i=4;i>=0;i--){
			if(p1[i]==1 && p1[i+1]==0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		for(int i=5;i>=0;i--){
			if(p1[i]-6+i==0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		for(int i=1;i<6;i++){
			if(p1[i]>6){
				cout<<i+1<<endl;
			}
		}
		for(int i=5;i>=0;i--){
			if(p1[i]-6+i<0 && p1[i]>0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		
		
		for(int i=5;i>=0;i--){
			if(p1[i]==0){
				int j=i-1;
				for(int tp=j;tp>=0;tp--){
					if(p1[tp]>0){
						cout<<tp+1<<endl;
						return 0;
					}
				}
			}
		}
		
		
		int min=100,minind=0;
		int coun=0;
		for(int i=2;i<6;i++){
			if(p1[i]>0 && p1[i]<min){
				min=p1[i];
				minind=i+1;
			}
			if(p1[i]==0)
				coun++;
		}
		
		if(minind>0 && coun<=2){
			cout<<minind<<endl;
			return 0;
		}
		
		for(int i=0;i<6;i++){
			if(p1[i]>0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		
	}
	else{
		for(int i=5;i>=0;i--){
			if(p2[i]==1 && p2[i+1]==0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		
		for(int i=5;i>=0;i--){
			if(p2[i]-6+i==0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		
		for(int i=1;i<6;i++){
			if(p2[i]>6){
				cout<<i+1<<endl;
			}
		}
		for(int i=5;i>=0;i--){
			if(p2[i]-6+i<0 && p2[i]>0){
				cout<<i+1<<endl;
				return 0;
			}
		}
		
		for(int i=5;i>=0;i--){
			if(p2[i]==0){
				int j=i-1;
				for(int tp=j;tp>=0;tp--){
					if(p2[tp]>0){
						cout<<tp+1<<endl;
						return 0;
					}
				}
			}
		}
		
		int min=100,minind=0,coun=0;
		for(int i=2;i<6;i++){
			if(p2[i]>0 && p2[i]<min){
				min=p1[i];
				minind=i+1;
			}
			if(p2[i]==0)
				coun++;
		}
		
		
		if(minind>0 && coun<=2){
			cout<<minind<<endl;
			return 0;
		}
		
		for(int i=0;i<6;i++){
			if(p2[i]>0){
				cout<<i+1<<endl;
				return 0;
			}
		}
	}
}
