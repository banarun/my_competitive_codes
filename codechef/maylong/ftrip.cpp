#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){
        double s,n,m,k;
        //scanf("%f%f%f%f",&s,&n,&m,&k);
        cin>>s>>n>>m>>k;
        s--;n--;m--;
        double ans=0;
        double k1=k;
        for(k1=k;k1<=m && k1<=n ;k1++){
            if(s-m>=n-k1){
                double prod=1.0,count=1.0;
                double i=s,j=m,r=s-m;
                while(1){
                    int f=0;
                    if(count<=k1){
                        prod*=(j/count);
                        f=1;
                        j--;
                    }
                    if(count<=n-k1){
                        prod*=(r/count);
                        f=1;
                        r--;
                    }
                    if(count<=n){
                        prod=(prod*count)/i;
                        f=1;
                        i--;
                    }
                    count++;
                    if(f==0)
                        break;
                }
                //cout<<prod<<endl;
                ans+=prod;
            }
        }
        printf("%.9f\n",ans);
    }

    return 0;
}
