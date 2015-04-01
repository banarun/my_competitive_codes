#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

struct topic{
    double x;
    double y;
    int id;
    double val;
};
struct question{
    int id;
    double val;
};
bool fun(const topic &l, const topic &r){
    if(l.val!=r.val)
    return l.val<r.val;

    else
    return l.id>r.id;
}
double hashx[100000];
double hashy[100000];
int main()
{
    int T,Q,n;
    int r[1000];
    int num;
    vector<topic> t;
    vector<question> q;
    cin>>T>>Q>>n;
    //cout<<"STart t\n";
    for(int i=0;i<T;i++){
        topic tp;
        scanf("%d",&(tp.id));

        cin>>tp.x>>tp.y;
        hashx[tp.id]=tp.x;
        hashy[tp.id]=tp.y;
        //cout<<tp.id<<" "<<tp.x<<" "<<tp.y<<endl;
        t.push_back(tp);
    }
    //cout<<"End of topic\n";

    for(int i=0;i<Q;i++){
        question qu;
        cin>>qu.id;
        cin>>num;
        for(int i=0;i<num;i++){
            scanf("%d",&r[i]);

        }
        }
    for(int i=0;i<n;i++){
        char ch;
        int count;
        double X,Y;
        //cout<<"Start query\n";
        cin>>ch;
        //cout<<ch<<endl;
        scanf("%d",&count);
        cin>>X>>Y;

        //cout<<X<<" "<<Y<<endl;
        if(ch=='t'){
            for(int j=0;j<T;j++){
                double x1=t[j].x-X;
                double y1=t[j].y-Y;
                t[j].val=sqrt((x1)*(x1)+(y1)*(y1));
            }
            sort(t.begin(),t.end(),fun);
      //      cout<<"Sorted\n";
            for(int i=0;i<count;i++){
                cout<<t[i].id<<" "<<t[i].val<<endl;
            }
            cout<<endl;
        }
        else if(ch=='q'){

        }
    }


    return 0;
}
