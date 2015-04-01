#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

int calculate_bid(int p, int pos,int n,int* fm, int* sm) 
{    
    int fbal=100,sbal=100;
    int pbal,opbal,away;
    for(int i=0;i<n;i++){
        if(fm[i]>sm[i]){
            fbal-=fm[i];
        }
        else if(fm[i]<sm[i]){
            sbal-=sm[i];
        }
        else{
            if(i%2){
                sbal-=sm[i];
            }
            else
                fbal-=fm[i];
        }
    }
    if(p==1){
        pbal=fbal;
        opbal=sbal;
        away=pos;
    }
    else{
        pbal=sbal;
        opbal=fbal;
        away=10-pos;
    }
    
    
    if(away>8){
        if(pbal>sbal){ 
        cout<<sbal+1<<endl;
            return 0;
            
        }
    }
    if(away>7){
        if(pbal>sbal){
			if(rand()%2){ 
				cout<<sbal-3<<endl;
				return 0;
			}
            else{
            cout<<pbal/2<<endl;
                return  0;
            }
        }
    }
    
    if(pbal<15){
        cout<<3<<endl;
        return 0;
    }
    if(pbal<10){
        cout<<2<<endl;
        return 0;
    }
    if(pbal>70){
        cout<<17+rand()%10<<endl;
        return 0;
    }
    if(pbal>40 && opbal>40){
        cout<<rand()%3+2+(rand()%2)*15<<endl;
        return 0;
    }
    else if(pbal>40){
        if(opbal<40){
			cout<<rand()%4+2+(rand()%2)*10<<endl;
			return 0; 
		}
    }
    else{
        cout<<(rand()%3)*6+rand()%5+2<<endl;
        return 0;
    }
}

int main(void) {
    int player;                                 //1 if first player 2 if second
    int scotch_pos;                             //position of the scotch 
    int bid,iter=0;                                    //Amount bid by the player
    size_t buf_limit = 500;
    char *first_move = (char *) malloc(buf_limit);      //previous bids of the first player
    char *second_move = (char *) malloc(buf_limit);     //prevous bids of the second player
    char remove_new_line[2];
    int first_moves[200] = {0};
    int second_moves[200] = {0};
    char *tok_1,*tok_2;
    cin>>player;
    cin>>scotch_pos;
    cin.getline(remove_new_line,2);           //removes a new line from the buffer
    cin.getline(first_move,200);
    cin.getline(second_move,200);
    tok_1 = strtok(first_move," ");
    int count=0;
    for(int i=0; tok_1; i++) {
        first_moves[i] = atoi(tok_1); 
        tok_1 = strtok(NULL," ");
        count++;
    }
    count++;
    tok_2 = strtok(second_move," ");
    for(int i=0;tok_2;i++) {
        second_moves[i] = atoi(tok_2); 
        tok_2 = strtok(NULL," ");
    }
    bid = calculate_bid(player,scotch_pos,count,first_moves,second_moves);
    
    return 0;
}
