#include<iostream>
#include<vector>
using namespace std;
int n,k;
int main(){
    cin >> n >> k;
    vector<vector<long long>> dp(n+1,vector<long long>(k+1,1));
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=k;j++){
            if(i== j || j == 0){
                dp[i][j] = 1;
            }else if( 1 <= j && j <= i-1){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    cout << dp[n][k];
    return 0;
}