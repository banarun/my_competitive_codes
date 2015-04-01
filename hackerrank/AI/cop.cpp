#include<iostream>
#include<vector>
#include<stdlib.h>
using namespace std;

int main() {
    vector<string> board;
    string s;
    srand(time(NULL));
    vector<string> moves;
    moves.push_back("UP");
    moves.push_back("DOWN");
    moves.push_back("LEFT");
    moves.push_back("RIGHT");
    vector<int> valid_moves;
    char p,op;
    int i_x, i_y, o_x, o_y;
    cin>>p>>i_x>>i_y>>o_x>>o_y;
    int x,y,opx,opy;
    if(p == 'r') {
        op='g';
        x = i_x;
        y = i_y;
        opx=o_x;
        opy=o_y;
    } else {
        op='r';
        opx = i_x;
        opy = i_y;
        x = o_x;
        y = o_y;
    }
    for( int i = 0; i < 15; i++ ) cin>>s, board.push_back(s);
    
    for ( int j = -1; j < 2; j++) {
    for ( int i = -1; i < 2; i++ ) {
        
            if ((i == 0 && j !=0) || ( i != 0 && j == 0 ) ) {
                
                if(board[x+i][y+j] == '-') {
                     for ( int i1 = -1; i1 < 2; i1++ ) {
                    for ( int j1 = -1; j1 < 2; j1++) {
                    if ((i1 == 0 && j1 !=0) || ( i1 != 0 && j1 == 0 ) ) {
                        if(board[x+i+i1][y+j+j1]=='-' && board[x+2*i][y+2*j]=='-'){
							
                    if( j == -1 ) {cout<<"LEFT";return 0;}
                    if( j == 1 ) {cout<<"RIGHT";return 0;}
                            if( i == -1 ) {cout<<"UP";return 0;}
                    if( i == 1 ) {cout<<"DOWN";return 0;}
                    }
                    }
                }
            }
        }
    }
    }
    }
    
    
    
    for ( int i = -1; i < 2; i++ ) {
        for ( int j = -1; j < 2; j++) {
            if ((i == 0 && j !=0) || ( i != 0 && j == 0 ) ) {
                
                if(board[x+i][y+j] == '-') {
                    if( i == -1 ) valid_moves.push_back(0);
                    if( i == 1 ) valid_moves.push_back(1);
                    if( j == -1 ) valid_moves.push_back(2);
                    if( j == 1 ) valid_moves.push_back(3);
                }
            }
        }
    }
    if( valid_moves.size()!=0 ) {
        
        int random = rand()%valid_moves.size();
        cout<<moves[valid_moves[random]];
        return 0;
    }
    cout<<moves[rand()%moves.size()]<<endl;
    return 0;
}
