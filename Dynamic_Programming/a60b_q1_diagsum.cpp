#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    int dp[n][n] = {{0}};
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> dp[i][j];
        }
    }
    int maxans = dp[0][0];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            maxans = max(maxans,dp[i][j]);
            for(int k = 1; (i+k < n ) && (j+k<n);k++){
                dp[i][j] += dp[i+k][j+k];
                maxans = max(dp[i][j],maxans);
            }
        }
    }
    cout << maxans;
    return 0;
}