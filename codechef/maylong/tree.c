#include <stdio.h>
#include <math.h>

long long int power(long long int x, long long int y)
{
    long long int temp;
    if( y == 0)
        return 1;
    temp = power(x, y/2);
    if (y%2 == 0)
        return (temp*temp)%1000000007;
    else
        return ((x*((temp*temp)%1000000007
        ))%1000000007);
}

int main()
{
    long long int n,k,t;
    long long int ans,a1,a2;
    scanf("%lld%lld",&n,&k);

    a1=power(n*k,n-2);
    a2=power((n-1)*k,n*(k-1));
    ans=(a2*a1)%1000000007;
    printf("%lld\n",ans);
    return 0;
}

