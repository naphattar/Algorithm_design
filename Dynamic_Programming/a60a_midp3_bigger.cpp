#include<iostream>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,maxans = 0;
    cin >> n;
    int dp[n+1] = {0};
    int b[n+1] = {0};
    for(int i = 1;i<=n;i++){
        cin >> b[i];
    }
    for(int i = 1;i<=min(3,n);i++){
        dp[i] = b[i];
        maxans = max(maxans,b[i]);
    }
    for(int i = 4;i<=n;i++){
        for(int j = 1;j<i-2;j++){
            dp[i] = max(dp[i],dp[j]);
        }
        dp[i] += b[i];
        maxans = max(maxans,dp[i]);
    }
    cout << maxans;
    return 0;
}