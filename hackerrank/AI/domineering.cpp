#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n=8;
    char a[8][8];
    char c,b;
    cin>>c;
    int coun=0;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>a[i][j];
    }
    if(c=='v'){
        b='h';
        for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]==b)
                coun++;
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(a[i][j]=='-' &&a[i][j+1]=='-' &&a[i+1][j]=='-' &&a[i+1][j+1]=='-' ){
                    cout<<i<<" "<<j+1<<endl;
                    return 0;
                }
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                    int cou=0;
                if(a[i][j]=='-')cou++;
                if(a[i][j+1]=='-')cou++;
                if(a[i+1][j]=='-')cou++;
                if(a[i+1][j+1]=='-')cou++;

                if(cou>2){
                    if(a[i][j]!='-'){
                        cout<<i<<" "<<j+1<<endl;
                        return 0;
                    }
                    if(a[i+1][j]=='-'){
                        cout<<i<<" "<<j<<endl;
                    }
                    else{
                        cout<<i<<" "<<j+1<<endl;
                    }
                    return 0;
                }
            }
        }

        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='-'&&a[i+1][j]=='-'){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }

            }
        }
    }
    else{
        b='v';
        for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++){
            cin>>a[i][j];
            if(a[i][j]==b)
                coun++;
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                if(a[i][j]=='-' &&a[i][j+1]=='-' &&a[i+1][j]=='-' &&a[i+1][j+1]=='-' ){
                    cout<<i+1<<" "<<j<<endl;
                    return 0;
                }
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-1;j++){
                    int cou=0;
                if(a[i][j]=='-')cou++;
                if(a[i][j+1]=='-')cou++;
                if(a[i+1][j]=='-')cou++;
                if(a[i+1][j+1]=='-')cou++;

                if(cou>2){
                    if(a[i][j]!='-'){
                        cout<<i+1<<" "<<j<<endl;
                        return 0;
                    }
                    if(a[i][j+1]=='-'){
                        cout<<i<<" "<<j<<endl;
                    }
                    else{
                        cout<<i+1<<" "<<j<<endl;
                    }
                    return 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(a[i][j]=='-'&&a[i][j+1]=='-'){
                    cout<<i<<" "<<j<<endl;
                    return 0;
                }

            }
        }
    }
    return 0;
}
