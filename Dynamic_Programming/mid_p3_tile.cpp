#include<iostream>
#include<vector>
using namespace std;

int getdis(int a ,int b){
    return ((a-b)*(a-b));
}
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,m;
    cin >> n >> m;
    int a[n+1];
    vector<vector<int>> dp(n+1,vector<int>(m+1,2e9));
    for(int i = 1;i<=n;i++) cin >> a[i];
    dp[0][0] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
                for(int k = 1;k*k<=j;k++){
                    dp[i][j] = min(dp[i][j],getdis(k,a[i])+dp[i-1][j-k*k]);
                }
        }
    }
    if (dp[n][m] == 2e9){
        cout << -1;
    }else{
        cout << dp[n][m];
    }
    return 0;
}