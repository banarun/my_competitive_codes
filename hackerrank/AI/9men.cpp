#include <iostream>
#include <vector>
using namespace std;


int main() {

    char p,op;
    string move;
    char a[7][7];

    cin >> p;
    if(p=='W'){
		op='B';
	}
	else{
		op='W';
	}
	int n=7;
    cin >> move;
    for(int i=0; i<7; i++) {
		for(int j=0;j<7;j++)
        cin>>a[i][j];
    }
    
    if(move=="MOVE"){
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]==p && (i==j ||i+j==6)){
					if(a[3][j]=='O'){
						if(a[3][j+1]== p && a[3][j+2]==p){
						cout<<i<<" "<<j<<" "<<3<<" "<<j<<endl;
						return 0;
						}
						if(a[3][j+1]== p && a[3][j-1]==p){
						cout<<i<<" "<<j<<" "<<3<<" "<<j<<endl;
						return 0;
						}
						if(a[3][j-1]== p && a[3][j-2]==p){
						cout<<i<<" "<<j<<" "<<3<<" "<<j<<endl;
						return 0;
						}
					}
					if(a[i][3]=='O'){
						
						if(a[i+1][3]== p && a[i+2][3]==p){
						cout<<i<<" "<<j<<" "<<i<<" "<<3<<endl;
						return 0;
						}
						if(a[i+1][3]== p && a[i-1][3]==p){
						cout<<i<<" "<<j<<" "<<i<<" "<<3<<endl;
						return 0;
						}
						if(a[i-1][3]== p && a[i-2][3]==p){
						cout<<i<<" "<<j<<" "<<i<<" "<<3<<endl;
						return 0;
						}
						
					}

					
				}
				else if(a[i][j]==p && (i==3 || j==3)){
					if(i==3){
						if(a[i][j+1]=='O'){
							if(a[i+1][j+1]==p && a[6-i-1][j+1]==p){
							cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
							return 0;
							}
						}
						if(a[i][j-1]=='O'){
							if(a[i-1][j-1]==p && a[6-i+1][j-1]==p){
							cout<<i<<" "<<j<<" "<<i<<" "<<j-1<<endl;
							return 0;
							}
						}
						if(a[j][j]=='O'){
							if(a[j][3]==p && a[j][6-j]==p){
							cout<<i<<" "<<j<<" "<<j<<" "<<j<<endl;
							return 0;
							}
						}
						if(a[6-j][j]=='O'){
							if(a[6-j][3]==p && a[6-j][6-j]==p){
							cout<<i<<" "<<j<<" "<<6-j<<" "<<j<<endl;
							return 0;
							}
						}
						
					}
					if(j==3){
						if(a[i+1][j]=='O'){
							if(a[i+1][j+1]==p && a[i+1][6-j-1]==p){
							cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
							return 0;
							}
						}
						if(a[i-1][j]=='O'){
							if(a[i-1][j-1]==p && a[i-1][6-j+1]==p){
							cout<<i<<" "<<j<<" "<<i-1<<" "<<j<<endl;
							return 0;
							}
						}
						if(a[i][i]=='O'){
							if(a[3][i]==p && a[6-i][i]==p){
							cout<<i<<" "<<j<<" "<<i<<" "<<i<<endl;
							return 0;
							}
						}
						if(a[i][6-i]=='O'){
							if(a[3][6-i]==p && a[6-i][6-i]==p){
							cout<<i<<" "<<j<<" "<<i<<" "<<6-i<<endl;
							return 0;
							}
						}
					}
				}
			}
		}
		
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]==p && (i==j ||i+j==6)){
					if(a[3][j]=='O'){
						cout<<i<<" "<<j<<" "<<3<<" "<<j<<endl;
						return 0;
					}
					if(a[i][3]=='O'){
						
						cout<<i<<" "<<j<<" "<<i<<" "<<3<<endl;
						return 0;
					}
				}
			}
		}
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]==p && (i==3 || j==3)){
					if(i==3){
						if(a[i][j+1]=='O'){
							cout<<i<<" "<<j<<" "<<i<<" "<<j+1<<endl;
							return 0;
						}
						if(a[i][j-1]=='O'){
							cout<<i<<" "<<j<<" "<<i<<" "<<j-1<<endl;
							return 0;
						}
						if(a[j][j]=='O'){
							cout<<i<<" "<<j<<" "<<j<<" "<<j<<endl;
							return 0;
						}
						if(a[6-j][j]=='O'){
							cout<<i<<" "<<j<<" "<<6-j<<" "<<j<<endl;
							return 0;
						}
						
					}
					if(j==3){
						if(a[i+1][j]=='O'){
							cout<<i<<" "<<j<<" "<<i+1<<" "<<j<<endl;
							return 0;
						}
						if(a[i-1][j]=='O'){
							cout<<i<<" "<<j<<" "<<i-1<<" "<<j<<endl;
							return 0;
						}
						if(a[i][i]=='O'){
							cout<<i<<" "<<j<<" "<<i<<" "<<i<<endl;
							return 0;
						}
						if(a[i][6-i]=='O'){
							cout<<i<<" "<<j<<" "<<i<<" "<<6-i<<endl;
							return 0;
						}
					}
				}
			}
		}
	}
	
	if(move=="INIT"){
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]==p && (i==j ||i+j==6)){
					if(a[3][j]==p){
						if(a[6-i][j]=='O'){
							cout<<6-i<<" "<<j<<endl;
							return 0;
						}
					}
					if(a[i][3]==p){
						if(a[i][6-j]=='O'){
							cout<<i<<" "<<6-j<<endl;
							return 0;
						}
					}
					if(a[i][6-j]==p){
						if(a[i][3]=='O'){
							cout<<i<<" "<<3<<endl;
							return 0;
						}
					} 
					if(a[6-i][j]==p){
						if(a[3][j]=='O'){
							cout<<3<<" "<<j<<endl;
							return 0;
						}
					}
				}
				
				else if(a[i][j]==p && (i==3 || j==3)){
					if(i==3){
						if(a[i][j+1]==p || a[i][j+2]==p){
							if(a[i][j+2]=='O'){
								cout<<i<<" "<<j+2<<endl;
								return 0;
							}
							if(a[i][j+1]=='O'){
								cout<<i<<" "<<j+1<<endl;
								return 0;
							}
							if(a[i][j-1]=='O'){
								cout<<i<<" "<<j-1<<endl;
								return 0;
							}
							
							
						}
						if(a[i][j-1]==p || a[i][j-2]==p){
							if(a[i][j+1]=='O'){
								cout<<i<<" "<<j+1<<endl;
								return 0;
							}
							if(a[i][j-1]=='O'){
								cout<<i<<" "<<j-1<<endl;
								return 0;
							}
							if(a[i][j-2]=='O'){
								cout<<i<<" "<<j-2<<endl;
								return 0;
							}
							
						}
						if(a[j][j]==p &&a[6-j][j]=='O'){
							cout<<6-j<<" "<<j<<endl;
							return 0;
						}
						if(a[6-j][j]==p && a[j][j]=='O'){
							cout<<i<<" "<<j<<endl;
							return 0;
						}
						
					}
					if(j==3){
						if(a[i+1][j]==p || a[i+2][j]==p){
							if(a[i+2][j]=='O'){
								cout<<i+2<<" "<<j<<endl;
								return 0;
							}
							if(a[i+1][j]=='O'){
								cout<<i+1<<" "<<j<<endl;
								return 0;
							}
							if(a[i-1][j]=='O'){
								cout<<i-1<<" "<<j<<endl;
								return 0;
							}
							
						}
						if(a[i-1][j]==p || a[i-2][j]==p){
							if(a[i+1][j]=='O'){
								cout<<i+1<<" "<<j<<endl;
								return 0;
							}
							if(a[i-1][j]=='O'){
								cout<<i-1<<" "<<j<<endl;
								return 0;
							}
							if(a[i-2][j]=='O'){
								cout<<i-2<<" "<<j<<endl;
								return 0;
							}
						}
						if((a[i][i]==p) && a[i][6-i]=='O'){
							cout<<i<<" "<<6-i<<endl;
							return 0;
						}
						if((a[i][6-i]==p) &&a[i][i]=='O'){
							cout<<i<<" "<<i<<endl;
							return 0;
						}
					}
				}
			}
		}
		
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]==p && (i==j ||i+j==6)){
					if(a[3][j]==p){
						if(a[6-i][j]=='O'){
							cout<<6-i<<" "<<j<<endl;
							return 0;
						}
					}
					if(a[i][3]==p){
						if(a[i][6-j]=='O'){
							cout<<i<<" "<<6-j<<endl;
							return 0;
						}
					}
				}
				
				else if((a[i][j]==p) && (i==3 || j==3)){
					if(i==3){
						if(a[i][j+1]==p || a[i][j+1]=='O'){
							if(a[i][j+2]=='O'){
								cout<<i<<" "<<j+2<<endl;
								return 0;
							}
							if(a[i][j-1]=='O'){
								cout<<i<<" "<<j-1<<endl;
								return 0;
							}
							
							
						}
						if(a[i][j-1]==p || a[i][j-1]=='O'){
							if(a[i][j+1]=='O'){
								cout<<i<<" "<<j+1<<endl;
								return 0;
							}
							if(a[i][j-2]=='O'){
								cout<<i<<" "<<j-2<<endl;
								return 0;
							}
							
						}
						if(a[j][j]==p &&a[6-j][j]=='O'){
							cout<<6-j<<" "<<j<<endl;
							return 0;
						}
						if(a[6-j][j]==p && a[j][j]=='O'){
							cout<<i<<" "<<j<<endl;
							return 0;
						}
						
					}
					if(j==3){
						if(a[i+1][j]==p || a[i+1][j]=='O'){
							if(a[i+2][j]=='O'){
								cout<<i+2<<" "<<j<<endl;
								return 0;
							}
							if(a[i-1][j]=='O'){
								cout<<i-1<<" "<<j<<endl;
								return 0;
							}
							
						}
						if(a[i-1][j]==p || a[i-1][j]=='O'){
							if(a[i+1][j]=='O'){
								cout<<i+1<<" "<<j<<endl;
								return 0;
							}
							if(a[i-2][j]=='O'){
								cout<<i-2<<" "<<j<<endl;
								return 0;
							}
						}
						if((a[i][i]==p || a[i][i]=='O') && a[i][6-i]=='O'){
							cout<<i<<" "<<6-i<<endl;
							return 0;
						}
						if((a[i][6-i]==p || a[i][6-i]=='O') &&a[i][i]=='O'){
							cout<<i<<" "<<i<<endl;
							return 0;
						}
					}
				}
			}
		}
		for(int i=0;i<7;i++){
			for(int j=0;j<7;j++){
				if(a[i][j]=='O'){
					cout<<i<<" "<<j<<endl;
					return 0;
				}
			}
		}
	}
	
	
    for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){

			if(a[i][j]==op && move=="MILL"){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}
   
    return 0;
}
