#include <cstring>
#include <iostream>
#include <cstdio>
using namespace std;

typedef long long BigNum;

int         T,  M,  N;

BigNum      DP[11][2001];

int main() {
    
    cin >> T;
    
    for( int t = 1; t <= T; ++t ) {
    
        cin >> N >> M;
        
        memset( DP, 0, sizeof( DP ) );
        
        for( int i = 1; i <= M; ++i )
            DP[1][i] = 1;
            
        for( int i = 2; i <= N; ++i )
            for( int j = 1 << (i - 1); j <= M >> ( N - i ); ++j )
                for( int k = 1; k <= j >> 1; ++k )
                    DP[i][j] += DP[i-1][k];
        
        BigNum  ans = 0;
        for( int i = 1; i <= M; ++i )
            ans += DP[N][i];
        
    }
    
}
