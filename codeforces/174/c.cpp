#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>

using namespace std;

int n, q,p=1, l, r, a[2000005], b[1000005], c[1000005];
long long i, Ans;

int main()
{
	int t,inc,x;
	double avg=0,sum=0;
	scanf("%I64d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &t);
		if(t==1){
			scanf("%d%d",&x,&inc);
			b[x]=b[x]+inc;
			sum=sum+(inc*x);
			avg=(sum)/p;
		}
		if(t==2){
			p++;
			scanf("%d",&x);
			a[p]=x;
			sum=sum+x;
			avg=(sum)/p;
			
		}
		if(t==3){
			
			sum=sum-a[p];
			a[p]=0;
			sum=sum-b[p];
			b[p-1]+=b[p];
			b[p]=0;
			avg=(sum)/(p-1);
			p--;
		}
		printf("%f\n",avg);
	}
	/*
	for (i = 1; i <= q; i++)
		scanf("%I64d %I64d", &l, &r), c[l]++, c[r + 1]--;
	for (i = 1; i <= n; i++)
		b[i] = b[i - 1] + c[i];
	sort(a + 1, a + n + 1);
	sort(b + 1, b + n + 1);
	for (i = 1; i <= n; i++)
		Ans += (a[i] * b[i]);
	printf("%I64d\n", Ans);
	*/
	return 0;
}
