#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int i,t,l,p,n;
	int c,g,j,m;
	
	cin>>t;
	for(l=0;l<t;l++){
		g=3;
		p=3;
		j=3;
		vector<int> v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		v.push_back(2);
		int q;
		cin>>q;
		while(p<q){
			for(i=0;i<v[j];i++){
				v.push_back(g);
				p++;
			}
			j++;
			g++;
		}
		cout<<v[q]<<endl;		
	}
	return 0;
}
