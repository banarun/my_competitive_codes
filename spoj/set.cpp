#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

#define ARRAY_SIZE(A) sizeof(A)/sizeof(A[0])


int CeilIndex(int A[], int l, int r, int key) {
    int m;

    while( r - l > 1 ) {
        m = l + (r - l)/2;
        (A[m] >= key ? r : l) = m;
    }

    return r;
}

int LongestIncreasingSubsequenceLength(int A[], int size) {


    int *tailTable = new int[size];
    int len;

    memset(tailTable, 0, sizeof(tailTable[0])*size);

    tailTable[0] = A[0];
    len = 1;
    for( int i = 1; i < size; i++ ) {
        if( A[i] < tailTable[0] )

            tailTable[0] = A[i];
        else if( A[i] > tailTable[len-1] )

            tailTable[len++] = A[i];
        else


            tailTable[CeilIndex(tailTable, -1, len-1, A[i])] = A[i];
    }

    delete[] tailTable;

    return len;
}
int a[100001];
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		int ans=LongestIncreasingSubsequenceLength(a, n);
		printf("%d\n",ans);
	}
    return 0;
}
