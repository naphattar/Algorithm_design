#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> price(n+1,0);
    vector<int> dp(n+1,2e9);
    for(int i = 1;i<=n;i++){
        cin >> price[i];
    }
    for(int i = 1;i<=min(n,k+1);i++){
        // for i = 1 to i = k+1 it's cover 1
        dp[i] = price[i];
    }
    for(int i = min(n,k+2);i<=n;i++){
        for(int j = max(1,i-2*k-1);j<i;j++){
            dp[i] = min(dp[i],price[i]+dp[j]);
        }
    }
    int minans = 2e9;
    for(int i = max(1,n-k);i<=n;i++){
        minans = min(minans,dp[i]);
    }
    cout << minans;
    return 0;
}