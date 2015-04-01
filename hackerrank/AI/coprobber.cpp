#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<vector>
using namespace std;
#define INRANGE(i,a,b) (i>=a && i<b)
int co_ord_distance(int a, int b, int c, int d) {
    return abs(c-a)+abs(d-b);
}
int main() {
    srand(time(NULL));
    char player;
    cin>>player;
    int rob[2];
    int pol[6];
    cin>>rob[0];
    cin>>rob[1];
    int a[3][2];
    for(int i=0;i<6;i++) cin>>pol[i];
    vector< pair < int , int > > moves;
    int dist1 = co_ord_distance(rob[0],rob[1],pol[0],pol[1]);
            int dist2 = co_ord_distance(rob[0],rob[1],pol[2],pol[3]);
            int dist3 = co_ord_distance(rob[0],rob[1],pol[4],pol[5]);
            int mindis=min(dist1,dist2);
            mindis=min(mindis,dist3);
    
    if (player == 'R') {
            
			if((pol[0]+pol[4]+pol[2])%3==0 && ((pol[0]+pol[4]+pol[2])/3==pol[0] || (pol[0]+pol[4]+pol[2])/3==pol[2] ||(pol[0]+pol[4]+pol[2])/3==pol[4])){
				if(mindis==2){
					if(dist1==2){
						
					}
					if(dist2==2){
						
					}
					if(dist3==2){
						
					}
				}
			}
            for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                    int x = rob[0]+i;
                    int y = rob[1]+j;
                    if(INRANGE(x,0,20) && INRANGE(y,0,20)) {
                        int temp = min(co_ord_distance(x,y,pol[0],pol[1]) , co_ord_distance(x,y,pol[2],pol[3]));
                        temp=min( temp,co_ord_distance(x,y,pol[4],pol[5]));
                        
                        if (temp > mindis) {
                            cout<<x<<" "<<y<<endl;
                            return 0;
                        }
                    }
                }
            }
            int con=0;
            for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                    int x = rob[0]+i;
                    int y = rob[1]+j;
                    if(INRANGE(x,0,20) && INRANGE(y,0,20)) {
                        con++;
                    }
                }
            }
        if(con<=4 && mindis>2){
            for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                    if(i!=0 && j!=0){
                    int x = rob[0]+i;
                    int y = rob[1]+j;
                        
                    if(INRANGE(x,0,20) && INRANGE(y,0,20)) {
                        cout<<x<<" "<<y<<endl;
                        return 0;
                    }
                    }
                }
            }
        }
         for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                    int x = rob[0]+i;
                    int y = rob[1]+j;
                    if(INRANGE(x,0,20) && INRANGE(y,0,20) && (x!=rob[0] || y!=rob[1])) {
                        int temp = min(co_ord_distance(x,y,pol[0],pol[1]) , co_ord_distance(x,y,pol[2],pol[3]));
                        temp=min( temp,co_ord_distance(x,y,pol[4],pol[5]));
                        
                        if (temp == mindis) {
                            cout<<x<<" "<<y<<endl;
                            return 0;
                        }
                    }
                }
            }               
            
            cout<<rob[0]<<" "<<rob[1]<<endl;
            return 0;
    } 
    
    
    else {
		
		int flag=0;
		for(int i=1;i<5;i++){
			if(pol[i]!=0 && i!=3){
				flag=1;
				break;
			}
		}
		if(flag==0 && pol[0]==0){
			cout<<1<<" "<<0<<" "<<0<<" "<<1<<" "<<0<<" "<<1<<endl;
			return 0;
		}
		else if(flag==0){
			cout<<2<<" "<<0<<" "<<1<<" "<<1<<" "<<0<<" "<<2<<endl;
			return 0;
		}

        vector< pair < int, int > > move1;
        vector< pair < int, int > > move2;
        vector< pair < int, int > > move3;
            move1.push_back(make_pair(pol[0],pol[1]));
            move2.push_back(make_pair(pol[2],pol[3]));
            move3.push_back(make_pair(pol[4],pol[5]));
            int dist1 = co_ord_distance(rob[0],rob[1],pol[0],pol[1]);
            int dist2 = co_ord_distance(rob[0],rob[1],pol[2],pol[3]);
            int dist3 = co_ord_distance(rob[0],rob[1],pol[4],pol[5]);
            
            if(dist1==1){
				cout<<rob[0]<<" "<<rob[1]<<" "<<pol[2]<<" "<<pol[3]<<" "<<pol[4]<<" "<<pol[5]<<endl;
				return 0;
			}
			if(dist2==1){
				cout<<pol[0]<<" "<<pol[1]<<" "<<rob[0]<<" "<<rob[1]<<" "<<pol[4]<<" "<<pol[5]<<endl;
				return 0;
			}
			if(dist3==1){
				cout<<pol[0]<<" "<<pol[1]<<" "<<pol[2]<<" "<<pol[3]<<" "<<rob[0]<<" "<<rob[1]<<endl;
				return 0;
			}
			
			int x=pol[0];
			int y=pol[1];
			a[0][0]=x;
			a[0][1]=y;
			a[1][0]=x-1;
			a[1][1]=y+1;
			a[2][0]=x-2;
			a[2][1]=y+2;

			for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                    if(i!=0 && j!=0) continue;
                    int x = pol[0]+i;
                    int y = pol[1]+j;
                    if(INRANGE(x-2,0,20) && INRANGE(y+2,0,20)) {
                        int temp = co_ord_distance(x,y,rob[0],rob[1]);                        
                        if (temp <= dist1) {
                            a[0][0]=x;
                            a[0][1]=y;
                            a[1][0]=x-1;
                            a[1][1]=y+1;
                            a[2][0]=x-2;
                            a[2][1]=y+2;
                        }
                    }
                }
            }
			cout<<a[0][0]<<" "<<a[0][1]<<" "<<a[1][0]<<" "<<a[1][1]<<" "<<a[2][0]<<" "<<a[2][1]<<" "<<endl;
			return 0;

            for(int i=-1;i<2;i++) {
                for(int j=-1;j<2;j++) {
                     if(i!=0 && j!=0) continue;
                    int a = pol[0]+i;
                    int b = pol[1]+j;
                    int c = pol[2]+i;
                    int d = pol[3]+j;
                    int e = pol[4]+i;
                    int f = pol[5]+j;
                    if (INRANGE(a,0,20) && INRANGE(b,0,20)) {
                        int temp = co_ord_distance(a,b,rob[0],rob[1]);
                        if(temp<dist1) move1.push_back(make_pair(a,b));
                    }
                    if (INRANGE(c,0,20) && INRANGE(d,0,20)) {
                        int temp = co_ord_distance(c,d,rob[0],rob[1]);
                        if(temp<dist2) move2.push_back(make_pair(c,d));
                    }
                    if (INRANGE(e,0,20) && INRANGE(f,0,20)) {
                        int temp = co_ord_distance(e,f,rob[0],rob[1]);
                        if(temp<dist3) move3.push_back(make_pair(e,f));
                    }
                }
            }
            int ran1 = rand()%move1.size();
            int ran2,ran3;
            for(int tr=0;tr<5;tr++){
				ran2 = rand()%move2.size();
				ran3 = rand()%move3.size();
				if(move2[ran2].first==move3[ran3].first && move2[ran2].second == move3[ran3].second){
					continue;
				}
				else
					break;
			}
            cout<<a[0][0]<<" "<<a[0][1]<<" "<<move2[ran2].first<<" "<<move2[ran2].second<<" "<<move3[ran3].first<<" "<<move3[ran3].second;
    }
    return 0;
}
