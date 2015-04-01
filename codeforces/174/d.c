#include <stdio.h>
int n;
int a[20],b[20];
int dp[20][20];
int stri[20][200];
int strj[20][200];
long long int d[20][20];
long long int count=0;

void fun(int p)
{
	if(p==n+1){
		count++;
        if(count>1000000007)
            count=count-1000000007;
		return;
	}
    int i;
    for(i=0;i<n;i++){
        //cout<<i<<j<<endl;
        if(a[stri[p][i]]==0 && b[strj[p][i]]==0 && dp[stri[p][i]][strj[p][i]]==p){
           // printf("A");
            a[stri[p][i]]=1;
            b[strj[p][i]]=1;
            //cout<<i<<" "<<j<<" "<<endl;
            fun(p+1);
            a[stri[p][i]]=0;
            b[strj[p][i]]=0;
        }
    }
}


int main()
{
	int i,j;
    unsigned long long int p;
	scanf("%d",&n);
	
	if(n%2==0){
		printf("0\n");
		return 0;
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			dp[i][j]=((i+j-2)%n)+1;
		}
	}
	d[1][1]=1;
    for(p=1;p<=n;p++){
        int k=0;
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
				if(dp[i][j]==p){
					stri[p][k]=i;
                    strj[p][k]=j;
                    k++;
				}
			}
		}
	}
    fun(1);
    /*
	for(i=1;i<n;i++){
        for(j=0;j<30;j++){
            printf("%d ",strj[i][j]);
        }
        printf("\n");
    }
    */
	p=1;
	for(i=1;i<=n;i++){
		p=p*i;
		p=p%1000000007;
	}
	count=(count*p)%1000000007;
	printf("%d\n",count);
	return 0;
}
