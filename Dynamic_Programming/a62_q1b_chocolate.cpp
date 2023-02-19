#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false),cin.tie(nullptr);
    int n,k;
    cin >> n >> k;
    vector<int> eatable(k,0);
    for(int i = 0;i<k;i++) cin >> eatable[i];
    vector<int> dp(n+1,0);
    sort(eatable.begin(),eatable.end());
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<k;j++){
            if(i >= eatable[j]){
                dp[i] = (dp[i]+ dp[i-eatable[j]]%1000003)%1000003;
            }
        }
    }
    cout << dp[n];
    return 0;
}