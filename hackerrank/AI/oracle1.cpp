#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
/* Head ends here */
void nextQuestion(int n, bool plularity, int lies, int color, bool exact_lies, int qnum, vector< vector < int > > a)
{
	int tr=0,fl=0,ind=-1,cur=-1;
	for(int i=0;i<n;i++){
		if(i!=7){
			if(a[7][i]==1){
				tr++;
			}
			if(a[7][i]==0){
				fl++;
				ind=i;
			}
			if(a[7][i]==-1){
				cur=i;
				break;
			}
		}
	}
	int diff=0;
	if(tr-fl>0){
		diff=tr-fl;
	}
	else{
		diff=fl-tr;
	}
	if(diff>(n-1-qnum){
		if(tr-fl>0){
			cout<<7<<endl;
			return;
		}
		else{
			cout<<ind<<endl;
			return;
		}
	}
	else{
		cout<<7<<" "<<cur<<endl;
		return;
	}
	
}
/* Tail starts here */

int main(void)
{
    int n, plularity, lies, color, exact_lies, query_size,x,y;
    cin >> n >> plularity >> lies >> color >> exact_lies >> query_size;
    vector < vector < int > > query;
    vector < int > temp;
    string answer;
    for(int i=0;i<n;i++)
        temp.push_back( -1 );
    for(int i=0;i<n;i++)
        query.push_back( temp );

    for(int i=0;i<n; i++) {
        for( int j=0;j<n;j++ ) {
            query[ i ][ j ] = -1;
        }
    }
    for(int i=0;i<query_size;i++) {
        cin >> x >> y >> answer;
        if(answer.compare("YES") == 0)
        {
            query[ x ][ y ] = 1;
            query[ y ][ x ] = 1;
        }
        else
        {
            query[ x ][ y ] = 0;
            query[ y ][ x ] = 0;
        }
    }
    nextQuestion(n, plularity, lies, color, exact_lies, query_size, query);
    return 0;
}
