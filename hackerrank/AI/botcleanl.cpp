#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

char grid[100][100];
int n=5;
int count=0;

int main()
{
    int mx,my,px,py,count=0;
    int n1,n2;
    cin>>mx;
    cin>>my;
    cin>>n1;
    cin>>n1;
    int xd,yd;
    int x1,y1;
    int tot=100;
    for(int i=0;i<n1;i++)
    for(int j=0;j<n2;j++){
        cin>>grid[i][j];
    }
    if(grid[mx][my]=='d'){
        cout<<"CLEAN";
        return 0;
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            if(grid[i][j]=='d'){
                xd=i-mx;
                yd=j-my;
                int tem=int(abs(xd)+abs(yd));
                if(tem<tot){
                    tot=tem;
                    x1=i;
                    y1=j;
                }
                count++;
            }
        }
    }

    if(count==0)
        return 0;
  //  cout<<x1<<" "<<y1<<endl;
    if(abs(x1-mx)>abs(y1-my)){
        if(mx<x1){
            cout<<"RIGHT\n";
            return 0;
        }
        else{
            cout<<"LEFT\n";
            return 0;
        }
    }
    else{
        if(my<y1){
            cout<<"DOWN\n";
            return 0;
        }
        else{
            cout<<"UP\n";
            return 0;
        }
    }
}
