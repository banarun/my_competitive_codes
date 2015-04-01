#include <iostream>
#include <algorithm>
#include <set>
#include <cstdio>
using namespace std;

int main()
{
    int n,k;
    int flag=0;
    cin>>n;
    multiset<int> s;
    multiset<int>::iterator it1,it,temp;

    for(int i=0;i<n;i++){
        char ch;
        cin>>ch;
        cin>>k;
        if(ch=='a'){
            s.insert(k);
            if(s.size()==1){
                it=s.begin();
                it1=it;
            }
            else if(s.size()%2){
                    if(k>*it && k>*it1){
                        it=it1;
                    }
                    else if(k<*it && k<*it1){
                        it1=it;
                    }
                    else if(k==*it || k==*it1){
                        if(k == *it){
                            it++;
                            it1=it;
                        }
                        else{
                            it=it1;
                        }
                    }
                    else{
                        it++;
                        it1--;
                    }
            }
            else{
                if(k>=*it){
                    it1++;
                }
                else if(k<*it){
                    it--;
                }
            }
            double tem=*it;
            double ans=tem+(*it1-tem)/2.0;
            int te=int(ans);
            tem=te;
            if(tem==ans)
                printf("%.0f\n",ans);
            else
                printf("%.1f\n",ans);

        }
        else{
            if(s.size()>1 && s.find(k)!=s.end()){
                temp=s.find(k);
                if(s.size()%2){
                    if(*it==k){
                        temp=it;
                        it--;
                        it1++;
                       // cout<<*it<<" "<<*it1<<endl;
                        s.erase(temp);
                       // cout<<*it<<" "<<*it1<<endl;

                    }
                    else{
                        if(*it<k)
                            it--;
                        else
                            it1++;
                         //cout<<*it<<" "<<*it1<<endl;
                        s.erase(temp);
                       // cout<<*it<<" "<<*it1<<endl;

                    }
                }
                else{

                    if(*it==k){
                        //cout<<*it1<<endl;
                        s.erase(it);
                        it=it1;
                    }
                    else if(*it1==k){
                        s.erase(it1);
                        it1=it;
                    }
                    else{
                        if(*it1<k){
                            it1--;
                            s.erase(temp);
                        }
                        else{
                            it++;
                            s.erase(temp);
                        }
                    }

                }
                double tem=*it;
                double ans=tem+(*it1-tem)/2.0;
                int te=int(ans);
                tem=te;
                if(tem==ans)
                    printf("%.0f\n",ans);
                else
                    printf("%.1f\n",ans);
            }
            else if(s.size()==1 && s.find(k)!=s.end()){
				s.erase(k);
				cout<<"Wrong!"<<endl;
			}
            else{
                cout<<"Wrong!"<<endl;
            }
        }
    }
    return 0;
}
