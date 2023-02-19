#include<iostream>
using namespace std;
int main(){
    int n,k;
    cin >> n >> k;
    int dp[n+1][k+1] = {{0}};
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            if(j > i) break;
            if(j == 1) dp[i][j] = 1;
            else dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1])%1997;
        }
    }
    cout << dp[n][k];
    return 0;
}