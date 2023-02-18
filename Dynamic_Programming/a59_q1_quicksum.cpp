#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m,k,elm;
    cin >> n >> m >> k;
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            cin >> elm;
            dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+elm;
        }
    }
    while(k--){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        cout <<  dp[r2+1][c2+1] - dp[r2+1][c1] - dp[r1][c2+1] + dp[r1][c1] << "\n";
    }
    return 0;
}
