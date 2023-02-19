#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,ans = 0;
    cin >> n;
    int dp[n][n] = {{0}}; // dp[i][j] is the maximum sum reaching row i+1 and column j+1
    for(int i = 0;i<n;i++){
        for(int j = 0;j<=i;j++){
            cin >> dp[i][j];
            if(i > 0 ){
                if(j == 0){
                    dp[i][j] = dp[i][j] + dp[i-1][j];
                }else if(j < i){
                    dp[i][j] += max(dp[i-1][j],dp[i-1][j-1]);
                }else{
                    dp[i][j] += dp[i-1][j-1];
                }
            }
            if( i == n-1) ans = max(ans,dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}