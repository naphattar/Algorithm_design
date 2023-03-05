#include<bits/stdc++.h>
using namespace std;
int n,m;
int start[2][2];

int solve(long long n,long long r,long long c){
    if(n == 2){
        return start[r][c];
    }
    if( r < n/2){
        if(c < n/2){
            return solve(n/2,r,c);
        }else{
            return solve(n/2,c-(n/2),r);
        }
    }else{
        if(c < n/2){
            return -1*solve(n/2,r-(n/2),c);
        }else{
            return -1*solve(n/2,c-(n/2),r-(n/2));
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    cin >> start[0][0] >> start[0][1]>> start[1][0]>> start[1][1];
    while(m--){
        long long r,c,N = (1LL << n);
        cin >> r >> c;
        cout << solve(N,r-1,c-1) << "\n";
    }
    return 0;
}
