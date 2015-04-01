#include <iostream>

int a[30][30];

bool inRange(int i){
    if(i>=0 && i<29){
        return true;
    }
    else{
        return false;
    }
}

#include <vector>
using namespace std;
/* Head ends here */
void nextMove(char p, vector <string> board){
    char op;
    if(p=='w'){
        op='b';
    }
    else{
        op='w';
    }
    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==p){
                        b++;
                    }
                }
            }
            if(b==4){
                for(int i1=-1;i1<3;i1++)
                for(int j1=-1;j1<3;j1++)
                    if(inRange(i+i1) && inRange(j+j1))
                        a[i+i1][j+j1]=-1;
            }
        }
    }

    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==op){
                        b++;
                    }
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-'){
                        ca++;
                    }

                }
            }
            if(b==3 && ca==1){
                for(int i1=-1;i1<3;i1++)
                for(int j1=-1;j1<3;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-' && a[i+i1][j+j1]==0){
                        cout<<i+i1<<" "<<j+j1<<endl;
                        return;
                    }
                }
            }
        }
    }

    for(int i=0;i<28;i++){
            for(int j=0;j<28;j++){
                if(a[i][j]==p && a[i+1][j+1]=='-'){
                    cout<<i+1<<" "<<j+1<<endl;
                }
            }
    }

        for(int i=1;i<29;i++){
            for(int j=1;j<29;j++){
                if(a[i][j]==p && a[i-1][j-1]=='-'){
                    cout<<i-1<<" "<<j-1<<endl;
                }
            }
    }

    }

    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==p){
                        b++;
                    }
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-'){
                        ca++;
                    }

                }
            }
            if(b==3 && ca==1){
                for(int i1=0;i1<2;i1++)
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-' && a[i+i1][j+j1]==0){
                        cout<<i+i1<<" "<<j+j1<<endl;
                        return;
                    }
                }
            }
        }
    }



    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==p){
                        b++;
                    }
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-'){
                        ca++;
                    }

                }
            }
            if(b==2 && ca==2){
                for(int i1=0;i1<2;i1++)
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-' && a[i+i1][j+j1]==0){
                        cout<<i+i1<<" "<<j+j1<<endl;
                        return;
                    }
                }
            }
        }
    }

    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==p){
                        b++;
                    }
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-'){
                        ca++;
                    }

                }
            }
            if(b==1 && ca==3){
                for(int i1=0;i1<2;i1++)
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-' && a[i+i1][j+j1]==0){
                        cout<<i+i1<<" "<<j+j1<<endl;
                        return;
                    }
                }
            }
        }
    }

    for(int i=0;i<28;i++){
        for(int j=0;j<28;j++){
            int ca=0,b=0,c=0;
            for(int i1=0;i1<2;i1++){
                for(int j1=0;j1<2;j1++){
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]==p){
                        b++;
                    }
                    if(inRange(i+i1) && inRange(j+j1) && board[i+i1][j+j1]=='-'){
                        ca++;
                    }
                }
            }
            if(b==0 && ca==4){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }


    for(int i=0;i<29;i++){
        for(int j=0;j<29;j++){
            if(a[i][j]=='-'){
                cout<<i<<" "<<j<<endl;
                return;
            }
        }
    }

}

int main() {

    char player;
    vector <string> board;

    cin >> player;

    for(int i=0; i<29; i++) {
        string s; cin >> s;
        board.push_back(s);
    }
    nextMove(player,board);
    return 0;
}
