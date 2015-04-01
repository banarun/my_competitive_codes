#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

#define pi 3.14159265358979323
inline int inp( )
{
	int n=0;
	int ch=getchar_unlocked();
	while( ch >47 )
	n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
	return n;
}

int main()
{
	int t;
	int t1,t2;
	double w,h;
	t=inp();
	while(t--){
		double r,a,ans=0,vol=0,temp;
		t1=inp();
		t2=inp();
		w=min(t1,t2);
		h=max(t1,t2);
		ans=((w*w)/(4*pi))*(h-w/pi);
		if(w*11>h){
			r=h/(2*(pi+1));
			if(4*r<=w){
				vol=pi*r*r*w;
				ans=max(vol,ans);
			}
			r=double(w)/2;
			a=w;
			if(h>=(2+pi)*w){
				vol=pi*r*r*a;
				ans=max(vol,ans);
			}
			else{
				double tr=2*(pi+1)*h*w+(1-(pi+1)*(pi+1))*w*w;
				if(tr>=0 && h>=(2+2*pi)*(w/4) ){
					tr=sqrt(tr);
					r=(h*(pi+1)+w-tr)/(2*(pi+1)*(pi+1));
						vol=pi*r*r*w;
						ans=max(vol,ans);
				}
			}
			r=h/(2*pi);
			temp=w-(2*r);
			if(temp>0){
				a=temp;
				vol=pi*r*r*a;
				ans=max(vol,ans);
			}
			
		}
		printf("%.12f",ans);
		putchar_unlocked('\n');
	}
	return 0;
}
