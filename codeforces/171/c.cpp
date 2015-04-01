#include <iostream>
#include <vector>
#include <cstdio>
#include <set>
#include <map>

using namespace std;

int main()
{
	int t,n,m;
	cin>>n>>m;
	int a[100002];
	int b[100002];
	//int c[100000];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	int p=1,ct=0,flag=0;
	b[0]=1;
	for(int i=1;i<=n-1;){
		
		while(i<n && a[i]<=a[i+1] ){
			i++;
		}
		while( i<n && a[i]>=a[i+1] ){
			i++;
		}
		b[p]=i;
		p++;
	}
	
	/*
	for(int i=0;i<p;i++)
		cout<<b[i]<<" ";
	cout<<endl;
		*/
	int x,y;
	int str=p;
	for(int i=0;i<m;i++){
		int imin=0,imid,key;
		int imax=p;
		cin>>x>>y;
		if(x==y){
			cout<<"Yes\n";
			continue;
		}
		else if(x<y)
			key = x;
		else {
			key = y;
			y=x;
		}
		flag=0;
		while (imax >= imin)
		{
			imid = (imin+imax)/2;
			if(b[imid]<key && b[imid+1]>key) {
				flag=1;
				break; 
				
			}
			
			else if ((b[imid-1]<key && b[imid]>key)){
				flag=1;
				imid--;
				break;
				
			}
			
			else if(b[imid]==key){
				flag=0;
				break;
			}
			else if (b[imid] < key)
				imin = imid + 1;
			else if (b[imid] > key)
				imax = imid - 1;
			
		}
		//cout<<flag;
		
		if(flag==1 && (b[imid]<=y && b[imid+1]>=y))
			cout<<"Yes\n";
		else if (flag==0 &&  (b[imid+1]>=y && y>=b[imid]))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	
	
	return 0;
}
