#include <iostream>
#include <string>
using namespace std;
#define ROW 50
#define COL 50
#define infi 100000000  
{
   int graph[ROW][COL],nodes;
   public:
   prims();
   void createGraph();
   void primsAlgo();
};

prims :: prims(){
     for(int i=0;i<ROW;i++)
       for(int j=0;j<COL;j++)
     graph[i][j]=0;
}

void prims :: createGraph(){
    int i,j,nodes;
    cin>>nodes;
    int graph[55][55];
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
        cin>>graph[i][j];

    //Assign infinity to all graph[i][j] where weight is 0.for(i=0;i<nodes;i++){
        for(j=0;j<nodes;j++){
           if(graph[i][j]==0)
          graph[i][j]=infi;
        }
    }
}

void prims :: primsAlgo(){
    int selected[ROW],i,j,ne; //ne for no. of edgesintfalse=0,true=1,min,x,y;

    for(i=0;i<nodes;i++)
       selected[i]=false;

    selected[0]=true;
    ne=0;

    while(ne < nodes-1){
       min=infi;

       for(i=0;i<nodes;i++)
       {
          if(selected[i]==true){
         for(j=0;j<nodes;j++){
            if(selected[j]==false){
               if(min > graph[i][j])
               {
               min=graph[i][j];
               x=i;
               y=j;
               }
            }
         }
          }
       }
       selected[y]=true;
       ne=ne+1;
    }
}

int main(){
    prims MST;
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}
