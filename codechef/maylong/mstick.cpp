#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <iostream>
using namespace std;
int minVal(int x, int y) { return (x < y)? x: y; }
int maxVal(int x, int y) { return (x < y)? y: x; }

int getMid(int s, int e) {  return s + (e -s)/2;  }
int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MAX;
    int mid = getMid(ss, se);
    return minVal(RMQUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQXUtil(int *st, int ss, int se, int qs, int qe, int index)
{
    if (qs <= ss && qe >= se)
        return st[index];
    if (se < qs || ss > qe)
        return INT_MIN;

    int mid = getMid(ss, se);
    return maxVal(RMQXUtil(st, ss, mid, qs, qe, 2*index+1),
                  RMQXUtil(st, mid+1, se, qs, qe, 2*index+2));
}

int RMQ(int *st, int n, int qs, int qe)
{

    if (qs < 0 || qe > n-1 || qs > qe)
    {
        printf("Invalid Input");
        return -1;
    }

    return RMQUtil(st, 0, n-1, qs, qe, 0);
}

int RMXQ(int *st, int n, int qs, int qe)
{
    // Check for erroneous input values
    if (qs < 0 || qe > n-1 || qs > qe)
    {
        return INT_MIN;
    }

    return RMQXUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  minVal(constructSTUtil(arr, ss, mid, st, si*2+1),
                     constructSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int constructXSTUtil(int arr[], int ss, int se, int *st, int si)
{
    if (ss == se)
    {
        st[si] = arr[ss];
        return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =  maxVal(constructXSTUtil(arr, ss, mid, st, si*2+1),
                     constructXSTUtil(arr, mid+1, se, st, si*2+2));
    return st[si];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int max_size = 2*(int)pow(2, x) - 1;
    int *st = new int[max_size];

    constructSTUtil(arr, 0, n-1, st, 0);

    return st;
}

int *constructXST(int arr[], int n)
{
    int x = (int)(ceil(log2(n))); //Height of segment tree
    int max_size = 2*(int)pow(2, x) - 1; //Maximum size of segment tree
    int *st = new int[max_size];

    // Fill the allocated memory st
    constructXSTUtil(arr, 0, n-1, st, 0);
    return st;
}
int main()
{
    int arr[100000];
    int n,mini=0;
    long long int maxi=1000000000;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        if(mini>arr[i])
            mini=arr[i];
        if(maxi<arr[i])
            maxi=arr[i];
    }

    int *st = constructST(arr, n);
    int *sta = constructXST(arr,n);

    int q,qs,qe;
    cin>>q;
    while(q--){
        scanf("%d%d",&qs,&qe);
        int rmin=RMQ(st, n, qs, qe);
        int rmax=RMXQ(sta, n, qs, qe);
        int rlmax=max(RMXQ(sta, n, 0, qs-1),RMXQ(sta,n,qe+1,n-1));
        double time=rmin+max(static_cast<double>(rlmax),(rmax-rmin)/2.0);
        printf("%.1f\n",time);
    }
    return 0;
}
