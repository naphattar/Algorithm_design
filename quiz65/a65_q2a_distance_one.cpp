#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,k,md = 100000007;
    cin >> n >> k;
    vector<int> dp(n+1,1);
    for(int i = 1;i<=n;i++){
            if(i == 1){
                dp[i] = 2;
            }else{
                dp[i] = dp[i-1];
                if(i > k){
                    dp[i] = (dp[i]%md + dp[i-k]%md)%md;
                }else{
                    dp[i]++;
                }
            }
    }
    cout << dp[n];
    return 0;
}