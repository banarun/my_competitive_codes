#include <iostream>
#include <vector>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
    vector<vector<int> > adj(101);
    vector<int> a;
    vector<int> b;
    
    for(int i=1;i<=100;i++)
            adj[i].resize(101);
 
    int x,y;
    while( )
    {
			cin>>x>>y;
             a.push_back(x);
             b.push_back(y);
             adj[x][y]=1;
             adj[x][y]=1;
    }

    
    int z;
    z =1;
    cout << z << " ";
    
    for(int i=0;i<100;i++)
    {
            
            if(adj[z][i] == 1 && b[i-1]==z && a[i-1] != z)
            {
                cout << a[i-1] << " ";
                int start = a[i-1];
            }
            
    }

}
