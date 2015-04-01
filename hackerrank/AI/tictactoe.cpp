#include <iostream>
using namespace std;

int main()
{
    int n=3;
    char c;
    char b;
    cin>>c;


    char a[3][3];
    int coun=0;
    if(c=='X')
        b='O';
    else
        b='X';
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++){
        cin>>a[i][j];
        if(a[i][j]==b)
            coun++;
    }

    if(c=='X'){
        if(a[0][0]=='_' && coun==0){
            cout<<0<<" "<<0<<endl;
            return 0;
        }
    }
    else{
        if(a[1][1]=='_' && coun==1){
            cout<<1<<" "<<1<<endl;
            return 0;
        }
        else if(coun==1){
            cout<<0<<" "<<0<<endl;
            return 0;
        }
    }
    if(coun==2 && a[1][1]==b && a[2][2]==b){
        cout<<0<<" "<<2<<endl;
        return 0;
    }

    if(coun==2 && a[1][1]==c){
        if(a[0][0]==b && a[0][1]=='_' && a[2][2]==b){
            cout<<0<<" "<<1<<endl;
            return 0;
        }
        if(a[0][2]==b && a[0][1]=='_' && a[2][0]==b){
            cout<<0<<" "<<1<<endl;
            return 0;
        }
    }


    if(coun==1 && a[1][1]=='_' && a[0][0]==c){
        int f=0;
        for(int i=0;i<n;i++){
            if(a[0][i]==b){
                f=1;
            }
        }
        if(f==0){
            cout<<0<<" "<<1<<endl;
            return 0;
        }
        cout<<1<<" "<<0<<endl;
        return 0;
    }
    else if(coun==1 && a[0][0]==c && a[1][1]==b){
        cout<<2<<" "<<2<<endl;
        return 0;
    }

    if(coun==2 && a[1][1]=='_' && a[0][0]==c && a[0][1]==c){
        if(a[0][2]==b){
        cout<<1<<" "<<1<<endl;
        return 0;
        }
        else if(a[0][2]=='_'){
           cout<<0<<" "<<2<<endl;
            return 0;//won
        }
    }


    int co,cd;
    co=0;cd=0;
        for(int i=0;i<3;i++){

        if(a[i][i]=='_'){
            cd++;
        }
        if(a[i][i]==c)
            co++;
    }
    if(co==2 && cd==1){
        for(int i=0;i<n;i++)
        if(a[i][i]=='_'){
            cout<<i<<" "<<i<<endl;
            return 0;
        }
    }
    co=0;cd=0;
    for(int i=0;i<3;i++){

        if(a[i][2-i]=='_'){
            cd++;
        }
        if(a[i][2-i]==c)
            co++;
    }
    if(co==2 && cd==1){
        for(int i=0;i<n;i++)
        if(a[i][2-i]=='_'){
            cout<<i<<" "<<2-i<<endl;
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        co=0;cd=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==c)
                co++;
            if(a[i][j]=='_')
                cd++;
        }
        if(co==2 && cd==1){
            for(int p=0;p<n;p++){
                if(a[i][p]=='_'){
                    cout<<i<<" "<<p<<endl;
                    return 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        co=0;cd=0;
        for(int j=0;j<n;j++){
            if(a[j][i]==c)
                co++;
            if(a[j][i]=='_')
                cd++;
        }
        if(co==2 && cd==1){
            for(int p=0;p<n;p++){
                if(a[p][i]=='_'){
                    cout<<p<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }

    //defend
    cd=0;co=0;
    for(int i=0;i<3;i++){

        if(a[i][i]=='_'){
            cd++;
        }
        if(a[i][i]==b)
            co++;
    }
    if(co==2 && cd==1){
        for(int i=0;i<n;i++)
        if(a[i][i]=='_'){
            cout<<i<<" "<<i<<endl;
            return 0;
        }
    }

    co=0;cd=0;
    for(int i=0;i<3;i++){

        if(a[i][2-i]=='_'){
            cd++;
        }
        if(a[i][2-i]==b)
            co++;
    }
    if(co==2 && cd==1){
        for(int i=0;i<n;i++)
        if(a[i][2-i]=='_'){
            cout<<i<<" "<<2-i<<endl;
            return 0;
        }
    }

    for(int i=0;i<n;i++){
        co=0;cd=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==b)
                co++;
            if(a[i][j]=='_')
                cd++;
        }
        if(co==2 && cd==1){
            for(int p=0;p<n;p++){
                if(a[i][p]=='_'){
                    cout<<i<<" "<<p<<endl;
                    return 0;
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        int co=0,cd=0;
        for(int j=0;j<n;j++){
            if(a[j][i]==b)
                co++;
            if(a[j][i]=='_')
                cd++;
        }
        if(co==2 && cd==1){
            for(int p=0;p<n;p++){
                if(a[p][i]=='_'){
                    cout<<p<<" "<<i<<endl;
                    return 0;
                }
            }
        }
    }


    if(coun==2 && a[1][1]==b && a[0][0]==c && a[2][2]==c){
        if(a[0][2]=='_'){
            cout<<0<<" "<<2<<endl;
            return 0;
        }
        if(a[2][0]=='_'){
            cout<<2<<" "<<0<<endl;
            return 0;
        }
    }
    int cmine=0;

    cd=0;co=0;
    cmine=0;
    for(int i=0;i<n;i++){
        if(a[0][i]=='_')
            cd++;
        if(a[0][i]==b)
            co++;
        if(a[0][i]==c)
            cmine++;
    }
    for(int i=0;i<n;i++){
        if(a[i][2]=='_')
            cd++;
        if(a[i][2]==b)
            co++;
        if(a[i][2]==c)
            cmine++;
    }
    if(cmine==0 && co>1){
        if(a[0][2]=='_'){
        cout<<0<<" "<<2<<endl;
        return 0;
            }
    }

    cd=0;co=0;
    cmine=0;
    for(int i=0;i<n;i++){
        if(a[0][i]=='_')
            cd++;
        if(a[0][i]==b)
            co++;
        if(a[0][i]==c)
            cmine++;
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='_')
            cd++;
        if(a[i][0]==b)
            co++;
        if(a[i][0]==c)
            cmine++;
    }
    if(cmine==0 && co>1){
            if(a[0][0]=='_'){
        cout<<0<<" "<<0<<endl;
        return 0;
            }
    }


    cd=0;co=0;
    cmine=0;
    for(int i=0;i<n;i++){
        if(a[2][i]=='_')
            cd++;
        if(a[2][i]==b)
            co++;
        if(a[2][i]==c)
            cmine++;
    }
    for(int i=0;i<n;i++){
        if(a[i][2]=='_')
            cd++;
        if(a[i][2]==b)
            co++;
        if(a[i][2]==c)
            cmine++;
    }
    if(cmine==0 && co>1){
            if(a[2][2]=='_'){
        cout<<2<<" "<<2<<endl;
        return 0;
            }
    }


    cd=0;co=0;
    cmine=0;
    for(int i=0;i<n;i++){
        if(a[2][i]=='_')
            cd++;
        if(a[2][i]==b)
            co++;
        if(a[2][i]==c)
            cmine++;
    }
    for(int i=0;i<n;i++){
        if(a[i][0]=='_')
            cd++;
        if(a[i][0]==b)
            co++;
        if(a[i][0]==c)
            cmine++;
    }
    if(cmine==0 && co>1){
            if(a[2][0]=='_'){
        cout<<2<<" "<<0<<endl;
        return 0;
            }
    }





    if( a[0][1]==a[1][0] && a[0][0]=='_' && a[0][2]=='_' && a[2][0]=='_'){
        if(a[0][1]=='_')
         cout<<0<<" "<<1<<endl;
        else
        cout<<0<<" "<<0<<endl;
               return 0;
    }
    if( a[2][1]==a[1][0] && a[2][0]=='_' && a[2][2]=='_' && a[2][0]=='_'){
        if(a[1][0]=='_')
         cout<<1<<" "<<0<<endl;
        else
        cout<<2<<" "<<0<<endl;
               return 0;
    }
    if( a[0][1]==a[1][2] && a[0][2]=='_' && a[0][2]=='_' && a[2][2]=='_'){
        if(a[1][2]=='_')
         cout<<1<<" "<<2<<endl;
        else
        cout<<0<<" "<<2<<endl;
               return 0;
    }
    if( a[2][1]==a[1][2] && a[2][2]=='_' && a[0][2]=='_' && a[2][0]=='_'){
        if(a[1][2]=='_')
         cout<<1<<" "<<2<<endl;
        else
        cout<<2<<" "<<2<<endl;
        return 0;
    }


     if( a[0][1]==a[1][0] && a[1][1]=='_' && a[1][2]=='_' && a[2][1]=='_'){
        if(a[0][1]=='_')
         cout<<0<<" "<<1<<endl;
        else
        cout<<1<<" "<<1<<endl;
               return 0;
    }
    if( a[2][1]==a[1][0] && a[1][1]=='_' && a[0][1]=='_' && a[1][2]=='_'){
        if(a[1][0]=='_')
         cout<<1<<" "<<0<<endl;
        else
        cout<<1<<" "<<1<<endl;
               return 0;
    }
    if(a[0][1]==a[1][2] && a[1][1]=='_' && a[2][1]=='_' && a[1][0]=='_'){
        if(a[1][2]=='_')
         cout<<1<<" "<<2<<endl;
        else
        cout<<0<<" "<<2<<endl;
               return 0;
    }
    if( a[2][1]==a[1][2] && a[1][1]=='_' && a[0][1]=='_' && a[1][0]=='_'){
        if(a[1][2]=='_')
         cout<<1<<" "<<2<<endl;
        else
        cout<<2<<" "<<2<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
            int bt=0,ct=0;
        for(int j=0;j<n;j++){
            if(a[i][j]==b)
                bt++;
            if(a[i][j]==c)
                ct++;
        }
        if(bt==0 && ct==1){
            for(int j=0;j<n;j++){
                if(a[i][j]=='_'){
                   cout<<i<<" "<<j<<endl;
                    return 0;
                }
            }
        }
    }
    if(a[1][1]=='_'){
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    for(int i=0;i<3;i++){
        if(a[i][i]=='_'){
            cout<<i<<" "<<i<<endl;
            return 0;
        }
    }

    if(a[0][2]=='_'){
        cout<<0<<" "<<2<<endl;
        return 0;
    }
    if(a[2][0]=='_'){
        cout<<2<<" "<<0<<endl;
        return 0;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(a[i][j]=='_'){
            cout<<i<<" "<<j<<endl;
                return 0;
            }
        }
    }

    return 0;
}
