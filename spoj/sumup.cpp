#include<cstdio>
main(){float d,t,n,p;scanf("%f",&t);while(t--){scanf("%f",&n);p=0;n++;while(n--)p+=n/((n*n-n+1)*(n*n+n+1));printf("%.5f\n",p);}}
