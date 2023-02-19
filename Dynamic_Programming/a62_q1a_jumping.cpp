#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n,0),arr(n,0);
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    dp[0] = arr[0];
    dp[1] = arr[0]+arr[1];
    dp[2] = max(dp[1],dp[0])+arr[2];
    for(int i = 3;i<n;i++){
        dp[i] = max(dp[i-1],max(dp[i-2],dp[i-3]))+arr[i];
    }
    cout << dp[n-1];
    return 0;
}