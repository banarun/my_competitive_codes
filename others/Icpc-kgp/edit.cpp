#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#define ll long long;
using namespace std;

#define STRING_X "SUNDAY"
#define STRING_Y "SATURDAY"
 
#define SENTINEL (-1)
#define EDIT_COST (1)
 int m1,n1;
int Minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}
 
int EditDistanceDP(int X[], int Y[])
{
    int cost = 0;
    int leftCell, topCell, cornerCell;
 
    int m = 1+m1;
    int n = n1+1;
 
    int *T = (int *)malloc(m * n * sizeof(int));
 
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            *(T + i * n + j) = SENTINEL;
    for(int i = 0; i < m; i++)
        *(T + i * n) = i;
 
    // T[0][j] = j
    for(int j = 0; j < n; j++)
        *(T + j) = j;
 
    // Build the T in top-down fashion
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // T[i][j-1]
            leftCell = *(T + i*n + j-1);
            leftCell += EDIT_COST; // deletion
 
            // T[i-1][j]
            topCell = *(T + (i-1)*n + j);
            topCell += EDIT_COST; // insertion
 
            // Top-left (corner) cell
            // T[i-1][j-1]
            cornerCell = *(T + (i-1)*n + (j-1) );
 
            // edit[(i-1), (j-1)] = 0 if X[i] == Y[j], 1 otherwise
            cornerCell += (X[i-1] != Y[j-1]); // may be replace
 
            
            *(T + (i)*n + (j)) = Minimum(leftCell, topCell, cornerCell);
        }
    }
 
    // Cost is in the cell T[m][n]
    cost = *(T + m*n - 1);
    free(T);
    return cost;
}
 
 
int main()
{
	int t;
	cin>>t;
	while(t--){
		
		int a1[102],a2[102];
		scanf("%d",&m1);
		for(int i=0;i<m1;i++){
			scanf("%d",&a1[i]);
		}
		scanf("%d",&n1);
		for(int i=0;i<n1;i++){
			scanf("%d",&a2[i]);
		}
		printf("%d\n",EditDistanceDP(a1, a2) );
	}
    return 0;
}
