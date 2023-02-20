#include<iostream>
#include<vector>
int ans = INT32_MAX;
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> s(n+1,0); // s_{i} and s_{i+1} is the row and column of Matrix_{i}
    for(int i = 0;i<=n;i++){
        cin >> s[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,2e9)); // dp[i][j] is MCM  of M_{j} to M_{j+i-1} ans is dp[n][0];
    for(int i = 1;i<=n;i++){
        for(int j = 0;j+i-1<n;j++){
            if(i == 1){
                dp[i][j] = 0;
            }else if(i == 2){
                // multiply M_{j} and M_{j+1}
                dp[i][j] = s[j]*s[j+1]*s[j+2];
            }else{
                for(int k = 1;k<i;k++){
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j+k]+ s[j]*s[j+k]*s[j+i]);
                }
            }
        }
    }
    cout << dp[n][0];
    return 0;
}