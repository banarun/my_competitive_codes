#include<stdio.h>
#define ull unsigned long long
#define mod 1000000007
int buf[14];
ull in()
{
    ull r=0;
    int c;
    for(c=getchar_unlocked();c<=32;c=getchar_unlocked());
    for(;c>32;r=(r<<1)+(r<<3)+c-'0',c=getchar_unlocked());
    return r;
}

inline void out(int x)
{
    int ptr=0;
    while(x){
        buf[ptr++]=x%10+48;
        x/=10;
    }
    if(!ptr){
        putchar_unlocked(48);
        putchar_unlocked(10);
        return;
    }
    while(ptr){
        putchar_unlocked(buf[--ptr]);
    }
    putchar_unlocked(10);
}




ull int power(ull int x, ull int y)
{
    ull int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%mod;
    else
        return ((x*((temp*temp)%mod))%mod);
}


int main()
{
    int t;
    t=in();

    while(t--){
        ull int v;
        int n;
        ull int p[101],q[101],l[101],a[101];
        ull int a0,b0,c0,m0,a1,b1,c1,m1;
        v=in();
        n=in();
        p[0]=in();
        p[1]=in();
        a0 = in();
        b0 = in();
        c0 = in();
        m0 = in();
        q[0] = in();
        q[1] = in();
        a1 = in();
        b1 = in();
        c1 = in();
        m1 = in();
        a[0]=p[0]*m1+q[0];
        a[1]=p[1]*m1+q[1];
        int i;
        for(i=2;i<n;i++){
            p[i]=((((a0*a0)%m0)*p[i-1])%m0+(b0*p[i-2])%m0+c0%m0)%m0;
            q[i]=((((a1*a1)%m1)*q[i-1])%m1+(b1*q[i-2])%m1+c1%m1)%m1;
            a[i]=p[i]*m1+q[i];
        }
        //for(int i=0;i<n;i++)

        ull int pa=1,flag=0;

        for(i=0;i<n;i++){
            if(a[i]==0){
                pa=0;
                out(1);
                flag=1;
                break;
            }
            a[i]=a[i]%(mod-1);
            pa=(pa*a[i])%(mod-1);

        }
        if(pa==0 && flag==1)
            continue;

        v=v%mod;
        if(v==0 || v==1){
            out(int(v));
            continue;
        }
        out(int(power(v,pa)));
    }
    return 0;
}
