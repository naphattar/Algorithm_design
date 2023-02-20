#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int coin[n+1];
    for(int i = 1;i<=n;i++) cin >> coin[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,2e2));
    for(int i = 1;i<=n;i++){
        dp[i][0] = 0;
    }
    for(int j = 1;j<=m;j++){
        if(j%coin[1] == 0) dp[1][j] = j/coin[1];
    }
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<=m;j++){
            int amount = j/coin[i];
            for(int k = 0;k<=amount;k++){
                dp[i][j] = min(dp[i][j],min( dp[i-1][j] , dp[i-1][j-coin[i]*k]+k));
            }
        }
    }
    cout << dp[n][m];
    return 0;

}